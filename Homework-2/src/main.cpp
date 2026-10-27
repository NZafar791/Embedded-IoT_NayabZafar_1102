#include <Arduino.h>
#include <WiFi.h>

const int LED1_PIN = 18;
const int LED2_PIN = 19;

const int LED1_FREQ = 1000;
const int LED2_FREQ = 5000;

const int PWM_RESOLUTION = 8;
const int MAX_DUTY = 255;

const int LED1_CHANNEL = 0;
const int LED2_CHANNEL = 1;

int duty1 = 0;
int duty2 = 0;

void setup()
{
  ledcSetup(LED1_CHANNEL, LED1_FREQ, PWM_RESOLUTION);
  ledcAttachPin(LED1_PIN, LED1_CHANNEL);

  ledcSetup(LED2_CHANNEL, LED2_FREQ, PWM_RESOLUTION);
  ledcAttachPin(LED2_PIN, LED2_CHANNEL);
}

void loop()
{
  for (int duty = 0; duty <= MAX_DUTY; duty++) {
    duty1 = duty;
    duty2 = MAX_DUTY - duty;

    ledcWrite(LED1_CHANNEL, duty1);
    ledcWrite(LED2_CHANNEL, duty2);

    delay(10);
  }

  for (int duty = MAX_DUTY; duty >= 0; duty--) {
    duty1 = duty;
    duty2 = MAX_DUTY - duty;

    ledcWrite(LED1_CHANNEL, duty1);
    ledcWrite(LED2_CHANNEL, duty2);

    delay(10);
  }
}

