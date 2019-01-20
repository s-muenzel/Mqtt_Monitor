#ifndef _INCLUDE_TFT
#define _INCLUDE_TFT

class Mein_TFT {
  public:
    Mein_TFT();
    void Beginn();
    void Zeige(uint8_t Zeile, uint8_t Kanal, const char*Text);
  private:
};

#endif // _INCLUDE_TFT
