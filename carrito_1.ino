const int controlPin1 =2;
const int controlPin2 =3;
const int enablePin =9;

const int trigpin = 10;
const int echopin = 11;
long duracion, distancia;


int motorEnabled =1;
int motorSpeed = 0;
int motorDirection =1;

const int controlRotPin1 =4;
const int controlRotPin2 =5;
const int enableRotPin=8;

int motorEnabled2=0;
int motorDirection2=1;

long intervalo2 = 2000;   // es el tiempo de nuestro delay        
long tiempo2 = 0;
long tiempoAnterior2 = 0;


long intervalo = 300;   // es el tiempo de nuestro delay        
long tiempo = 0;
long tiempoAnterior = 0;


void setup(){
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
}

void loop(){
//motorSpeed=analogRead(potPin)/4;

 Serial.println(motorSpeed);
 calcularDistancia();
 avanzar();
 if(distancia >0 && distancia <=25){
 analogWrite(enablePin, 0);
 rotarDerecha();
 retroceder();
 delay(1000);
 rotarIzquierda();
 avanzar();
  }
  else{
    avanzaNormal();
    avanzar();
  }

}



  
void avanzar(){
  digitalWrite(controlPin1,LOW);
  digitalWrite(controlPin2, HIGH);
  analogWrite(enablePin, 200);
}

void retroceder(){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    analogWrite(enablePin, 209);
}
void avanzaNormal(){
    digitalWrite(controlRotPin1, HIGH);
    digitalWrite(controlRotPin2, HIGH);
   analogWrite(enableRotPin, 69); 
}
void rotarDerecha(){
  
    digitalWrite(controlRotPin1, HIGH);
    digitalWrite(controlRotPin2, LOW);
    analogWrite(enableRotPin, 300);
}

void rotarIzquierda(){
    digitalWrite(controlRotPin1, LOW);
    digitalWrite(controlRotPin2, HIGH);
    analogWrite(enableRotPin, 300);
}
int calcularDistancia(){
  digitalWrite(10,LOW);
  delayMicroseconds(5);
  digitalWrite(10,HIGH);
  delayMicroseconds(10);
  duracion = pulseIn(11, HIGH);
  distancia=int(0.017*duracion);
  
  Serial.print("duracion:");
  Serial.println(duracion);
  Serial.print("distancia:");
  Serial.print(distancia);
  Serial.println();
  
 // delay(10);
  return distancia;
}

boolean calculaTiempo(){
  
 if(tiempo - tiempoAnterior > intervalo)  // pasará por aqui cada 1000 contajes
      {
         return true;
      }
    
  else
    return false;  
}

