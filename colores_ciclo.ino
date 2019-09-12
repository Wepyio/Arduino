void setup(){
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
}

void loop(){
for(int i = 0; i < 256; i++){
 analogWrite(3,i);
 analogWrite(6,255-i);   analogWrite(5,255);
 delay(100);
}
for(int j = 0; j < 256; j++){
 analogWrite(5,j);
 analogWrite(3,255-j);    analogWrite(6,255);
 delay(100);
}
for(int k = 0; k < 256; k++){
 analogWrite(6,k);
 analogWrite(5,255-k);   analogWrite(3,255);
 delay(100);
}
}
