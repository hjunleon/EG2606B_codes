
#define LED_PIN SCK//MISO//MOSI //SS

bool isOn = false;

void setup() {
  Serial.begin(115200);
  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (isOn){
    digitalWrite(LED_PIN, LOW); // turn the LED off
    Serial.println("Off");
  } else {
    digitalWrite(LED_PIN, HIGH); // turn the LED on
    Serial.println("On");
  }
  isOn = !isOn;
  delay(1000);
}