#include <Arduino.h>

// Name: Hasnait Ansari
// Student number: 26006375

// GPIO 22 controls the external LED.
#define LED_PIN 22

// GPIO 23 reads the push button.
#define BUTTON_PIN 23

// Store the LED state. HIGH means the LED starts turned on.
bool ledState = HIGH;

void setup() {
  // Configure GPIO 22 as an output because it drives the LED.
  pinMode(LED_PIN, OUTPUT);

  // Configure GPIO 23 as an input with an internal pull-down resistor.
  // It reads LOW when the button is released and HIGH when pressed.
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  // Apply the initial LED state: HIGH, so the LED is on at startup.
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // Check whether the button has connected GPIO 23 to 3.3 V.
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Wait 50 ms to ignore the mechanical bounce of the switch.
    delay(50);

    // Check again after the delay to confirm it was a real press.
    if (digitalRead(BUTTON_PIN) == HIGH) {
      // Reverse the saved state: ON becomes OFF, and OFF becomes ON.
      ledState = !ledState;

      // Write the new saved state to the LED output pin.
      digitalWrite(LED_PIN, ledState);

      // Do nothing until the button is released.
      // This makes one press toggle the LED only once.
      while (digitalRead(BUTTON_PIN) == HIGH) {
      }

      // Wait 50 ms to ignore bounce when the button is released.
      delay(50);
    }
  }
}
// well done -- thomas