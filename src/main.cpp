#include <Arduino.h>
#include "Wire.h"
#include "SPI.h"
#include "U8g2lib.h"


U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R2, 32, 33, 27, 26,25);

void setup(void) {
//    Serial.begin(115200);

    pinMode(14, OUTPUT);

    u8g2.begin();
    u8g2.enableUTF8Print();
}


float vol = 12.34;
void loop(void) {


//    Serial.print("FUCK\n");

/* Page buffer mode
 * 低速模式下
 */
//    u8g2.firstPage();
//    do {
//        u8g2.setFont(u8g2_font_ncenB14_tr);
//        u8g2.drawStr(0,20,"Hello World!");
//        u8g2.drawStr(0,40,"CHM");
//    } while ( u8g2.nextPage() );


    vol += 0.1;

/*
 * Full screen buffer mode
 * 以下需要在full_buffer下使用，否则无法使用
 */
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_pcsenior_8f);
    u8g2.setCursor(0, 10);
    u8g2.print("hello chm");
    u8g2.setCursor(0, 20);
    u8g2.print(vol);

    u8g2.sendBuffer();

//    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
//    u8g2.setFontDirection(0);
//    u8g2.clearBuffer();
//    u8g2.setCursor(0, 15);
//    u8g2.print("Hello World!");
//    u8g2.setCursor(0, 40);
//    u8g2.print("你好世界");        // Chinese "Hello World"
//    u8g2.sendBuffer();



    digitalWrite(14,HIGH);
    delay(50);
    digitalWrite(14,LOW);
    delay(30);

}