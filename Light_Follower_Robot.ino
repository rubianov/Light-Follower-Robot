//Definiendo los pines físicos de motor y sensores 
#define motorIzqA 2
#define motorIzqB 3
#define motorDerA 4
#define motorDerB 5
#define sensor0 A0
#define sensor1 A1


void setup() { // Establecer las variables de la lectura de los sensores (fotoR) y sus salidas en señales de voltaje (OutR)
  int fotoR1 = 0;
  int fotoR0 = 0;  
  int outR1 = 0;
  int outR0 = 0;
 
  //Clasificar los pines de los motores como salidas/actuadores
  pinMode(motorIzqA, OUTPUT);
  pinMode(motorIzqB, OUTPUT);
  pinMode(motorDerA, OUTPUT);
  pinMode(motorDerB, OUTPUT);
}

//Función de giro hacia la izquierda
void izquierda(){
  digitalWrite(motorIzqA, HIGH);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, HIGH);
  digitalWrite(motorDerB, LOW);
}
//Función de giro hacia la derecha
void derecha(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, HIGH);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, HIGH);
}
//Función de giro hacia adelante
void avanzar(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, HIGH);
  digitalWrite(motorDerA, HIGH);
  digitalWrite(motorDerB, LOW);
}
//Función de giro hacia atras
//void retoceder(){
  //digitalWrite(motorIzqA, HIGH);
  //digitalWrite(motorIzqB, LOW);
  //digitalWrite(motorDerA, LOW);
  //digitalWrite(motorDerB, HIGH);
}
//Función para detenerse
void detenerse(){
  digitalWrite(motorIzqA, LOW);
  digitalWrite(motorIzqB, LOW);
  digitalWrite(motorDerA, LOW);
  digitalWrite(motorDerB, LOW);
}
//Lectura de los valores analógicos por los sensores y transformados en otra escala más reducida de voltaje
void loop(){
  int fotoR1 = analogRead(sensor0);
  int fotoR0 = analogRead(sensor1);
  int outR1 = map(fotoR1, 0, 1023, 0, 255); //sensor de la derecha
  int outR0 = map(fotoR0, 0, 1023, 0, 255); //sensor de la izquierda
  
  // Lógica de operación
  if (outR0 < 170 or outR1 < 170){
    if(outR0-outR1>30){
      derecha();
    } else{
      if(outR1-outR0>30){
        izquierda();
      } else{
        avanzar();
      }
    }
  } else{
    detenerse();
  }
}