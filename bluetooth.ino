//este es el codigo para cambiar la configuracion del modulo bluetooth

#include <SoftwareSerial.h>

SoftwareSerial Serial1(10, 11); // RX, TX

void setup() {
  // initialize both serial ports:
  Serial.begin(9600); //serial de pc a arduino
  Serial1.begin(9600); //serial de arduino a modulo
}

void loop(){
  if (Serial1.available()){//revisa si el modulo bluetooth envia algo
    int inByte = Serial1.read();//lo guarda en inbyte
    Serial.write(inByte);//lo  envia a la pc
  }

  if (Serial.available()){//revisa si la pc envia algo
    int inByte = Serial.read();//lo guarda en inbyte
    Serial1.write(inByte);//lo envia al modulo bluetooth
  }
}
