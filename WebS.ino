#include "WebS.h"

#include <FS.h>
#include <WebServer.h>
#include <SPIFFS.h>

WebServer server(80);

bool __Admin_Mode_An;
bool __AutoUpdate;


///////// Hilfsfunktionen
//format bytes
String formatBytes(size_t bytes) {
  if (bytes < 1024) {
    return String(bytes) + " B";
  } else if (bytes < (1024 * 1024)) {
    return String(bytes / 1024.0) + " KB";
  } else if (bytes < (1024 * 1024 * 1024)) {
    return String(bytes / 1024.0 / 1024.0) + " MB";
  } else {
    return String(bytes / 1024.0 / 1024.0 / 1024.0) + " GB";
  }
}

//Stunde aus Text
uint8_t parseZeit_Stunde(String s) {
  return constrain( int(s.toInt()), 0, 23);
}

//Minute aus Text
uint8_t parseZeit_Minute(String s) {
  return constrain(int(s.substring(3).toInt()), 0, 59);
}

void handleRoot() {
  D_PRINTLN("handleRoot");
  if (SPIFFS.exists("/top.htm")) {
    File file = SPIFFS.open("/top.htm", "r");
    server.streamFile(file, "text/html");
    file.close();
  } else {
    server.send(404, "text/plain", "file error");
  }
}

void handleNachrichten() {
  D_PRINTLN("handleNachrichten");
  String temp;
  temp = "<html><head><meta charset='UTF-8'><link rel='stylesheet' type='text/css' href='style.css'></head><body>";
  temp += "<table><tr><th>Zeit</th><th>Topic</th><th>Nachricht</th></tr>";
  //  for (int i = 0; i < __MQTT.Anzahl_Nachrichten(); i++) {
  for (int i = __MQTT.Anzahl_Nachrichten() - 1; i >= 0; i--) {
    temp += "<tr class='filter" + String(__MQTT.Filter(i), HEX);
    temp += "'><td class='zeit'>";
    temp += __MQTT.Zeitstempel(i);
    temp += "</td><td class='thema'>";
    temp += __MQTT.Thema(i);
    temp += "</td><td class='wert'>";
    temp += __MQTT.Nachricht(i);
    temp += "</td></tr>";
  }
  temp += "</table></body></html>";
  server.send(200, "text/html", temp);
}

void handleMonitor() {
  D_PRINTLN("handleMonitor");
  String temp;
  temp = "<html><head><meta charset='UTF-8'><link rel='stylesheet' type='text/css' href='style.css'></head><body>";
  temp += "<form action='/Setze_Topic' method='POST'><div class='Tag'>";
  temp += "<div>Auto-Refresh<input type='checkbox' name='auto' ";
  temp += __AutoUpdate ? "checked" : "";
  temp += "></div>";
  temp += "<div>Speichern<input type='checkbox' name='speichern' ";
  temp += __MQTT.Speichern() ? "checked" : "";
  temp += "></div>";
  for (int i = 0; i < MAX_THEMEN; i++) {
    temp += "<span class='filter" + String(i, HEX);
    temp += "'><span>Topic" + String(i, HEX);
    temp += "</span><span class='Rechts'><input type='text' name='thema" + String(i, HEX) ; //
    temp += "' value='";
    temp += __MQTT.Aktuelles_Thema(i);
    temp += "'></span></span>";
  }
  temp += "<input type='submit' name='ok' value='ok'></div></form>";
  temp += "</body></html>";
  server.send(200, "text/html", temp);
}

void handleSetzeTopic() {
  D_PRINTLN("handleSetzeTopic");
  __MQTT.Speichern(false);
  __AutoUpdate = false;
  for (int i = 0; i < server.args(); i++) {
    if (server.argName(i) == "thema0") {
      String neues_thema = server.arg(i);
      D_PRINTF("Neues Topic: %s\n", neues_thema.c_str());
      __MQTT.Registriere_Thema(0, neues_thema.c_str());
    } else if (server.argName(i) == "thema1") {
      String neues_thema = server.arg(i);
      D_PRINTF("Neues Topic: %s\n", neues_thema.c_str());
      __MQTT.Registriere_Thema(1, neues_thema.c_str());
    } else if (server.argName(i) == "thema2") {
      String neues_thema = server.arg(i);
      D_PRINTF("Neues Topic: %s\n", neues_thema.c_str());
      __MQTT.Registriere_Thema(2, neues_thema.c_str());
    } else if (server.argName(i) == "thema3") {
      String neues_thema = server.arg(i);
      D_PRINTF("Neues Topic: %s\n", neues_thema.c_str());
      __MQTT.Registriere_Thema(3, neues_thema.c_str());
    } else if (server.argName(i) == "thema4") {
      String neues_thema = server.arg(i);
      D_PRINTF("Neues Topic: %s\n", neues_thema.c_str());
      __MQTT.Registriere_Thema(4, neues_thema.c_str());
    } else if (server.argName(i) == "auto") {
      __AutoUpdate = true;
      D_PRINTF("Auto-Update an\n");
    } else if (server.argName(i) == "speichern") {
      __MQTT.Speichern(true);
      D_PRINTF("Auto-Update an\n");
    }
  }
  server.sendHeader("Location", "/Monitor");
  server.send(303, "text/html", "Location:/Monitor");
}

void handleCSS() {
  D_PRINTLN("handleCSS");
  if (SPIFFS.exists("/style.css")) {
    File file = SPIFFS.open("/style.css", "r");
    server.streamFile(file, "text/css");
    file.close();
  } else {
    server.send(404, "text/plain", "file error");
  }
}

void handleStatus() {
  char temp[1000];
  time_t t = now(); // Store the current time in time
  snprintf(temp, 1000,
           "{ \"Zeit\" : \"%2d:%02d:%02d\", \"ZeitStatus\" : %d, \"Aktiv\" : %d, \"Admin\" : %d}", hour(t), minute(t), second(t), timeStatus(), __AutoUpdate && __MQTT.Update_Vorhanden(), __Admin_Mode_An);
  server.send(200, "application/json", temp);
}

void handleFavIcon() {
  D_PRINTLN("handleFavIcon");
  if (SPIFFS.exists("/favicon.ico")) {
    File file = SPIFFS.open("/favicon.ico", "r");
    server.streamFile(file, "image/x-icon");
    file.close();
  } else {
    server.send(404, "text/plain", "file error");
  }
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ":" + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

File fsUploadFile;
void handleHochladen() {
  if (server.uri() != "/Hochladen") {
    return;
  }
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    String filename = upload.filename;
    if (filename == "") {
      filename = "dummy.txt";
    }
    if (!filename.startsWith("/")) {
      filename = "/" + filename;
    }
    D_PRINT("handleHochladen Name: "); D_PRINTLN(filename);
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    //D_PRINT("handleHochladen Data: "); D_PRINTLN(upload.currentSize);
    if (fsUploadFile) {
      fsUploadFile.write(upload.buf, upload.currentSize);
    }
  } else if (upload.status == UPLOAD_FILE_END) {
    if (fsUploadFile) {
      fsUploadFile.close();
    }
    D_PRINT("handleHochladen Groesse: "); D_PRINTLN(upload.totalSize);
  }
}

void handleLaden() {
  if ((server.args() == 0) || (server.argName(0) != "datei")) {
    return server.send(500, "text/plain", "BAD ARGS");
  }
  String dateiname = server.arg(0);
  //  String contentType = getContentType(file);
  File datei = SPIFFS.open(dateiname, "r");
  if (datei) {
    //    server.streamFile(file, contentType);
    server.streamFile(datei, "text/plain");
    datei.close();
    return;
  }
  server.send(404, "text/plain", "FileNotFound");
}

void handleLoeschen() {
  if ((server.args() == 0) || (server.argName(0) != "datei")) {
    return server.send(500, "text/plain", "BAD ARGS");
  }
  String path = server.arg(0);
  D_PRINTLN("handleLoeschen: " + path);
  if (path == "/") {
    return server.send(500, "text/plain", "BAD PATH");
  }
  if (!SPIFFS.exists(path)) {
    return server.send(404, "text/plain", "FileNotFound");
  }
  SPIFFS.remove(path);
  server.sendHeader("Location", "/Dateien");
  server.send(303, "text/html", "Location:/Dateien");
  path = String();
}


void handleDateien() {
  D_PRINTLN("Seite handleDateien");

  String output;
  output = "<html><head><meta charset='UTF-8'><link rel='stylesheet' type='text/css' href='style.css'></head><body>";
  if (__Admin_Mode_An) {
    output += String("<form action='/Hochladen' method='post' enctype='multipart/form-data'><span><div class='Tag'><input type='file' name='name'></div></span><span><input class='button' type='submit' value='Upload'></span></form>");
  }
  File dir = SPIFFS.open("/");
  File entry = dir.openNextFile();
  while (entry) {
    output += String("<form action='/Loeschen' method='post'>");
    output += String("<span><div class='Tag'><span><a href='/Laden?datei=") + entry.name();
    output += String("'>") + entry.name() + String("</a></span><span class='Rechts'>") + formatBytes(entry.size());
    output += String("</span><input type='text' style='display:none' name='datei' value='") + entry.name();
    output += String("'></div></span><span><input class='button' type='submit' value='l&ouml;schen'></span></form>");
    D_PRINTF("File '%s', Size %d\n", entry.name(), entry.size());
    entry.close();
    entry = dir.openNextFile();
  }
  dir.close();
  output += String("<div>Filesystem: ") +  formatBytes(SPIFFS.totalBytes());
  output += String(" belegt: ") +  formatBytes(SPIFFS.usedBytes()) + String("</div>");
  output += "</body></html>";
  server.send(200, "text/html", output);
}
///////////

WebS::WebS() {
  __Admin_Mode_An = false;
  __AutoUpdate = true;
}

void WebS::Beginn() {
  if (!SPIFFS.begin()) {
    D_PRINTLN("Failed to mount file system");
  }

  server.on("/",              handleRoot);          // Anzeige Weckzeiten und Möglichkeit Weckzeiten zu setzen. Auch Link zu Konfig und Dateien
  server.on("/Status",        handleStatus);        // Dynamische Daten
  server.on("/Monitor",       handleMonitor);
  server.on("/Nachrichten",   handleNachrichten);
  server.on("/Setze_Topic",   handleSetzeTopic);
  server.on("/Dateien",       handleDateien);       // Datei-Operationen (upload, delete)
  server.on("/Loeschen",      handleLoeschen);      // Delete (spezifische Datei)
  server.on("/Laden",         handleLaden);         // Herunterladen (spezifische Datei)
  server.on("/Hochladen", HTTP_POST, []() { //first callback is called after the request has ended with all parsed arguments
    server.sendHeader("Location", "/Dateien");
    server.send(303, "text/html", "Location:/Dateien");
  },  handleHochladen);        //second callback handles file uploads at that location
  server.on("/favicon.ico",   handleFavIcon);       // liefert das Favicon.ico
  server.on("/style.css",     handleCSS);           // liefert das Stylesheet
  server.onNotFound(          handleNotFound);      // Fallback

  server.begin();
}

void WebS::Admin_Mode(bool ja) {
  __Admin_Mode_An = ja;
}

void WebS::Tick() {
  server.handleClient();
}
