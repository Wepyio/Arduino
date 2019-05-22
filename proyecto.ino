int listaz1[5] = {1,0,0,1,0};
int listaz2[5] = {0,1,0,0,0};
int listad1[5] = {1,0,1,0,0};
int listad2[5] = {0,1,0,0,0};
int listaangulos[5] = {0,45,90,135,180};

int n = 4;

void loop(){
    manual();
}

void movimiento(n){
    digitalWrite(z1, listaz1[n]);
    digitalWrite(z2, listaz2[n]);
    digitalWrite(d1, listad1[n]);
    digitalWrite(d2, listad2[n]);
}

void manual(){
while(1){
    leer();
    if(red == 'w'){
        movimiento(0);
    }else if(red == 's'){
        movimiento(1);
    }else if(red == 'a'){
        n = 2;
        movimiento();
    }else if(red == 'A' or digitalRead(boton1) == '0'){
        automatico();
}
}
}

void automatico(){
while(1){
    leer();
    medir(angulo);
    revisardistancia();
}
}

void medir(angulo){
    se(listaangulos[angulo]);
}

void revisardistancia(){
    movimiento(0);
}

void leer(){
    if(Serial.available()>0){
        red = Serial.read();
}
}
