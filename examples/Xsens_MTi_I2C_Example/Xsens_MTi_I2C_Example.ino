//This library demonstrates basic Xbus communication between an Arduino (Uno) and an Xsens MTi 1-series shield board (MTi-#-DK) using the I2C interface.

//At least the following hardware connections are required:
//MTi_SCL - Arduino_SCL
//MTi_SDA - Arduino_SDA
//MTi_GND - Arduino_GND
//MTi_3.3V - Arduino_3.3V
//MTi_DRDY - Arduino_D3
//Additionally, make sure to:
//  -Enable I2C by switching PSEL0,1 to "1"
//  -Supply the MTi-#-DK with 3.3V (since 5V will force USB mode)
//  -Add 2.7 kOhm pullup resistors to the SCL/SDA lines (only for MTi-#-DK board Rev 2.3 or older - newer revisions come with onboard pullup resistors)

//This example code is merely a starting point for code development. Its functionality can be extended by making use of the Xbus protocol.
//Xbus is the proprietary binary communication protocol that is supported by all Xsens MTi products, and it is fully documented at https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation

//For further details on this example code, please refer to BASE: https://base.xsens.com/s/article/Interfacing-the-MTi-1-series-DK-with-an-Arduino?language=en_US


#include "MTi.h"
#include <Wire.h>

#define DRDY 3                      //Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B                //MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *MyMTi = NULL;


void setup() {
  Serial.begin(115200);             //Initialize communication for serial monitor output (Ctrl+Shift+M)
  Wire.begin();                     //Initialize Wire library for I2C communication
  pinMode(DRDY, INPUT);             //Data Ready pin, indicates whether data/notifications are available to be read

  MyMTi = new MTi(ADDRESS, DRDY);   //Create our new MTi object

  if (!MyMTi->detect(1000)) {       //Check if MTi is detected before moving on
    Serial.println("Please check your hardware connections.");
    while (1) {
      //Cannot continue because no MTi was detected.
    }
  } else {
    MyMTi->goToConfig();            //Switch device to Config mode
    MyMTi->requestDeviceInfo();     //Request the device's product code and firmware version
    MyMTi->configureOutputs();      //Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
    MyMTi->goToMeasurement();       //Switch device to Measurement mode
  }
}

void loop() {
  if (digitalRead(MyMTi->drdy)) {   //MTi reports that new data/notifications are available
    MyMTi->readMessages();          //Read new data messages
    MyMTi->printData();             //...and print them to the serial monitor (Ctrl+Shift+M)
  }
  delay(10);
}
