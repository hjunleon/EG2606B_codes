
#include <SPI.h>
#include <TLA2518.h>

#define REF_V 5.0 //3.3

SPIClass * vspi = NULL; //HSPI
// SPIClass fspi(VSPI); //HSPI

TLA2518Class* ioexpander;
// https://arduino.stackexchange.com/questions/79728/when-is-spi-begintransaction-required
// https://www.arduino.cc/reference/en/language/functions/communication/spi/
void setup() {
  Serial.begin(115200);
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);
  Serial.print("HSPI: ");
  Serial.println(HSPI);  
  Serial.print("FSPI: ");
  Serial.println(FSPI);
  // Serial.print("CS_1: ");
  // Serial.println(CS_1);  
  // Serial.print("CS_2: ");
  // Serial.println(CS_2);  
  // SPI.begin(SCK, MISO, MOSI, SS);

  // pinMode(SS, OUTPUT);
  // // digitalWrite(SS, HIGH);
  // digitalWrite(SS, LOW); // enable Slave Select
  vspi = new SPIClass(FSPI);
  ioexpander = new TLA2518Class(*vspi,SS); //5
  if(!ioexpander->begin()) {
    Serial.println("Some error!");
    // return;
  };
  ioexpander->pinModeIO(0,ANALOG);
  // ioexpander->pinModeIO(2,ANALOG);
  // ioexpander->pinModeIO(3,ANALOG);
  // ioexpander->pinModeIO(4,ANALOG);
}

void loop() {
  // put your main code here, to run repeatedly:

  ioexpander->readStatus();
  //Read analog inputs
  int valAnalog0 = ioexpander->analogReadIO(0);
  // int valAnalog2 = ioexpander->analogReadIO(2);
  // int valAnalog3 = ioexpander->analogReadIO(3);
  // int valAnalog4 = ioexpander->analogReadIO(4);


  Serial.print("RAW_0:");
  Serial.print(valAnalog0);
  Serial.print(",");
  Serial.print("Voltage_0:");
  Serial.print((valAnalog0 / 4095.0) * REF_V);
  // Serial.print(",");
  // Serial.print("RAW_2:");
  // Serial.print(valAnalog2);
  // Serial.print(",");
  // Serial.print("RAW_3:");
  // Serial.print(valAnalog3);
  // Serial.print(",");
  // Serial.print("Voltage_2:");
  // Serial.print((valAnalog2 / 4095.0) * REF_V);  
  // Serial.print('V');
  // Serial.print(",");

  // Serial.print("Voltage_3:");
  // Serial.print((valAnalog3 / 4095.0) * 3.3);
  // Serial.println('V');
  // Serial.println('V \t');

  // Serial.print(valAnalog3);
  // Serial.print('V\t');
  // Serial.println(valAnalog4);
  Serial.println("");
  delay(1000);
  // delay(2);
  // delay(1);
}
