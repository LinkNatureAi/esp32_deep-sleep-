#include <Arduino.h>

// Define the external wakeup pin
const int wakeupPin = 2; // Change this to the desired pin

void setup() {
  Serial.begin(115200);

  // Configure the external wakeup pin as an input
  pinMode(wakeupPin, INPUT);

  // Check if the ESP32 was reset due to external wakeup
  if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT0) {
    Serial.println("Woke up from external pin");
  } else {
    Serial.println("Normal boot");
  }
}

void loop() {
  // Enter deep sleep
  Serial.println("Going to sleep...");
  esp_deep_sleep_start();
}
