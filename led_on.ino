//Programa que enciende un led 
//Recordar conectar el led con un resistor en serie de al menos 100 ohms
int led = 6; //terminal del arduino donde se conectara el led
void setup(){
  pinMode(led, OUTPUT); //se configura la terminal led como salida
}

void loop(){
  digitalWrite(led, HIGH); //HIGH o 1 enciende el led, LOW o 0 lo apaga
}
