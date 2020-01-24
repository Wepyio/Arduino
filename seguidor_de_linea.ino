//se deben conectar dos leds infrarrojos a 5v con un resistor de 330ohms
//los sensores van cruzados, sensor 1 del lado derecho, y sensor 2 izquierdo
//ambos sensores conectados a tierra y el terminal sobrante a su pin correspondiente
//recuerda conectar al puente H a una batería y unir tierras con el arduino
//ambos sensores buscaran la forma de estar sobre la pista negra
//la pista debe ser lo suficiente ancha para que ambos quepan

//terminales conectadas al puente H
const int in1 = 0;
const int in2 = 1;
const int in3 = 2;
const int in4 = 3;
//terminales conectadas a los sensores
const int sensor1 = 4;
const int sensor2 = 5;
//variables para guardar las lecturas
bool lectura1, lectura 2 = 0;

void setup() {
  //salidas hacia el puente H
 pinMode(OUTPUT, in1);
 pinMode(OUTPUT, in2);
 pinMode(OUTPUT, in3);
 pinMode(OUTPUT, in4);
 //entradas de los sensores
 pinMode(INPUT_PULLUP, sensor1);
 pinMode(INPUT_PULLUP, sensor2);
}

void loop() {
  //revisamos lo que detectan los sensores
  lectura1 = digitalRead(sensor1);
  lectura2 = digitalRead(sensor2);
  
  //revisa el sensor del lado derecho
  if(lectura1 = HIGH){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
  }else{
   digitalWrite(in2, HIGH);
   digitalWrite(in1, LOW);
  }
  //revisa el sensor del lago izquierdo
  if(lectura2 = HIGH){
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
  }else{
   digitalWrite(in4, HIGH);
   digitalWrite(in3, LOW);
  }

delay(10);
}
