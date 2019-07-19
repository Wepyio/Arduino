int rojo = 30;
int verde = 39;
int azul = 40;
int rojos[12] =  {225,  0,  0,225,0,225,  0,225,225,100,225,100};
int verdes[12] = {  0,225,  0,225,0,225,225,  0, 50,225,100,225};
int azules[12] = {  0,  0,225,225,0,  0,225,225, 50,100,  0,  0};

void setup(){
  pinMode(rojo, OUTPUT);  
  pinMode(verde, OUTPUT);  
  pinMode(azul, OUTPUT);  
}

void loop(){
  for(int n = 0; n < 12; n++){
    analogWrite(rojo, rojos[n]);
    analogWrite(verde, verdes[n]);
    analogWrite(azul, azules[n]);
    delay(1500);  
  }
}
