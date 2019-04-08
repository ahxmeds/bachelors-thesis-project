const int led = 2;

int ledState = 0;

unsigned long previousMillis = 0;

const long interval = 1000;

void setup()
{
  pinMode(led, OUTPUT);  
}


void loop()
{
  
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval)
  {
     previousMillis = currentMillis;
    
    if(ledState == 0)
       { 
          ledState = 1;
       } 
     else
       {
          ledState = 0;
        }  
  digitalWrite(led,ledState);  
  }
}
