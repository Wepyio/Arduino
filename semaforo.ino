int ledrojo = 0;
int ledamarillo = 1;
int ledverde = 2;
int tlargo = 3000;
int tcorto = 200;

void setup(){
  pinMode(ledrojo, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(ledverde, OUTPUT);  
}

void loop(){
  digitalWrite(ledverde, HIGH);
  delay(tlargo);
  digitalWrite(ledverde, LOW);
  for(int i = 0; i < 5; i++){
    digitalWrite(ledamarillo, HIGH);
    delay(tcorto);
    digitalWrite(ledamarillo, LOW);
    delay(tcorto);
  }
  digitalWrite(ledrojo, HIGH);
  delay(tlargo);
  digitalWrite(ledrojo, LOW);
}
