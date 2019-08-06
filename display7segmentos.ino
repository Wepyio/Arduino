//Display de 7 segmentos

int texto[10][7] = {{1,0,0,1,1,1,0},{1,1,1,0,1,1,1},{0,0,1,0,1,0,1},{1,1,1,0,1,1,1},{0,1,1,1,1,0,1},{0,1,1,0,0,0,0},{1,0,0,1,1,1,1,},{0,0,1,0,1,0,1},{1,0,1,1,0,1,1},{1,0,0,1,1,1,1}};
//					c				a				n				a				d				i				e				n				s				e	

void setup(){//configuracion e inicializacion
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){//ciclo que se repite infinitamente
  for(int i = 0; i < 10; i++){
    digitalWrite(0, texto[i][0]);
    digitalWrite(1, texto[i][1]);
    digitalWrite(2, texto[i][2]);
    digitalWrite(3, texto[i][3]);
    digitalWrite(4, texto[i][4]);
    digitalWrite(5, texto[i][5]);
    digitalWrite(6, texto[i][6]);
    delay(1000);
  }
}
