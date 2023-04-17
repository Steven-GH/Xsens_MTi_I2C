# Arduino I<sup>2</sup>C library for Xsens MTi 1-series #
## Introduction ##
This Arduino library demonstrates basic Xbus communication between an Arduino and an Xsens MTi 1-series shield board (MTi-#-DK) using the I<sup>2</sup>C interface. The example code is merely a starting point for code development. Its functionality can be extended by making use of the Xbus protocol. Xbus is the proprietary binary communication protocol that is supported by all Xsens MTi products, and it is fully documented in the [MT Low-Level Communication Protocol Document](https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation).

For further guidance on using this example code, please refer to [Xsens BASE](https://base.xsens.com/s/article/Interfacing-the-MTi-1-series-DK-with-an-Arduino?language=en_US).

## Tested hardware ##
**Arduino:**
* Uno
* Due

**Xsens MTi:**
* MTi-3-DK
* MTi-7-DK
* MTi-8-DK

## Setup ##
At least the following hardware connections are required:
* MTi_SCL - Arduino_SCL
* MTi_SDA - Arduino_SDA
* MTi_GND - Arduino_GND
* MTi_3.3V - Arduino_3.3V
* MTi_DRDY - Arduino_D3

Additionally, make sure to:
* Enable I<sup>2</sup>C by switching PSEL0,1 to "1"
* Supply the MTi-#-DK with 3.3V (since 5V will force USB mode)
* Add 2.7 kOhm pullup resistors to the SCL/SDA lines (only for MTi-#-DK board Rev 2.3 or older - newer revisions come with onboard pullup resistors)

## Functionality ##
After connecting with an MTi 1-series device, the example code will request device information (product code and firmware version). It will then continue to configure the outputs of the MTi (1 Hz default, 10 Hz selectable):
* MTi-1: RateOfTurn and Acceleration
* MTi-2/3: EulerAngles
* MTi-7/8: EulerAngles and Latitude/Longitude

After configuring, the MTi will be forced into Measurement mode and the received data will be printed to the serial monitor. 

