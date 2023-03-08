#define rojo 3
#define verde 6
#define azul 9
#define botonf 7
#define botonc 8
#define umbral 100
#define lmax 150
#define lmed 100
#define lmin 50
#define funcionl 7

int tiempos[16] = {160, 150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
int salidar, salidag, salidab = 0;
int t_on = 100;
bool b1, b2, pendiente, cambio = 0;
int funcion, pasos, paso, salto, estado = 0;
int volumen = 0;

void setup(){
  pinMode(A0, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(botonf, INPUT_PULLUP);
  pinMode(botonc, INPUT_PULLUP);
}

void loop(){
  analogWrite(rojo, salidar);
  analogWrite(verde, salidag);
  analogWrite(azul, salidab);
  delay(t_on);

  salidar = 0;
  salidag = 0;
  salidab = 0;

  analogWrite(rojo, salidar);
  analogWrite(verde, salidag);
  analogWrite(azul, salidab);
    
  revisar();
  efectuar();
}

void revisar(){
  if(digitalRead(botonf) == 0 and b1 == 0){
    delay(5);
    b1 = 1;
    if(funcion < funcionl){
      funcion = funcion + 1;
    }else{
      funcion = 0;
    }
  }else if(digitalRead(botonf) == 1 and b1 == 1){
      b1 = 0;
  }
  
  if(digitalRead(botonc) == 0 and b2 == 0){
    delay(5);
    b2 = 1;
    if(estado < 15){
       estado = estado + 1;
    }else{
      estado = 0;
    }
  }else if(digitalRead(botonc) == 1 and b2 == 1){
      b2 = 0;
  }
}

void efectuar(){
  switch(funcion){
    case 0:
      t_on = 100;
      color_fijo();
      break;
    case 1:
      color_variable();
      break;
    case 2:
      brillo_fijo();
      break;
    case 3:
      brillo_variable();
      break;
    case 4:
      intermitente();
      break;
    case 5:
      flash();
      break;
    case 6:
      estroboscopico();
      break;
    case 7:
      audio();  
      break;
  }
}

void color_fijo(){
  switch(estado){
    case 0:
      salidar = lmax; //rojo
      break;
    case 1:
      salidag = lmax; //verde
      break;
    case 2:
      salidab = lmax; //azul
      break;
    case 3:
      salidar = lmax; //amarillo
      salidag = lmax;
      break;
    case 4:
      salidag = lmax; //aqua
      salidab = lmax;
      break;
    case 5:
      salidar = lmax; //morado
      salidab = lmax;
      break;
    case 6:
      salidar = lmax; //blanco
      salidag = lmax;
      salidab = lmax;
      break;
    case 7:
      salidar = lmax; //rosado
      salidag = lmed;
      salidab = lmed;
      break;
    case 8:
      salidar = lmed; //verde menta
      salidag = lmax;
      salidab = lmed;
      break;
    case 9:
      salidar = lmed; //celeste
      salidag = lmed;
      salidab = lmax;
      break;
    case 10:
      salidar = lmax; //naranja
      salidag = lmax;
      salidab = lmed;
      break;
    case 11:
      salidar = lmed; //turquesa
      salidag = lmax;
      salidab = lmax;
      break;
    case 12:
      salidar = lmax; //violeta
      salidag = lmed;
      salidab = lmax;
      break;
    case 13:
      salidar = lmax; //rojo b
      salidag = lmin;
      salidab = lmin;
      break;
    case 14:
      salidar = lmin; //verde b
      salidag = lmax;
      salidab = lmin;
      break;
    case 15:
      salidar = lmin; //azul b
      salidag = lmin;
      salidab = lmax;
      break;
  }
}

void color_variable(){
  if (paso < 255){
    paso = paso + 1;
  }else{
    paso = 0;
  }
  
  if (paso < 16){
    salidar = paso*10;
  }else if(paso < 31){
    salidar = lmax*2 - paso*10;
    salidag = paso*10 - 150;
  }else if(paso < 46){
    salidag = lmax*3 - paso*10;
    salidab = paso*10 - 300;
  }else if(paso < 61){
    salidab = lmax*4 - paso*10;
    salidar = paso*10 - 450;
    salidag = paso*10 - 450;
  }else if(paso < 76){
    salidar = lmax*5 - paso*10;  
    salidag = lmax;
    salidab = paso*10 - 600;  
  }else if(paso < 91){
    salidar = paso*10 - 750;    
    salidag = lmax*6 - paso*10;  
    salidab = lmax;  
  }else if(paso < 106){
    salidar = lmax;  
    salidab = lmax;  
    salidag = paso*10 - 900;    
  }else if(paso < 121){
    salidar = lmax;
    salidag = lmax - (paso - 105)*3;  
    salidab = lmax - (paso - 105)*3;  
  }else if(paso < 136){
    salidar = lmax - (paso - 120)*3;  
    salidag = lmed + (paso - 120)*3;  
    salidab = lmed;    
  }else if(paso < 151){
    salidar = lmed;  
    salidag = lmax - (paso - 135)*3;  
    salidab = lmed + (paso - 135)*3;  
  }else if(paso < 166){
    salidar = lmed + (paso - 150)*3;    
    salidag = lmed + (paso - 150)*3;  
    salidab = lmax - (paso - 150)*3;  
  }else if(paso < 181){
    salidar = lmax - (paso - 165)*3;    
    salidag = lmax;
    salidab = lmed + (paso - 165)*3;  
  }else if(paso < 196){
    salidar = lmed + (paso - 180)*3;    
    salidag = lmax - (paso - 180)*3;    
    salidab = lmax;    
  }else if(paso < 211){
    salidar = lmax;    
    salidag = lmax - (paso - 195)*6;    
    salidab = lmax - (paso - 195)*6;      
  }else if(paso < 226){
    salidar = lmax - (paso - 210)*6;    
    salidag = lmin + (paso - 210)*6;    
    salidab = lmin;    
  }else if(paso < 241){
    salidar = lmin;    
    salidag = lmax - (paso - 225)*6;    
    salidab = lmin + (paso - 225)*6;      
  }else if(paso < 256){
    salidar = lmin - (paso - 240)*3;    
    salidag = lmin - (paso - 240)*3;    
    salidab = lmax - (paso - 240)*10;      
  }

  t_on = tiempos[estado];
}

void brillo_fijo(){
  if (paso < 255){
    paso = paso + 1;
  }else{
    paso = 0;
  }

  if (paso < 16){
    salidar = lmax;
  }else if(paso < 31){
    salidag = lmax;
  }else if(paso < 46){
    salidab = lmax;
  }else if(paso < 61){
    salidar = lmax;
    salidag = lmax;
  }else if(paso < 76){
    salidag = lmax;
    salidab = lmax;
  }else if(paso < 91){
    salidar = lmax; 
    salidab = lmax;  
  }else if(paso < 106){
    salidar = lmax;  
    salidab = lmax;  
    salidag = lmax;
  }else if(paso < 121){
    salidar = lmax;
    salidag = lmed;
    salidab = lmed;
  }else if(paso < 136){
    salidar = lmed;
    salidag = lmax;
    salidab = lmed;    
  }else if(paso < 151){
    salidar = lmed;  
    salidag = lmed;
    salidab = lmax;
  }else if(paso < 166){
    salidar = lmax;
    salidag = lmax;
    salidab = lmed;
  }else if(paso < 181){
    salidar = lmax;
    salidag = lmed;
    salidab = lmax;
  }else if(paso < 196){
    salidar = lmed;
    salidag = lmax;
    salidab = lmax;    
  }else if(paso < 211){
    salidar = lmax;    
    salidag = lmin;
    salidab = lmin;
  }else if(paso < 226){
    salidar = lmin;
    salidag = lmax;
    salidab = lmin;    
  }else if(paso < 241){
    salidar = lmin;    
    salidag = lmin;
    salidab = lmax;
  }else if(paso < 256){
    salidar = lmed;
    salidag = lmed;
    salidab = lmed;
  }
    
  t_on = tiempos[estado];
}

void brillo_variable(){
  if(pendiente == 0){  
    paso = paso + 5;
    if (paso >= 150){
      pendiente = 1;  
    }
  }else{
    paso = paso - 5;    
    if (paso < 5){
      pendiente = 0;
    }
  }
  
  t_on = 100;
  
  switch(estado){
    case 0:
      salidar = paso; //rojo
      break;
    case 1:
      salidag = paso; //verde
      break;
    case 2:
      salidab = paso; //azul
      break;
    case 3:
      salidar = paso; //amarillo
      salidag = paso;
      break;
    case 4:
      salidag = paso; //aqua
      salidab = paso;
      break;
    case 5:
      salidar = paso; //morado
      salidab = paso;
      break;
    case 6:
      salidar = paso; //blanco
      salidag = paso;
      salidab = paso;
      break;
    case 7:
      salidar = paso; //rosado
      salidag = paso*2/3;
      salidab = paso*2/3;
      break;
    case 8:
      salidar = paso*2/3; //verde menta
      salidag = paso;
      salidab = paso*2/3;
      break;
    case 9:
      salidar = paso*2/3; //celeste
      salidag = paso*2/3;
      salidab = paso;
      break;
    case 10:
      salidar = paso; //naranja
      salidag = paso;
      salidab = paso*2/3;
      break;
    case 11:
      salidar = paso*2/3; //turquesa
      salidag = paso;
      salidab = paso;
      break;
    case 12:
      salidar = paso; //violeta
      salidag = paso*2/3;
      salidab = paso;
      break;
    case 13:
      salidar = paso; //rojo b
      salidag = paso/3;
      salidab = paso/3;
      break;
    case 14:
      salidar = paso/3; //verde b
      salidag = paso;
      salidab = paso/3;
      break;
    case 15:
      salidar = paso/3; //azul b
      salidag = paso/3;
      salidab = paso;
      break;
  }
}

void intermitente(){
  t_on = 50;
  if(paso < 10){
    paso = paso + 1;
    color_fijo();
  }else if (paso < 20){
    paso = paso + 1;
  }else{
    paso = 0;
  }
}

void flash(){
  t_on = 50;
  if(paso < 2){
    paso = paso + 1;
    color_fijo();
  }else if (paso < 20){
    paso = paso + 1;
  }else{
    paso = 0;
  }
}

void estroboscopico(){
  t_on = 50;
  if(paso < 1){
    paso = paso + 1;
    color_fijo();
  }else if (paso < 2){
    paso = paso + 1;
  }else{
    paso = 0;
  }  
}

void audio(){
  if (analogRead(A0) >= umbral){
    t_on = 50;
    color_fijo();
  }
}
