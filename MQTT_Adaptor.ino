#define USE_ARDUINO_MQTT
//#define USE_PUBSUBBLIENT

#include "MQTT_Adaptor.h"

#ifdef USE_PUBSUBCLIENT
#include <PubSubClient.h>
PubSubClient client(__Wifi_Client);
#endif // USE_PUBSUBCLIENT
#ifdef USE_ARDUINO_MQTT
#include <MQTT.h>
#include <MQTTClient.h>
MQTTClient client;
#endif // USE_ARDUINO_MQTT


///////////////////////////////////////////////////
// MQTT Part als Adator Pattern

#ifdef USE_PUBSUBBLIENT
void Nachricht_Erhalten(char* topic, byte* payload, unsigned int length) {
  __MQTT.NeuerEintrag((const char*)topic, (const char*)payload, length);
}
#endif // USE_PUBSUBBLIENT
#ifdef USE_ARDUINO_MQTT
void Nachricht_Erhalten(String &topic, String &payload) {
  __MQTT.NeuerEintrag(topic.c_str(), payload.c_str(), payload.length());
}
#endif // USE_ARDUINO_MQTT


MQTT_Adaptor::MQTT_Adaptor() {
}

void MQTT_Adaptor::Beginn() {
#ifdef USE_PUBSUBBLIENT
  client.setServer(mqtt_server, 1883);
  client.setCallback(Nachricht_Erhalten);
#endif // USE_PUBSUBBLIENT
#ifdef USE_ARDUINO_MQTT
  client.begin(mqtt_server, 1883, __Wifi_Client);
  client.onMessage(Nachricht_Erhalten);
  //  client.onMessageAdvanced(Nachricht_Erhalten);
#endif // USE_ARDUINO_MQTT
}

bool MQTT_Adaptor::Verbunden() {
  return client.connected();
}

bool MQTT_Adaptor::Verbinde(const char*ClientID, const char* User, const char* PW) {
  return client.connect(ClientID, User, PW);
}

void MQTT_Adaptor::Tick() {
  yield();
  client.loop();
  yield();
}

bool MQTT_Adaptor::Subscribe(const char *Thema) {
  if (client.connected()) {
#ifdef USE_PUBSUBBLIENT
    bool ergebnis = client.subscribe(Thema, 1);
#endif // USE_PUBSUBBLIENT
#ifdef USE_ARDUINO_MQTT
    bool ergebnis = client.subscribe(Thema, 2);
#endif // USE_ARDUINO_MQTT
    yield();
    client.loop();
    yield();
    return ergebnis;
  } else {
    return true;
  }
}

bool MQTT_Adaptor::Unsubscribe(const char *Thema) {
  if (client.connected()) {
    bool ergebnis = client.unsubscribe(Thema);
    yield();
    client.loop();
    yield();
    return ergebnis;
  } else {
    return true;
  }
}

int MQTT_Adaptor::Status() {
#ifdef USE_PUBSUBBLIENT
  return client.state();
#endif // USE_PUBSUBBLIENT
#ifdef USE_ARDUINO_MQTT
  return client.lastError();
#endif // USE_ARDUINO_MQTT
}
