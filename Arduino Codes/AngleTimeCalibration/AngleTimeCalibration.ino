#include<AFMotor.h>


AF_DCMotor LeftMotor(2);
AF_DCMotor RightMotor(1);

int velocity = 200;
void setup()
{ 
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

int time = 700;

void loop()
{
  delay(1000);
  TurnLeft(time);
  delay(500000);

}


void TurnRight(int ThetaTime)
{
  LeftMotor.setSpeed(255);
  RightMotor.setSpeed(255);
  LeftMotor.run(FORWARD);
  RightMotor.run(BACKWARD);
  delay(ThetaTime);
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(10); 
}

void TurnLeft(int ThetaTime)
{
  LeftMotor.setSpeed(255);
  RightMotor.setSpeed(255);
  LeftMotor.run(BACKWARD);
  RightMotor.run(FORWARD);
  delay(ThetaTime); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(10);
}


void MoveForward(int DeltaTime)
{
  LeftMotor.setSpeed(velocity);
  RightMotor.setSpeed(velocity);
  LeftMotor.run(FORWARD);
  RightMotor.run(FORWARD);
  delay(DeltaTime); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(10);
}

void MoveBackward()
{
  LeftMotor.setSpeed(velocity);
  RightMotor.setSpeed(velocity);
  LeftMotor.run(BACKWARD);
  RightMotor.run(BACKWARD);
  delay(700); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(10);
}
