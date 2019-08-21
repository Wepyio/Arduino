int boton_a = 0;
bool estado_a;
bool flag = 0;
int contador = 0;

void setup(){
  pinMode(boton_a, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  estado_a = digitalRead(boton_a);
  if(estado_a == 1){
  	flag = 0;
  }else if(estado_a == 0 and  flag == 0 and contador < 10){
  	flag = 1;
    contador += 1;
  }
  Serial.println(contador);
}
