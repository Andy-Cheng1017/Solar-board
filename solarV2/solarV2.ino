#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 INA219_1(0X44);
Adafruit_INA219 INA219_2(0X41);
Adafruit_INA219 INA219_3(0X40);

float busvoltage_1 = 0;
float current_mA_1 = 0;
float power_W_1 = 0;
float busvoltage_2 = 0;
float current_mA_2 = 0;
float power_W_2 = 0;
float busvoltage_3 = 0;
float current_mA_3 = 0;
float power_W_3 = 0;

void setup()
{
  Serial.begin(9600);

  while (!Serial)
  {
    // will pause Zero, Leonardo, etc until serial console opens
    delay(1);
  }

  if (!INA219_1.begin())
  {
    Serial.println("Failed to find 1INA219 chip");
    while (1)
    {
      delay(10);
    }
  }

  if (!INA219_2.begin())
  {
    Serial.println("Failed to find 2INA219 chip");
    while (1)
    {
      delay(10);
    }
  }

  if (!INA219_3.begin())
  {
    Serial.println("Failed to find 3INA219 chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.print("Solar Voltage");
  Serial.print(",");
  Serial.print("Solar Current");
  Serial.print(",");
  Serial.print("Solar Power");
  Serial.print(",");
  Serial.print(",");
  Serial.print("MPPT Voltage");
  Serial.print(",");
  Serial.print("MPPT Current");
  Serial.print(",");
  Serial.print("MPPT Power");
  Serial.print(",");
  Serial.print("MPPT Efficiency");
  Serial.print(",");
  Serial.print(",");
  Serial.print("USB Voltage");
  Serial.print(",");
  Serial.print("USB Current");
  Serial.print(",");
  Serial.print("USB Power");
  Serial.print(",");
  Serial.print("USB Efficiency");
  Serial.println();

}
void loop()
{
  Serial.print("Solar Voltage");
  Serial.print(",");
  Serial.print("Solar Current");
  Serial.print(",");
  Serial.print("Solar Power");
  Serial.print(",");
  Serial.print(",");
  Serial.print("MPPT Voltage");
  Serial.print(",");
  Serial.print("MPPT Current");
  Serial.print(",");
  Serial.print("MPPT Power");
  Serial.print(",");
  Serial.print("MPPT Efficiency");
  Serial.print(",");
  Serial.print(",");
  Serial.print("USB Voltage");
  Serial.print(",");
  Serial.print("USB Current");
  Serial.print(",");
  Serial.print("USB Power");
  Serial.print(",");
  Serial.print("USB Efficiency");
  Serial.println();
  // shuntvoltage = ina219.getShuntVoltage_mV();
  //  busvoltage = ina219.getBusVoltage_V();
  //  current_mA = ina219.getCurrent_mA();
  //  power_mW = ina219.getPower_mW();
  //
  //  myFile.print(millis());
  //  myFile.print(", ");
  //  myFile.print(busvoltage);
  //  myFile.print(", ");
  //  myFile.print(current_mA);
  //  myFile.print(", ");
  //  myFile.print(power_mW);
  //  myFile.print(", ");
  //  myFile.print(USBVoltage);
  //  myFile.print(", ");
  //  myFile.print(USBCurrent_ma);
  //  myFile.print(", ");
  //  myFile.print(USBPower_mw);
  //  myFile.print(", ");
  //  myFile.print(USBPower_mw / power_mW);
  //  myFile.println(", ");
  //  // myFile.println(dataStr);
  //  myFile.close();
//  delay(1000);
}
