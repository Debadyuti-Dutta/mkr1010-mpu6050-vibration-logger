#include <Wire.h>

#define MPU6050_ADDR 0x68

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Wake up MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);  // Power Management 1 register
  Wire.write(0x00);  // Wake up sensor
  Wire.endTransmission(true);

  delay(100);

  // CSV header
  Serial.println("Time_ms,Ax,Ay,Az");
}

void loop() {

  // Start reading accelerometer registers
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU6050_ADDR, 6, true);

  int16_t rawAx = Wire.read() << 8 | Wire.read();
  int16_t rawAy = Wire.read() << 8 | Wire.read();
  int16_t rawAz = Wire.read() << 8 | Wire.read();

  // MPU6050 default accelerometer range = ±2g
  // Sensitivity = 16384 LSB/g
  float Ax = rawAx / 16384.0;
  float Ay = rawAy / 16384.0;
  float Az = rawAz / 16384.0;

  // Timestamp
  unsigned long time_ms = millis();

  // CSV output
  Serial.print(time_ms);
  Serial.print(",");
  Serial.print(Ax, 4);
  Serial.print(",");
  Serial.print(Ay, 4);
  Serial.print(",");
  Serial.println(Az, 4);

  // Approximately 100 Hz sampling
  delay(10);
}
