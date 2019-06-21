#include <Servo.h>

Servo miservo1;
Servo miservo2;
Servo miservo3;
Servo pinza;

int giro1, adelante2, arribayabajo, agarrar;
bool agarra, bandera, cambio;
int boton = 2;
int angulo1 = 90;
int angulo2 = 90;
int angulo3 = 90;
int cerrado = 120;
int abierto = 60;

void setup(){
  miservo1.attach(3);
  miservo2.attach(5);
  miservo3.attach(6);
  pinza.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(boton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  giro1 = analogRead(A0);
  adelante2 = analogRead(A1);
  arribayabajo = analogRead(A2);
  agarra = digitalRead(boton);
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
  if(agarra == 0 && bandera == 1 && cambio == 0){
  	pinza.write(cerrado);
    bandera = 0;
    cambio = 1;
  }else if(agarra == 0 && bandera == 0 && cambio == 0){
  	pinza.write(abierto);
    bandera = 1;
    cambio = 1;
  }else if(agarra == 1){
  	cambio = 0;
  }
  delay(100);
}
