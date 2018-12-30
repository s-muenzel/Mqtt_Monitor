/* */

#include <WiFi.h>
#include <ESPmDNS.h>
#include <Time.h>
#include <TimeLib.h>

#include "Zugangsinfo.h"
#include "WebS.h"
#include "NTP.h"
#include "Mein_MQTT.h"

#define DEBUG_SERIAL
#ifdef DEBUG_SERIAL
#define D_BEGIN(speed)   Serial.begin(speed)
#define D_PRINT(...)     Serial.print(__VA_ARGS__)
#define D_PRINTLN(...)   Serial.println(__VA_ARGS__)
#define D_PRINTF(...)    Serial.printf(__VA_ARGS__)
#else
#define D_BEGIN(speed)
#define D_PRINT(...)
#define D_PRINTLN(...)
#define D_PRINTF(...)
#endif

WiFiClient __Wifi_Client;
WebS __WebS;
Mein_MQTT __MQTT;
NTP_Helfer __NTP;

/////////////////////////////////////////////////
// Normaler WiFi Part

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  D_PRINTLN();
  D_PRINT("Connecting to ");
  D_PRINTLN(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    D_PRINT(".");
  }

  D_PRINTLN("");
  D_PRINTLN("WiFi connected");
  D_PRINTLN("IP address: ");
  D_PRINTLN(WiFi.localIP());

  MDNS.begin("MQTT_Monitor");
}


//////////////////////////////////////////////////////
// Hauptprogramm

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
  setup_wifi();

  // NTP
  __NTP.Beginn();

  // Webserver konfigurieren
  __WebS.Beginn();
  __WebS.Admin_Mode(true);
  D_PRINT(" Webserver laeuft");

  // MQTT initialisieren
  __MQTT.Beginn();
}

void loop() {

  __MQTT.Tick();
  yield();
  __WebS.Tick();
  delay(50);
}

