//Programa del led intermitente
//Recordar conectar el led con un resistor en serie de al menos 100 ohms
int led = 6; //terminal del arduino donde se conectara el led
int pausa = 500; //tiempo que estara el led encendido o apagado

void setup(){
  pinMode(led, OUTPUT); //se configura la terminal led como salida
}

void loop(){
  digitalWrite(led, HIGH); //HIGH o 1 enciende el led
  delay(pausa);// pausa representa 500 milisegundos o medio segundo
  digitalWrite(led, LOW); //LOW o 0 apaga el led
  delay(pausa);
}
