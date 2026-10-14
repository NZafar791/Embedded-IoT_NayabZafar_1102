
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define OLED_ADDRESS 0x3C
#define BUTTON_PIN 18

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

int pressCount = 0;

bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void updateDisplay() {
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 Button Status");

  display.setCursor(0, 20);
  display.print("Status: ");

  if (stableButtonState == LOW) {
    display.println("PRESSED");
  } else {
    display.println("RELEASED");
  }

  display.setCursor(0, 40);
  display.print("Press Count: ");
  display.println(pressCount);

  display.display();
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
      )) {
    Serial.println("OLED initialization failed!");
    while (true) {
      // Stop if OLED initialization fails
    }
  }

  display.clearDisplay();
  updateDisplay();

  Serial.println("OLED initialized successfully.");
  Serial.println("Press the button to increase the count.");
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  // Detect a change in the raw button reading
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Accept the reading only after it remains stable
  if (millis() - lastDebounceTime >= debounceDelay) {

    if (reading != stableButtonState) {
      stableButtonState = reading;

      // Count only a valid press, not the release
      if (stableButtonState == LOW) {
        pressCount++;

        Serial.print("Accepted press count: ");
        Serial.println(pressCount);
      }

      updateDisplay();
    }
  }

  lastButtonReading = reading;
}
