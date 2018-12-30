
#include <ArduinoOTA.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include <SPIFFS.h>
#include <Regexp.h>

#include "Zugangsinfo.h"
#include "Mein_MQTT.h"

WiFiClient espClient;
PubSubClient client(espClient);
char msg[MAX_NACHRICHT];



///////////////////////////////////////////////////
// MQTT Part

void callback(char* topic, byte* payload, unsigned int length) {
  D_PRINTF("Message arrived [%s] ", topic);
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  unsigned int laenge = (length > MAX_NACHRICHT) ? MAX_NACHRICHT : length;

  for (int i = 0; i < laenge; i++) {
    D_PRINT((char)payload[i]);
  }
  D_PRINTLN();
  __MQTT.NeuerEintrag((const char*)topic, (const char*)payload, laenge);

  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}


Mein_MQTT::Mein_MQTT() {
  anzahl_nachrichten = 0;
  naechste_nachricht = 0;
  for (int i = 0; i < MAX_THEMEN; i++) {
    strcpy(thema[i], ""); // "" ist kein Thema
    strcpy(thema_regexp[i], ""); // "" ist kein Thema
  }
  _update_vorhanden = false;
  _speichern = false;
}

void Mein_MQTT::Beginn() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void Mein_MQTT::Tick() {
  if (!client.connected()) {
    char tt[MAX_THEMA];
    char nn[MAX_NACHRICHT];
    strcpy(tt, "MQTT FEHLER");
    sprintf(nn, "Fehlerstatus: %d", client.state());
    NeuerEintrag(tt, nn, strlen(nn));
    reconnect();
  }
  client.loop();
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
  if (client.connected() && (strlen(thema[i]) > 0)) {
    client.unsubscribe(thema[i]);
    delay(50); client.loop(); delay(50); // Callback leeren
  }
  strncpy(thema[i], t, MAX_THEMA);
  strncpy(thema_regexp[i], t, MAX_THEMA);
  MatchState ms (thema_regexp[i]  );
  ms.GlobalReplace("\+", "[^/]*");
  ms.GlobalReplace("#.*", ".*");
  D_PRINTF(" Regexp:<%s>", thema_regexp[i]);

  if (client.connected()) {
    if (strlen(t) > 0) {
      if (client.subscribe(t)) {
        D_PRINTF(" erfolgreich\n");
        delay(50); client.loop(); delay(50); // Callback leeren
      } else {
        D_PRINTF(" fehler\n");
        client.loop(); // Callback leeren
      }
    } else {
      D_PRINTF(" leer\n");
    }
  } else {
    D_PRINTF(" vorbereitet\n");
  }
}

void Mein_MQTT::NeuerEintrag(const char*t, const char *n, int l) {
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
}

void Mein_MQTT::reconnect() {
  while (!client.connected()) {
    String clientId = "E32__-";
    clientId += String((long unsigned int)(0xffff & ESP.getEfuseMac()), HEX);
    clientId += String((long unsigned int)(0xffff & (ESP.getEfuseMac() >> 32)), HEX);
    D_PRINTF("Verbinde mit MQTT server als <%s> ", clientId.c_str());
    // Attempt to connect
    if (client.connect(clientId.c_str(), "sensor", "AlteRinne14")) {
      D_PRINTLN("verbunden");
      for (int i = 0; i < MAX_THEMEN; i++) {
        if (strlen(thema[i]) > 0) {
          D_PRINTF("subscribing topic <%s> ", thema[i]);
          if (client.subscribe(thema[i])) {
            D_PRINTLN("erfolgreich");
            delay(50); client.loop(); delay(50); // Callback leeren
          } else {
            D_PRINTLN("nicht erfolgreich");
            client.loop(); // Callback leeren
          }
        }
      }
    } else {
      D_PRINT("failed, rc=");
      D_PRINT(client.state());
      D_PRINTLN(" try again in 5 seconds");
      // Wait 5 seconds before retrying
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
  if((SPIFFS.totalBytes() - SPIFFS.usedBytes()) < 10000) {
    D_PRINTF("SPIFFS fs voll, max bytes: %d, used bytes: %d, free; %d\n", 
      SPIFFS.totalBytes(), SPIFFS.usedBytes(),(SPIFFS.totalBytes() - SPIFFS.usedBytes()));
    return;
  }
  File logfile = SPIFFS.open("/log.txt","a");
  D_PRINTF("SPIFFS /log.txt geöffnet\n");
//  for(int i=_speicher_count-1;i>=0;i--) {
  for(int i=0; i<_speicher_count;i++) {
    logfile.printf("%s,%d,%s,%s\n", Zeitstempel(i), Filter(i), Thema(i), Nachricht(i));
  }
  logfile.close();
  _speicher_count = 0;
}

