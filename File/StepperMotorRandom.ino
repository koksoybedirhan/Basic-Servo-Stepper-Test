#include <Arduino.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define rastgeleMax 3
#define rastgeleMin 1

String value = ",";

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    srand(time(0));
    long a;

    for (int i = 1; i > 0; ++i) {
        a = rand() % rastgeleMax + rastgeleMin;

        Serial.print(a + value);
        pinMode(13, HIGH);
        delay(1000);
        pinMode(13, LOW);
        delay(1000);
    }
}
