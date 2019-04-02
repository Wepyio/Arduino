//Programa para medir ciclos de reloj
//Recordar conectar el led con un resistor en serie de al menos 100 ohms
int led = 6; //terminal del arduino donde se conectara el led
int i = 0; //variable de conteo
int limite = 5000000;

void setup(){
  pinMode(led, OUTPUT); //se configura la terminal led como salida
}

void loop(){
  digitalWrite(led, HIGH); //HIGH o 1 enciende el led
  while(i < limite){//medir con un cronometro el tiempo entre encendidos, dividir limite*2 entre el tiempo medido
    i+=1;
  }
  digitalWrite(led, LOW); //LOW o 0 apaga el led
  while(i > 0){
    i-=1;
  }  
}
