#include <Arduino.h>

const int BUTTON_PIN = 4; // Define the pin for the button
const int LED_PIN = 2;   // Define the pin for the LED

RTC_DATA_ATTR int bootCount = 0;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  pinMode(LED_PIN, OUTPUT);          // Set LED pin as output

  ++bootCount;
  Serial.println("Boot count: " + String(bootCount));

  // // Check if the button is pressed at boot
  // if (digitalRead(BUTTON_PIN) == LOW) {
  //   Serial.println("Button is pressed!");
  //   digitalWrite(LED_PIN, HIGH); // Turn on the LED
  //   delay(1000);
  //   digitalWrite(LED_PIN, LOW); // Turn off the LED
  //   delay(1000);
  // }
  // esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, LOW);
  // esp_deep_sleep_start();
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button is pressed!");
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
    delay(1000);
    digitalWrite(LED_PIN, LOW); // Turn off the LED
    delay(1000);
  }

  // Deep sleep for 10 seconds
  esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, LOW);
  esp_deep_sleep_start();
}
