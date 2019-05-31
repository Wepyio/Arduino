#include <Servo.h>

Servo miservo1;
Servo miservo2;
Servo miservo3;

int giro1, adelante2, arribayabajo;
bool agarra, bandera;
int angulo1 = 90;
int angulo2 = 90;
int angulo3 = 90;

void setup(){
  miservo1.attach(3);
  miservo2.attach(5);
  miservo3.attach(6);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop(){
  giro1 = analogRead(A0);
  adelante2 = analogRead(A1);
  arribayabajo = analogRead(A2);
  Serial.println(giro1);
 
  if(giro1 < 410 && angulo1 > 0){
    angulo1 -= 1;
    miservo1.write(angulo1);
  }else if(giro1 > 675 && angulo1 < 180){
    angulo1 += 1;
    miservo1.write(angulo1);
  }
  if(adelante2 < 410 && angulo2 > 0){
    angulo2 -= 1;
    miservo2.write(angulo2);
  }else if(adelante2 > 675 && angulo2 < 180){
    angulo2 += 1;
    miservo2.write(angulo2);
  }
  if(arribayabajo < 410 && angulo3 > 0){
    angulo3 -= 1;
    miservo3.write(angulo3);
  }else if(arribayabajo > 675 && angulo3 < 180){
    angulo3 += 1;
    miservo3.write(angulo3);
  }

  delay(100);
}
