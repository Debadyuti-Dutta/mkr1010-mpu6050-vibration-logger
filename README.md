# Vibration Logger (Arduino MKR WiFi 1010 + MPU6050)

A simple hardware setup to log vibration and motion data in real time using an MPU-6050 IMU connected to an Arduino MKR WiFi 1010.

### Hardware
- Arduino MKR WiFi 1010
- MPU-6050 accelerometer & gyroscope module
- Breadboard and jumper wires

### Wiring (I2C)
- **MPU6050 VCC** -> Arduino MKR 3.3V
- **MPU6050 GND** -> Arduino MKR GND
- **MPU6050 SDA** -> Arduino MKR Pin 11 (SDA)
- **MPU6050 SCL** -> Arduino MKR Pin 12 (SCL)

### What It Does
- Reads raw acceleration and gyro rate from the MPU-6050 over I2C (address `0x68`).
- Uses baseline calibration to filter out sensor drift.
- Flags abnormal vibration spikes when values exceed the safety threshold.

### How to Run
1. Wire the sensor as listed above.
2. Open the code in the Arduino IDE.
3. Select board **Arduino MKR WiFi 1010** and flash the code.
4. Open the Serial Monitor at **115200 baud** to see real-time output.
