#include <Arduino.h>
#include "Wire.h"
#include "SPI.h"
#include "U8g2lib.h"


U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 32, 33, 27, 26,25);

void setup() {
//    Serial.begin(115200);
    pinMode(14, OUTPUT);
    u8g2.begin();
//    u8g2.enableUTF8Print();
}

void loop() {
//    Serial.print("FUCK\n");

    u8g2.firstPage();
    do {
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.drawStr(0,24,"Hello World!");
    } while ( u8g2.nextPage() );


    digitalWrite(14,HIGH);
    delay(500);
    digitalWrite(14,LOW);
    delay(300);

}