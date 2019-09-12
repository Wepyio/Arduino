int i = 0;
int colores[8][3] = {{1,1,1},{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{0,0,0}};

void setup(){
 pinMode(0,OUTPUT);
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
}

void loop(){
 digitalWrite(0,colores[i][0]);
digitalWrite(1,colores[i][1]);
digitalWrite(2,colores[i][2]);
 delay(500);
 i = (i+1)%8;
}
