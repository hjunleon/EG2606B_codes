#define analogPin 10 // MISO, not ADC pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(analogPin, INPUT);   
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value
  delay(100);
}
