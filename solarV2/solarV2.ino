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
  Serial.begin(115200);

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
  Serial.print("Time_ms");
  Serial.print(",");
  Serial.print("Solar Voltage_V");
  Serial.print(",");
  Serial.print("Solar Current_mA");
  Serial.print(",");
  Serial.print("Solar Power_mW");
  Serial.print(",");
  Serial.print(",");
  Serial.print("MPPT Voltage_V");
  Serial.print(",");
  Serial.print("MPPT Current_mA");
  Serial.print(",");
  Serial.print("MPPT Power_mW");
  Serial.print(",");
  Serial.print("MPPT Efficiency_%");
  Serial.print(",");
  Serial.print(",");
  Serial.print("USB Voltage_V");
  Serial.print(",");
  Serial.print("USB Current_mA");
  Serial.print(",");
  Serial.print("USB Power_mW");
  Serial.println();

}
void loop()
{
  //  shuntvoltage = INA219_1.getShuntVoltage_mV();
  busvoltage_1 = INA219_1.getBusVoltage_V();
  current_mA_1 = INA219_1.getCurrent_mA();
  power_W_1 = INA219_1.getPower_mW();

  busvoltage_2 = INA219_2.getBusVoltage_V();
  current_mA_2 = INA219_2.getCurrent_mA();
  power_W_2 = INA219_2.getPower_mW();

  busvoltage_3 = INA219_3.getBusVoltage_V();
  current_mA_3 = INA219_3.getCurrent_mA();
  power_W_3 = INA219_3.getPower_mW();
  Serial.print(millis());
  Serial.print(",");
  Serial.print(busvoltage_1);
  Serial.print(",");
  Serial.print(current_mA_1);
  Serial.print(",");
  Serial.print(power_W_1);
  Serial.print(",");

  Serial.print(",");
  Serial.print(busvoltage_2);
  Serial.print(",");
  Serial.print(current_mA_2);
  Serial.print(",");
  Serial.print(power_W_2);
  Serial.print(",");
  Serial.print(power_W_2 * 100 / power_W_1);
  Serial.print(",");

  Serial.print(",");
  Serial.print(busvoltage_3);
  Serial.print(",");
  Serial.print(current_mA_3);
  Serial.print(",");
  Serial.print(power_W_3);
  Serial.println();
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
  delay(500);
}
