/*
unsigned int B_LED_PIN = 0; // 1 and 2
unsigned int G_LED_PIN = 1; // 1 and 2
unsigned int R_LED_PIN = 2; // 1 and 2
unsigned int BUTTON_PIN = 3;
*/


#define BUTTON_PIN 3
#define G_LED_PIN 1


unsigned long last_send_time = 0;
unsigned int led_status = 0;


void setup() {
  Serial.begin(115200);
  pinMode(G_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(G_LED_PIN, HIGH);
}

void loop() {
  if ((digitalRead(BUTTON_PIN) == LOW) && (micros() >= last_send_time + 500000)) {
    led_status = (led_status + 1) % 2;
    Serial.println(led_status);
    last_send_time = micros();
    digitalWrite(G_LED_PIN, led_status);
  }
}

