#include <Arduino.h>
#include "Wire.h"
#include "SPI.h"
#include "U8g2lib.h"


//U8G2_SSD1306_128X80_NONAME_F_HW_I2C u8g2(U8G2_R1, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 22, /* data=*/21);

//U8G2_SSD1306_128X32_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 12, /* data=*/ 14, /* cs=*/ 25, /* dc=*/ 26, /* reset=*/ U8X8_PIN_NONE);
//(const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t cs, uint8_t dc, uint8_t reset = U8X8_PIN_NONE)
//34, 35, 33, 25 , 26
//const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t cs, uint8_t reset = U8X8_PIN_NONE
U8G2_SSD1306_128X64_NONAME_1_3W_SW_SPI u8g2(U8G2_R1, 34, 35, 33, 26);
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R1, );
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R1, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 22, /* data=*/21);

void setup() {
//    Serial.begin(115200);
    pinMode(14, OUTPUT);
    u8g2.begin();
    u8g2.enableUTF8Print();
}

void loop() {
//    Serial.print("FUCK\n");
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.setFontDirection(0);
    u8g2.clearBuffer();
    u8g2.setCursor(0, 15);
    u8g2.print("Hello World!");
    u8g2.setCursor(0, 40);
    u8g2.print("你好世界");        // Chinese "Hello World"
    u8g2.sendBuffer();


    digitalWrite(14,HIGH);
    delay(500);
    digitalWrite(14,LOW);
    delay(300);

}