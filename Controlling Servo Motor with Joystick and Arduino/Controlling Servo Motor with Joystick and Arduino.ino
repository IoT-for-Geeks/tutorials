//For more Refer IoTforGeeks.com

#include <Servo.h>
Servo MyServo1;
Servo MyServo2;
int Servo1_Position; 
int Servo2_Position;

void setup() {
  //Set baud rate
  Serial.begin(9600);
  MyServo1.attach(5);
  MyServo2.attach(6);
}

void loop() {
  //Printing Joystick Data on Serial Monitor (You can comment the secion below if you don't want)
    Serial.print("Y:");
    Serial.println(analogRead(A0));
    Serial.print("X:");
    Serial.println(analogRead(A1));
  /////////////////////////////////////////////////////////////////////////////////////////////

    //Controlling Servo 1
    Servo1_Position = analogRead(A0);  //Reading Joystick Y position (Verical)
    Servo1_Position = map(Servo1_Position, 0, 1023, 0, 180);
    MyServo1.write(Servo1_Position);
    delay(15);

    //Controlling Servo 2
    Servo2_Position = analogRead(A1);  //Reading Joystick X position (Horizontal)
    Servo2_Position = map(Servo2_Position, 0, 1023, 0, 180);
    MyServo2.write(Servo2_Position);
    delay(15);
}
