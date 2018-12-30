#include <SPIFFS.h>
#include <Regexp.h>

#include "Zugangsinfo.h"
#include "Mein_MQTT.h"
#include "MQTT_Adaptor.h"

MQTT_Adaptor __MQTT_Adaptor;


Mein_MQTT::Mein_MQTT() {
  anzahl_nachrichten = 0;
  naechste_nachricht = 0;
  for (int i = 0; i < MAX_THEMEN; i++) {
    strcpy(thema[i], ""); // "" ist kein Thema
    strcpy(thema_regexp[i], ""); // "" ist kein Thema
  }
  _update_vorhanden = false;
  _speichern = false;
  sprintf(_client_ID, "E32__-%lH%lH", (long unsigned int)(0xffff & ESP.getEfuseMac()), (long unsigned int)(0xffff & (ESP.getEfuseMac() >> 32)));
}

void Mein_MQTT::Beginn() {
  __MQTT_Adaptor.Beginn();
}

void Mein_MQTT::Tick() {
  if (!__MQTT_Adaptor.Verbunden()) {
    char tt[MAX_THEMA];
    char nn[MAX_NACHRICHT];
    strcpy(tt, "MQTT FEHLER");
    sprintf(nn, "Fehlerstatus: %d", __MQTT_Adaptor.Status());
    NeuerEintrag(tt, nn, strlen(nn));
    reconnect();
  }
  __MQTT_Adaptor.Tick();
}

int Mein_MQTT::Anzahl_Nachrichten() {
  return anzahl_nachrichten;
}

const char* Mein_MQTT::Zeitstempel(int i) {
  if (anzahl_nachrichten == 0)
    return "";
  int ii = constrain(i, 0, anzahl_nachrichten);
  ii += naechste_nachricht;
  ii %= anzahl_nachrichten;
  sprintf(z_puffer, "%2d:%02d:%02d", hour(nachricht_zeit[ii]), minute(nachricht_zeit[ii]), second(nachricht_zeit[ii]));
  return z_puffer;
}

int Mein_MQTT::Filter(int i) {
  if (anzahl_nachrichten == 0)
    return -1;
  int ii = constrain(i, 0, anzahl_nachrichten);
  ii += naechste_nachricht;
  ii %= anzahl_nachrichten;
  return nachricht_filter_no[ii];

}

const char* Mein_MQTT::Thema(int i) {
  if (anzahl_nachrichten == 0)
    return "";
  int ii = constrain(i, 0, anzahl_nachrichten);
  ii += naechste_nachricht;
  ii %= anzahl_nachrichten;
  return nachricht_topic[ii];
}

const char* Mein_MQTT::Nachricht(int i) {
  if (anzahl_nachrichten == 0)
    return "";
  int ii = constrain(i, 0, anzahl_nachrichten);
  ii += naechste_nachricht;
  ii %= anzahl_nachrichten;
  return nachricht_inhalt[ii];
}

const char* Mein_MQTT::Aktuelles_Thema(int i) {
  if (i != constrain(i, 0, MAX_THEMEN))
    return "";
  return thema[i];
}

bool Mein_MQTT::Registriere_Thema(int i, const char* t) {
  if (i != constrain(i, 0, MAX_THEMEN - 1)) {
    D_PRINTF("Topic-Wechsel fehler [%d], <%s>\n", i, t);
    return false;
  }
  D_PRINTF("Topic-Wechsel Thema[%d] alt:<%s> auf neu:<%s>", i, thema[i], t);
  if (strlen(thema[i]) > 0) {
    __MQTT_Adaptor.Unsubscribe(thema[i]);
  }
  strncpy(thema[i], t, MAX_THEMA);
  strncpy(thema_regexp[i], t, MAX_THEMA);
  MatchState ms (thema_regexp[i]  );
  ms.GlobalReplace("\+", "[^/]*");
  ms.GlobalReplace("#.*", ".*");
  D_PRINTF(" Regexp:<%s>", thema_regexp[i]);

  if (strlen(t) > 0) {
    if (__MQTT_Adaptor.Subscribe(t)) {
      D_PRINTF(" erfolgreich\n");
    } else {
      D_PRINTF(" fehler\n");
    }
  } else {
    D_PRINTF(" leer\n");
  }
}

void Mein_MQTT::NeuerEintrag(const char*t, const char *n, int l) {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  D_PRINTF("Neue Nachricht [%s] [%s]\n", t, n);
  _update_vorhanden = true;
  nachricht_zeit[naechste_nachricht] = now();
  nachricht_filter_no[naechste_nachricht] = 255;
  MatchState ms((char*)t);
  for (int i = 0; i < MAX_THEMEN; i++) {
    if (strlen(thema_regexp[i]) > 0) {
      if (ms.Match(thema_regexp[i]) > 0) {
        D_PRINTF("Match Topic: <%s>=<%s> (%d)\n", t, thema_regexp[i], i);
        nachricht_filter_no[naechste_nachricht] = i;
        break;
      }
    }
  }
  strncpy(nachricht_topic[naechste_nachricht], t, MAX_THEMA);
  strncpy(nachricht_inhalt[naechste_nachricht], n, l);
  for (int i = l; i < MAX_NACHRICHT; i++)
    nachricht_inhalt[naechste_nachricht][i] = '\0';
  naechste_nachricht++;
  if (naechste_nachricht >= MAX_NACHRICHTEN)
    naechste_nachricht = 0;
  if (anzahl_nachrichten < naechste_nachricht)
    anzahl_nachrichten = naechste_nachricht;

  if (_speicher_count < MAX_NACHRICHTEN)
    _speicher_count++;
  if (_speichern && (_speicher_count == MAX_NACHRICHTEN)) {
    Sichern();
  }
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}

void Mein_MQTT::reconnect() {
  while (!__MQTT_Adaptor.Verbunden()) {
    D_PRINTF("Verbinde mit MQTT server als <%s> ", _client_ID);
    if (__MQTT_Adaptor.Verbinde(_client_ID, device_user, device_pw)) {
      D_PRINTLN("verbunden");
      for (int i = 0; i < MAX_THEMEN; i++) {
        if (strlen(thema[i]) > 0) {
          D_PRINTF("subscribing topic <%s> ", thema[i]);
          if (__MQTT_Adaptor.Subscribe(thema[i])) {
            D_PRINTLN("erfolgreich");
          } else {
            D_PRINTLN("nicht erfolgreich");
          }
        }
      }
    } else {
      D_PRINTF("nicht verbunden, rc=%d, in 5 Sekunden neuer Versuch\n", __MQTT_Adaptor.Status());
      delay(5000);
    }
  }
}

bool Mein_MQTT::Update_Vorhanden() {
  if (_update_vorhanden) {
    _update_vorhanden = false;
    return true;
  } else
    return false;
}

bool Mein_MQTT::Speichern() {
  return _speichern;
}

void Mein_MQTT::Speichern(bool ja) {
  _speichern = ja;
}

void Mein_MQTT::Sichern() {
  if ((SPIFFS.totalBytes() - SPIFFS.usedBytes()) < 10000) {
    D_PRINTF("SPIFFS fs voll, max bytes: %d, used bytes: %d, free; %d\n",
             SPIFFS.totalBytes(), SPIFFS.usedBytes(), (SPIFFS.totalBytes() - SPIFFS.usedBytes()));
    return;
  }
  File logfile = SPIFFS.open("/log.txt", "a");
  D_PRINTF("SPIFFS /log.txt geöffnet\n");
  //  for(int i=_speicher_count-1;i>=0;i--) {
  for (int i = 0; i < _speicher_count; i++) {
    logfile.printf("%s,%d,%s,%s\n", Zeitstempel(i), Filter(i), Thema(i), Nachricht(i));
  }
  logfile.close();
  _speicher_count = 0;
}

