//uuuu uuuu uuu uuu con cuerpo de pony
#include <Servo.h>
Servo se;
Servo sed;
char red = 'p';
int z1 = 53;
int z2 = 55;
int d1 = 57;
int d2 = 59;
int listaz1[5] = {1,0,0,1,0};
int listaz2[5] = {0,1,0,0,0};
int listad1[5] = {1,0,1,0,0};
int listad2[5] = {0,1,0,0,0};
int listaangulos[5] = {0,45,90,135,180};
int baudrate = 1200;
int constante = 58;
int distancias[5] = {};
int n = 4;
int angulo = 0;
int trigger = 76;
int echo = 78;
int tiempo, distancia;
int boton1 = 77;
bool flag = 0;

void setup(){
  se.attach(6);
  sed.attach(7);
  Serial1.begin(baudrate);
  pinMode(trigger, INPUT);
  pinMode(echo, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
}

void loop(){
    manual();
}

int movimiento(int n){
    digitalWrite(z1, listaz1[n]);
    digitalWrite(z2, listaz2[n]);
    digitalWrite(d1, listad1[n]);
    digitalWrite(d2, listad2[n]);
}

void manual(){
while(1){
    leer();
    if(red == 'w'){
      movimiento(0);
    }else if(red == 's'){
      movimiento(1);
    }else if(red == 'a'){
      movimiento(2);
    }else if(red == 'p'){
      movimiento(4);
    }else if(red == 'A' || (digitalRead(boton1) == '0' && flag == 0)){
        automatico();
        flag = 1;
    }
    if(digitalRead(boton1) == 1){
      flag = 0;
    }
}
}

void automatico(){
  while(1){
    leer();
    for(int i = 0; i<5; i++){
      medir(i);
      distancias[i] = distancia;
    }
    revisardistancias();
    if(red == 'M' || (digitalRead(boton1) == '0' && flag == 0)){
      manual();
      flag = 1;
    }
    if(digitalRead(boton1) == 1){
      flag = 0;
    }
  }
}

int medir(int angulo){
  se.write(listaangulos[angulo]);
  delay(500);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(echo, HIGH);
  delayMicroseconds(10);
  digitalWrite(echo, LOW);
  tiempo = pulseIn(trigger,HIGH);
  distancia = tiempo/constante;
}

void revisardistancias(){
  if(distancias[2] > 100){
    movimiento(0);
  }else if(distancias[2] < 30){
    movimiento(4);
  }
}

void leer(){
  if(Serial1.available()>0){
    red = Serial1.read();
  }
}
