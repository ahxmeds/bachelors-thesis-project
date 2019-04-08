double randomnum;
long int_max = pow(2, 31) -1;
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{
  randomnum = (double)random(int_max)/int_max;
  Serial.println(randomnum);
  delay(100);
}
