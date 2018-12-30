#ifndef _INCLUDE_MQTT
#define _INCLUDE_MQTT

#define MAX_NACHRICHTEN	40
#define MAX_NACHRICHT   40
#define MAX_THEMA       40
#define MAX_THEMEN      5


class Mein_MQTT {
  public:
    Mein_MQTT();

    void Beginn();

    void Tick();

    int Anzahl_Nachrichten();
    const char* Zeitstempel(int i);
    int Filter(int i);
    const char* Thema(int i);
    const char* Nachricht(int i);

    int Naechste_Nachricht();
    void NeuerEintrag(const char*t, const char*n, int l);

    const char* Aktuelles_Thema(int i);
    bool Registriere_Thema(int i, const char* thema);

    bool Update_Vorhanden();

    bool Speichern();
    void Speichern(bool ja);

  private:

    void Sichern();
    void reconnect();
    int anzahl_nachrichten;
    int naechste_nachricht;
    char thema[MAX_THEMEN][MAX_THEMA]; // auf welches topic ist/wird registriert
    char thema_regexp[MAX_THEMEN][MAX_THEMA]; // zum finden als Regular Expression kodiert

    time_t nachricht_zeit[MAX_NACHRICHTEN]; // Ring-Buffer Zeitstempel
    uint8_t nachricht_filter_no[MAX_NACHRICHTEN];
    char nachricht_topic[MAX_NACHRICHTEN][MAX_THEMA]; // Ring-Buffer für topics
    char nachricht_inhalt[MAX_NACHRICHTEN][MAX_NACHRICHT]; // Ring-Buffer für Nachrichten
    char z_puffer[30];

    bool _update_vorhanden;
    bool _speichern;

    int _speicher_count;
};

#endif // _INCLUDE_MQTT
