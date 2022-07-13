#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
File myFile;
// const int chipSelect = 10;
// char dataStr[100] = "";
// char buffer[10];

float shuntvoltage = 0;
float busvoltage = 0;
float current_mA = 0;
float loadvoltage = 0;
float power_mW = 0;

float USBVoltage = 0;
float USBCurrent_ma = 0;
float USBPower_mw = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(A3, INPUT);
    if (SD.begin(10))
    {
        Serial.println("SD card is present & ready");
    }
    else
    {
        //        Serial.println("SD card missing or failure");
        while (1)
            ; // halt program
    }
    // clear out old data file
    if (SD.exists("csv.csv"))
    {
        //        Serial.println("Removing simple.csv");
        SD.remove("csv.csv");
        //        Serial.println("Done");
    }

    // write csv headers to file:
    myFile = SD.open("csv.csv", FILE_WRITE);
    //  if (myFile) // it opened OK
    //  {
    //        Serial.println("Writing headers to csv.csv");
    myFile.println("Time,SolarVoltage,SolarCurrent_ma,SolarPower_mw,USBVoltage,USBCurrent_ma,USBPower_mw,Effective");
    myFile.close();
    //        Serial.println("Headers written");
    //  }
    //  else
    //        Serial.println("Error opening csv.csv");
    // Serial.println("Enter w for write, r for read or s for split csv");

    while (!Serial)
    {
        // will pause Zero, Leonardo, etc until serial console opens
        delay(1);
    }

    uint32_t currentFrequency;

    //    Serial.println("Hello!");

    // Initialize the INA219.
    // By default the initialization will use the largest range (32V, 2A).  However
    // you can call a setCalibration function to change this range (see comments).
    if (!ina219.begin())
    {
        //        Serial.println("Failed to find INA219 chip");
        while (1)
        {
            delay(10);
        }
    }
    // To use a slightly lower 32V, 1A range (higher precision on amps):
    // ina219.setCalibration_32V_1A();
    // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
    // ina219.setCalibration_16V_400mA();

    //    Serial.println("Measuring voltage and current with INA219 ...");
}
void loop()
{

    // shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    power_mW = ina219.getPower_mW();
    // loadvoltage = busvoltage + (shuntvoltage / 1000);
    USBVoltage = (float(map(analogRead(A3), 0, 1023, 0, 1000)) / 100);
    USBCurrent_ma = USBVoltage * USBVoltage * 80;
    USBPower_mw = USBCurrent_ma * USBVoltage;
    // Serial.println(USBVoltage);
    // Serial.print("Bus Voltage:   ");
    // Serial.print(busvoltage);
    // Serial.println(" V");
    // Serial.print("Shunt Voltage: ");
    // Serial.print(shuntvoltage);
    // Serial.println(" mV");
    // Serial.print("Load Voltage:  ");
    // Serial.print(loadvoltage);
    // Serial.println(" V");
    // Serial.print("Current:       ");
    // Serial.print(current_mA);
    // Serial.println(" mA");
    // Serial.print("Power:         ");
    // Serial.print(power_mW);
    // Serial.println(" mW");
    // Serial.println("");
    // ltoa(millis(), buffer, 10); // conver long to charStr
    // strcat(dataStr, buffer);    // add it onto the end
    // strcat(dataStr, ", ");      // append the delimeter

    // dtostrf(busvoltage, 10, 4, buffer); // 5 is mininum width, 1 is precision; float value is copied onto buff
    // strcat(dataStr, buffer);            // append the coverted float
    // strcat(dataStr, ", ");              // append the delimeter

    // dtostrf(current_mA, 10, 4, buffer); // 5 is mininum width, 1 is precision; float value is copied onto buff
    // strcat(dataStr, buffer);            // append the coverted float
    // strcat(dataStr, ", ");              // append the delimeter

    // dtostrf(power_mW, 10, 4, buffer); // 5 is mininum width, 1 is precision; float value is copied onto buff
    // strcat(dataStr, buffer);          // append the coverted float
    // strcat(dataStr, ", ");            // append the delimeter

    myFile = SD.open("csv.csv", FILE_WRITE);
    // if the file opened okay, write to it:
    if (myFile)
    {
        //        Serial.println("Writing to csv.txt");
        myFile.print(millis());
        myFile.print(", ");
        myFile.print(busvoltage);
        myFile.print(", ");
        myFile.print(current_mA);
        myFile.print(", ");
        myFile.print(power_mW);
        myFile.print(", ");
        myFile.print(USBVoltage);
        myFile.print(", ");
        myFile.print(USBCurrent_ma);
        myFile.print(", ");
        myFile.print(USBPower_mw);
        myFile.print(", ");
        myFile.print(USBPower_mw / power_mW);
        myFile.println(", ");
        // myFile.println(dataStr);
        myFile.close();
    }
    // else
    // {
    //     //        Serial.println("error opening csv.txt");
    // }
    delay(1000);
}