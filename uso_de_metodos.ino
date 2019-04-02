//Programa con cambio de metodos

int baudrate = 9600;
char letra;

void setup(){
  Serial.begin(baudrate);
}

void loop(){
  metodo1();
}

void metodo1(){
  while(1){
    letra = Serial.read();
    if(letra == 'd'){
      metodo2();
    }
  }
}

void metodo2(){
  while(1){
    letra = Serial.read();
    if(letra == 'u'){
      metodo1();
    }
  }
}
