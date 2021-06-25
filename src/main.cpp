#include <Arduino.h>
#include "Wire.h"
#include "U8g2lib.h"

U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R2, 32, 33, 27, 26,25);

void setup(void) {
//    Serial.begin(115200);

//    pinMode(14, OUTPUT);

    u8g2.begin();
    u8g2.enableUTF8Print();
}

float vol = 12.34;
void loop(void) {

//    Serial.print("FUCK\n");
    vol += 0.1;

//    digitalWrite(14,HIGH);
//    delay(50);
//    digitalWrite(14,LOW);
//    delay(30);

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_pcsenior_8f);
    u8g2.setCursor(0, 10);
    u8g2.print("Vol: ");
    u8g2.print(vol);
    u8g2.sendBuffer();
}
