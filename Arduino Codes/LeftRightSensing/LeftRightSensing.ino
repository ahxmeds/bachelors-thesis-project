const int LeftSensor = A1;
const int RightSensor = A2;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
int LeftSensorValue = analogRead(LeftSensor);
int RightSensorValue = analogRead(RightSensor);

Serial.print("Left Sensor = ");
Serial.print(LeftSensorValue);
Serial.print("\t");
Serial.print("Right Sensor = ");
Serial.print(RightSensorValue);
Serial.println("\t");

}
