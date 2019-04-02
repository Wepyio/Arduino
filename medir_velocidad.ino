//Programa para medir velocidad
//Recordar conectar el led con un resistor en serie de al menos 100 ohms
int led = 6; //terminal del arduino donde se conectara el led
int sensor = 7;
float cont = 0; //variable de conteo
float ciclos = 16000000;
int baudrate = 9600;
float diametro = 2.0;
bool s = 0;
float vel;

void setup(){
  pinMode(led, OUTPUT); //se configura la terminal led como salida
  pinMode(sensor, INPUT_PULLUP);
  Serial.begin(baudrate);
}

void loop(){
  s = digitalRead(sensor);
  if(s == 1){
    cont += 1;
  }else if(s == 0 && cont > 0){
    vel = (diametro*ciclos)/cont;
    Serial.println(vel);
    cont = 0;
  }
}
