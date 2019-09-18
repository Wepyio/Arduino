void setup(){
  DDRD = 255;
}

void loop(){
  for(int i = 0; i < 256; i++){
  	PORTD = i;
  	delay(1);
}
  for(int i = 255; i > 1; i--){
  	PORTD = i;
  	delay(1);
}
}
