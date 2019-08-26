int boton_a = 0;
bool estado_a;
bool flag = 0;
int contador = 0;
int i = 0;
int numeros[10][7] = {{1,0,0,1,1,1,0},{1,1,1,0,1,1,1},{0,0,1,0,1,0,1},{1,1,1,0,1,1,1},{0,1,1,1,1,0,1},{0,1,1,0,0,0,0},{1,0,0,1,1,1,1,},{0,0,1,0,1,0,1},{1,0,1,1,0,1,1},{1,0,0,1,1,1,1}};

void setup(){
  pinMode(boton_a, INPUT_PULLUP);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
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
i = contador;
  Serial.println(contador);
    digitalWrite(0, texto[i][0]);
    digitalWrite(1, texto[i][1]);
    digitalWrite(2, texto[i][2]);
    digitalWrite(3, texto[i][3]);
    digitalWrite(4, texto[i][4]);
    digitalWrite(5, texto[i][5]);
    digitalWrite(6, texto[i][6]);
}
