#include <Arduino.h>
#include "Wire.h"
#include "U8g2lib.h"

void setup() {
    Serial.begin(115200);
    pinMode(14, OUTPUT);
}

void loop() {
    Serial.print("FUCK\n");
    delay(1000);
    digitalWrite(14, HIGH);
    delay(1000);
    digitalWrite(14, LOW);
}