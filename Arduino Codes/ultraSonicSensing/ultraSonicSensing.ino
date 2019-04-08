#include <NewPing.h>


int TrigPin = 8;
int EchoPin = 9; 

void setup() 
{
   Serial.begin(9600);
   pinMode(EchoPin, INPUT);
   pinMode(TrigPin, OUTPUT);
}
 
long Duration;
long d;

void loop() 
{ 
   digitalWrite(TrigPin,LOW); 
   delayMicroseconds(2); 
   digitalWrite(TrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(TrigPin, LOW);
   Duration = pulseIn(EchoPin, HIGH); 
   d = (Duration/2)/29.1;
   Serial.println(d);
}
