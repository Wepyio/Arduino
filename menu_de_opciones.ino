int opcion = 6;
int seleccion = 5;
int ledham = 4;
int ledhd = 3;
int ledpz = 2;
int ledgel = 1;
int ledpas = 0;
int cont = 0;
bool opt, sel;
int pausa = 200;

void setup(){
  pinMode(ledham, OUTPUT);
  pinMode(ledhd, OUTPUT);
  pinMode(ledpz, OUTPUT);
  pinMode(ledgel, OUTPUT);
  pinMode(ledpas, OUTPUT);
  pinMode(opcion, INPUT_PULLUP);
  pinMode(seleccion, INPUT_PULLUP);
}

void loop(){
  opt = digitalRead(opcion);
  sel = digitalRead(seleccion);
  if(opt == 0){
    delay(pausa);
    if(cont < 4){
    	cont += 1;
    }else{
      cont = 0;
    }
  }else if(sel == 0){
    delay(pausa);
    digitalWrite(cont, HIGH);
    delay(pausa);
    digitalWrite(cont, LOW);
    delay(pausa);
  }
}
