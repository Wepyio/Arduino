//Motor Stepper Velocidad Variable
int l1 = 11;//las 4 lineas de un stepper
int l2 = 12;
int l3 = 13;
int l4 = 14;
int a = 0;//variable de navegacion en la lista de salidas
int s[4] = {1,1,0,0};//lista de salidas
int t = 100;//maximo tiempo entre pasos
int pushl = 73;//pulsador de desaceleracion
int pushm = 74;//pulsador de aceleracion

void setup(){
  pinMode(l1, OUTPUT);//salidas hacia puente H o circuito de control
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(pushl, INPUT_PULLUP);//pull up de entrada, solo conectar pulsador externo a tierra
  pinMode(pushm, INPUT_PULLUP);
}

void loop(){
  digitalWrite(l1, s[(a)%4]);//escritura de salidas, cada linea esta a un paso de diferencia
  digitalWrite(l2, s[(a + 1)%4]);
  digitalWrite(l3, s[(a + 2)%4]);
  digitalWrite(l4, s[(a + 3)%4]);  
  a++;//moverse entre pasos
  delay(t);//pausa entre pasos
  if(t > 3 && digitalRead(pushm) == 0){//limite y aumento de velocidad
    t--;
  }else if(t < 100 && digitalRead(pushl) == 0){//minimo y disminucion de velocidad
    t++;
  }
}
