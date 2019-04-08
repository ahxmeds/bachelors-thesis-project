    const int RightSensor = 1;

    const int LeftSensor = 2;



    int SensorLeft;

    int SensorRight;

    int SensorDifference;



    #include <AFMotor.h>



    AF_DCMotor leftMotor(1);

    AF_DCMotor rightMotor(2);



    void setup() {





    pinMode(LeftSensor, INPUT);

    pinMode(RightSensor, INPUT);

    Serial.begin(9600);

    Serial.println(" \nBeginning Light Seeking Behavior");

    }





    void loop() {

    SensorLeft = 1023 - analogRead(LeftSensor);

    delay(1);

    SensorRight = 1023 - analogRead(RightSensor);

    delay(1);

    SensorDifference = abs(SensorLeft - SensorRight);



    Serial.print("Left Sensor = ");

    Serial.print(SensorLeft);

    Serial.print("\t");

    Serial.print("Right Sensor = ");

    Serial.print(SensorRight);

    Serial.print("\t");



    if (SensorLeft > SensorRight && SensorDifference > 75) {

    Serial.println("Left");

    rightMotor.setSpeed(200);

    rightMotor.run(FORWARD);

    delay(250);

    rightMotor.run(RELEASE);

    delay(100);



    }



    if (SensorLeft < SensorRight && SensorDifference > 75) {

    Serial.println("Right");

    leftMotor.setSpeed(200);

    leftMotor.run(FORWARD);

    delay(250);

    leftMotor.run(RELEASE);

    delay(100);

    }



    else if (SensorDifference < 75) {

    Serial.println("Forward");

    leftMotor.setSpeed(200);

    rightMotor.setSpeed(200);

    leftMotor.run(FORWARD);

    rightMotor.run(FORWARD);

    delay(500);

    leftMotor.run(RELEASE);

    rightMotor.run(RELEASE);



    }

    Serial.print("\n");

    }
