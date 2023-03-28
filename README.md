This library demonstrates basic Xbus communication between an Arduino (Uno) and an Xsens MTi 1-series shield board (MTi-#-DK) using the I2C interface.

At least the following hardware connections are required:
-MTi_SCL - Arduino_SCL
-MTi_SDA - Arduino_SDA
-MTi_GND - Arduino_GND
-MTi_3.3V - Arduino_3.3V
-MTi_DRDY - Arduino_D3
Additionally, make sure to:
-Enable I2C by switching PSEL0,1 to "1"
-Supply the MTi-#-DK with 3.3V (since 5V will force USB mode)
-Add 2.7 kOhm pullup resistors to the SCL/SDA lines (only for MTi-#-DK board Rev 2.3 or older - newer revisions come with onboard pullup resistors)

This example code is merely a starting point for code development. Its functionality can be extended by making use of the Xbus protocol. Xbus is the proprietary binary communication protocol that is supported by all Xsens MTi products, and it is fully documented at https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation

For further details on this example code, please refer to BASE: https://base.xsens.com/s/article/Interfacing-the-MTi-1-series-DK-with-an-Arduino?language=en_US
