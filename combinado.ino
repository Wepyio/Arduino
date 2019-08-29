int boton_a = 0;
bool estado_a;
bool flag = 0;
int boton_b = 8;
bool estado_b;
bool flag2 = 0;
int contador = 0;
int i = 0;
int numeros[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1,},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
//						0				1				2				3				4				5				6				7				8				9
void setup(){
  pinMode(boton_a, INPUT_PULLUP);
  pinMode(boton_b, INPUT_PULLUP);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  estado_a = digitalRead(boton_a);
  if(estado_a == 1){
  	flag = 0;
  }else if(estado_a == 0 and  flag == 0 and contador < 9){
  	flag = 1;
    contador += 1;
  }
  estado_b = digitalRead(boton_b);
  if(estado_b == 1){
  	flag2 = 0;
  }else if(estado_b == 0 and  flag2 == 0 and contador > 0){
  	flag2 = 1;
    contador -= 1;
  }
i = contador;

    digitalWrite(1, numeros[i][0]);
    digitalWrite(2, numeros[i][1]);
    digitalWrite(3, numeros[i][2]);
    digitalWrite(4, numeros[i][3]);
    digitalWrite(5, numeros[i][4]);
  	digitalWrite(6, numeros[i][5]);
  	digitalWrite(7, numeros[i][6]);
}
