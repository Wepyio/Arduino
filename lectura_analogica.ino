//Programa para lectura analogica
//Recordar qalue la entrada no exceda 5 voltios

int adc = 5;//terminal con analog read, usa un convertidor analogico digital
int lectura;
int pausa = 200;
int baudrate = 9600;

void setup(){
  pinMode(adc, INPUT);
  Serial.begin(baudrate);
}

void loop(){
  lectura = analogRead(adc);
  Serial.print("La lectura es ");
  Serial.println(lectura);
  delay(pausa);
}
