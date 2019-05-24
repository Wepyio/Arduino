//circuito luz nocturna
int led = 2;
int ldr = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
}

void loop(){
	ldr = analogRead(A0);
  if(ldr > 200){//si la luz disminuye, la resistencia sube
    digitalWrite(led, 1);
  }else{
    digitalWrite(led, 0);
  }
}
