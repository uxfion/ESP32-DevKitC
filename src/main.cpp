#include <Arduino.h>
#include "Wire.h"
#include "U8g2lib.h"

int count1 = 0;
int count2 = 0;
float vol = 12.34;

U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R2, 32, 33, 27, 26,25);

void taskSerial(void * parameters){
    for( ; ; ){
        Serial.print("FUCK\n");
        Serial.print("Serial Debug Interface");
        Serial.print(count1++);
        Serial.print("\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void * parameters){
    for( ; ; ){
        vol += 0.1;
        Serial.print("Task 2 Counter: ");
        Serial.print(count2++);
        Serial.print("\n");
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void taskDisplay(void * parameters){
    while(1){
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_pcsenior_8f);
        u8g2.setCursor(0, 10);
        u8g2.print("Vol: ");
        u8g2.print(vol);
        u8g2.sendBuffer();
    }
}

void setup(void) {
    Serial.begin(115200);
//    pinMode(14, OUTPUT);

    u8g2.begin();
    u8g2.enableUTF8Print();

    xTaskCreate(
            taskSerial,
            "Task Serial",
            1000,
            NULL,
            1,
            NULL
    );

    xTaskCreate(
            task2,
            "Task 2",
            1000,
            NULL,
            1,
            NULL
    );

    xTaskCreate(
            taskDisplay,
            "Task Display",
            5000,
            NULL,
            1,
            NULL
    );

}

void loop(void) {
//
////    Serial.print("FUCK\n");
//    vol += 0.1;
//
////    digitalWrite(14,HIGH);
////    delay(50);
////    digitalWrite(14,LOW);
////    delay(30);
//

    while(1){

    }
}
