#include "Mein_TFT.h"

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

const uint16_t Farben[] = {
  TFT_WHITE,
  TFT_BLUE,
  TFT_GREEN,
  TFT_CYAN,
  TFT_RED,
  TFT_YELLOW,
  TFT_MAGENTA,
  TFT_NAVY,
  TFT_ORANGE
};
///////////

Mein_TFT::Mein_TFT() {
}

void Mein_TFT::Beginn() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
}

void Mein_TFT::Zeige(uint8_t Zeile, uint8_t Farbe, const char*Text) {
  D_PRINTF("TFT Zeile %d %d %s\n", Zeile, Farbe, Text);
  if (Zeile >= 6)
    return;
  uint8_t farbe = Farbe%(sizeof(Farben) / sizeof(uint16_t));
  tft.fillRect(0, Zeile*21, tft.width()- 1 , 20, TFT_BLACK);
  tft.setCursor(0, Zeile * 21);
  D_PRINTF("setCursor 0, %d\n", Zeile * 21);
  tft.setTextColor(Farben[farbe], TFT_BLACK);
  tft.setTextFont(2);
  D_PRINTF("setTextColor %d %x\n", Farbe, Farben[farbe]);
  tft.setTextWrap(false);
  tft.print(Text);
}
