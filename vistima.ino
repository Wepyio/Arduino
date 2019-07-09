#include <Servo.h>
Servo se;
Servo sed;
char red = 'p';
int z1 = 53;
int z2 = 55;
int d1 = 57;
int d2 = 59;
int en1 = 0;
int en2 = 1;
int cepillo = 2;
int listaz1[5] = {1,0,0,1,0};
int listaz2[5] = {0,1,0,0,0};
int listad1[5] = {1,0,1,0,0};
int listad2[5] = {0,1,0,0,0};
int listaangulos[7] = {0,45,90,135,180,30,100};//ajustar acorde a las pruebas
int velocidades[6] = {0,120,150,140,180,100};//ajustar acorde a las pruebas
int baudrate = 9600;
int constante = 58;
int pausa = 500;
int distancias[5] = {};
int n = 4;
int m = 0;
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
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(z1, OUTPUT);
  pinMode(z2, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(cepillo, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
}

void loop(){
    manual();
}

void movimiento(int n, int m){
    digitalWrite(z1, listaz1[n]);
    digitalWrite(z2, listaz2[n]);
    digitalWrite(d1, listad1[n]);
    digitalWrite(d2, listad2[n]);
    analogWrite(en1, velocidades[m]);
    analogWrite(en2, velocidades[m]);
}

void manual(){
while(1){
    leer();
    if(red == 'w'){
      movimiento(0, 4);
    }else if(red == 's'){
      movimiento(1, 4);
    }else if(red == 'a'){
      movimiento(2, 4);
    }else if(red == 'd'){
      movimiento(3, 4);
    }else if(red == 'p'){//movimientos
      movimiento(4, 0);
    }else if(red == 'c'){
      analogWrite(cepillo, velocidades[1]);
    }else if(red == 'C'){
      analogWrite(cepillo, velocidades[0]);
    }else if(red == 'z'){
      sed.write(listaangulos[6]);
    }else if(red == 'Z'){
      sed.write(listaangulos[5]);
    }else if(red == 'A' || (digitalRead(boton1) == '0' && flag == 0)){
        flag = 1;
        automatico();
    }
    if(digitalRead(boton1) == 1){
      flag = 0;
    }
}
}

void automatico(){
  while(1){
    leer();
    revisardistancias();
    
    if(red == 'M' || (digitalRead(boton1) == '0' && flag == 0)){
      flag = 1;
      manual();
    }
    if(digitalRead(boton1) == 1){
      flag = 0;
    }
  }
}

void medir(int angulo, int pausa){
  se.write(listaangulos[angulo]);
  delay(pausa);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tiempo = pulseIn(echo,HIGH);
  distancia = tiempo/constante;
}

void revisardistancias(){
  medir(2, 400);
  if(distancia > 100){
    movimiento(0, 2);
  }else{
    movimiento(4, 0);
    medir(2, 500); 
    if(distancia > 100){
      movimiento(2, 3);
      delay(600);
      movimiento(0, 2);
    }else{
      medir(3, 800);
      if(distancia > 100){
        movimiento(3, 3);
        delay(600);
        movimiento(0, 2);
      }else{
        movimiento(3, 5);
        delay(1100);
        movimiento(0, 2);
      }
    }
  }
}

void leer(){
  if(Serial1.available()>0){
    red = Serial1.read();
  }
}
