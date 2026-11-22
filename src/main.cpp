#include <Arduino.h>

// Name: Hasnait Ansari
// Student number: 26006375

#define LED_PIN 22
#define BUTTON_PIN 23

bool ledState = HIGH;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  digitalWrite(LED_PIN, ledState);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    delay(50);

    if (digitalRead(BUTTON_PIN) == HIGH) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);

      while (digitalRead(BUTTON_PIN) == HIGH) {
      }

      delay(50);
    }
  }
}