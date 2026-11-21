#include <Arduino.h>

#define LED_PIN 23
#define BUTTON_PIN 22

bool ledState = HIGH;

int buttonState = LOW;
int lastButtonReading = LOW;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);

    digitalWrite(LED_PIN, HIGH);
}

void loop() {

    int reading = digitalRead(BUTTON_PIN);

    if (reading != lastButtonReading) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {

        if (reading != buttonState) {
            buttonState = reading;

            if (buttonState == HIGH) {
                ledState = !ledState;
                digitalWrite(LED_PIN, ledState);
            }
        }
    }

    lastButtonReading = reading;
}