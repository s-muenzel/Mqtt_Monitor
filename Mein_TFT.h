#ifndef _INCLUDE_TFT
#define _INCLUDE_TFT

#define MAX_ZEILEN  6
#define MAX_TEXT 20

class Mein_TFT {
  public:
    Mein_TFT();
    void Beginn();
    void Zeige(uint8_t Zeile, uint8_t Farbe, const char*Text);
  private:
    char Text[MAX_ZEILEN][MAX_TEXT];
};

#endif // _INCLUDE_TFT
