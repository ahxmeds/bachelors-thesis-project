#include<AFMotor.h>


AF_DCMotor LeftMotor(2);
AF_DCMotor RightMotor(1);

const int LeftSensor = A2;
const int RightSensor = A3;
const int TrigPin = 8;
const int EchoPin = 9;

int LeftSensorValue;
int RightSensorValue;
int SensorDifference;


int DeltaTime = 4000;
long CollisionThreshold = 6;
int ThresholdIntensity = 75;
int MaximumIntensity = 600;
double RandomNumberSide;
double RandomNumberAngle;
long Int_Max = pow(2, 31) - 1;
int ThetaTime;
int TurnTime;
double UniformRandomNumber;


long Duration;
long Distance;
int velocity = 30;

int LeftTurnTimefor45deg = 424;
int RightTurnTimefor45deg = 432;

int Angle;
double r;

void setup()
{ 
  pinMode(LeftSensor, INPUT);
  pinMode(RightSensor, INPUT);
  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{

Distance = ping();
//Serial.println(Distance);
LeftSensorValue = analogRead(LeftSensor);
delay(1);
RightSensorValue = analogRead(RightSensor);
delay(1);
SensorDifference = abs(LeftSensorValue - RightSensorValue);
//Serial.print(LeftSensorValue);
//Serial.print(" ");
//Serial.println(RightSensorValue);
if(LeftSensorValue >= MaximumIntensity  && RightSensorValue >= MaximumIntensity)
     {
       while(1)
        {
           Serial.println("In loop");
           delay(500000);
        }       
     }


//UniformRandomNumber = (double) random(Int_Max)/Int_Max;
//DeltaTime = (int) 3000/pow(216 - 215*UniformRandomNumber, 0.3333);
Serial.println(DeltaTime);

if(Distance >= CollisionThreshold)
 { 
 
  if(SensorDifference < ThresholdIntensity)
  {
    {
       RandomNumberSide = (double) random(Int_Max)/Int_Max;
       //Serial.println(RandomNumberSide);
      if(RandomNumberSide < 0.5)
        {  
           Angle = GenerateRandomAngle();
           ThetaTime = LeftTurnTimeFunction(Angle);
           TurnLeft(ThetaTime);
           MoveForward(DeltaTime); 
        }
       
      else
       {  
        Angle = GenerateRandomAngle();
        ThetaTime = RightTurnTimeFunction(Angle);
        TurnRight(ThetaTime);
        MoveForward(DeltaTime);
       }   
    }   
  }

  if(SensorDifference >= ThresholdIntensity)
  {
    if(LeftSensorValue > RightSensorValue)
      { //Turn Left
        TurnLeft(LeftTurnTimefor45deg);
        MoveForward(DeltaTime); 
       }
     
     if(LeftSensorValue < RightSensorValue)
       { //Turn Right
         TurnRight(RightTurnTimefor45deg);
         MoveForward(DeltaTime);  
       }
   }
 }

else
 { 
   MoveBackward();
   TurnRight(1000);   
 } 
   
}


long ping()
{  
   long d;
   digitalWrite(TrigPin,LOW); 
   delayMicroseconds(2); 
   digitalWrite(TrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(TrigPin, LOW);
   Duration = pulseIn(EchoPin, HIGH); 
   d = (Duration/2)/29.1;
   return d;
}

int GenerateRandomAngle()
{ 
  int num;
  int Max = 90;
  int Min = 0;
  num = random(Min, Max);
  return num; 
}


int RightTurnTimeFunction(int angle)
{
   int TimeRight = (angle + 1.20547)/0.10687;
   return TimeRight;
}

int LeftTurnTimeFunction(int angle)
{
  int TimeLeft = (int) (angle + 0.96452)/0.10831;
  return TimeLeft;
}


void TurnRight(int Time)
{ 
  //Serial.println("Right");
  LeftMotor.setSpeed(250);
  RightMotor.setSpeed(250);
  LeftMotor.run(BACKWARD);
  RightMotor.run(BACKWARD);
  delay(Time);
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(100); 
}

void TurnLeft(int Time)
{ 
  //Serial.println("Left");
  LeftMotor.setSpeed(250);
  RightMotor.setSpeed(250);
  LeftMotor.run(FORWARD);
  RightMotor.run(FORWARD);
  delay(Time); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(100);
}


void MoveForward(int Time)
{ 
  //Serial.println("Forward");
  LeftMotor.setSpeed(velocity);
  RightMotor.setSpeed(velocity);
  LeftMotor.run(BACKWARD);
  RightMotor.run(FORWARD);
  delay(Time); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(100);
}

void MoveBackward()
{ //Serial.println("Back");
  LeftMotor.setSpeed(250);
  RightMotor.setSpeed(250);
  LeftMotor.run(FORWARD);
  RightMotor.run(BACKWARD);
  delay(500); 
  LeftMotor.run(RELEASE);
  RightMotor.run(RELEASE);
  delay(100);
}


