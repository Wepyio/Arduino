//motor servo controlado por potenciometro
#include <Servo.h>
int motor = 3; //señal del servo al pin 3
int pot;
Servo miservo;

void setup(){
  miservo.attach(motor);
  pinMode(A0, INPUT); //potenciometro al A0
}

void loop(){
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  miservo.write((pot*180)/255);
  delay(10);
}
