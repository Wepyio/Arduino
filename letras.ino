int abecedario[6][7] = {{1,0,1,1,0,1,1},{1,1,1,0,1,1,1},{1,0,0,1,1,1,1},{0,1,1,1,1,1,0},{1,0,0,1,1,1,1},{0,0,0,1,1,1,0}};

void setup(){
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  for(int i = 0; i <= 5; i++){
  digitalWrite(0, abecedario[i][0]);
  digitalWrite(1, abecedario[i][1]);
  digitalWrite(2, abecedario[i][2]);
  digitalWrite(3, abecedario[i][3]);
  digitalWrite(4, abecedario[i][4]);
  digitalWrite(5, abecedario[i][5]);
  digitalWrite(6, abecedario[i][6]);
  delay(1000);
  }
}
