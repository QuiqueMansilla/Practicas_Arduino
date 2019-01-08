//Autor Quique Mansilla
//Escuela Tecnica N°2 Obispo Colombres
//Medicion de nivel de agua en %, de un valde usando sensor ultrasonico usando funciones definidas por el usuario
 
const int EchoPin = 11;
const int TriggerPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  float Distancia = ping(TriggerPin, EchoPin); //Se llama a la funcion "ping" definida al final y guardo el valor que devuelve dicha funcion en variable Distancia
  imprimeValor(Distancia); //Se llama a la funcion "inprimeValor" que muestra en Monitor serial el valor de la distancia (cm)
  long int Nivel = nivel(Distancia);   //Se llama a la funcion "nivel" definida al final y guardo el valor que devuelva esta funcion en variable "Nivel"
  imprimeValor1(Nivel); //Se llama a la funcion "inprimeValor1" que muestra en Monitor serial el valor del nivel (%)
  delay(1000);
}

//AREA DE DEFINICION DE FUNCIONES

// Se define la funcion "ping" para medir la distancia usando las caracteristicas del sensor ultrasonico. El valor de la distancia indica el nivel(cm)
float ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm

  return distanceCm;
}

//Se define la funcion "nivel" que calcula el nivel de agua en %, suponemos una profundidad de 15 cm + distancia ubicacion del sensor (8 cm)
long int nivel(int Distancia){
  const int Vacio = 23; //Distancia maxima, cuando el bidon está vacio
  long int Porciento;
  Porciento = (-(100*(Distancia - Vacio)))/15;  //Calcula el nivel de agua en % Ecuacion de una recta Y  = Nivel(%); x = Distancia(cm)
                                                //x = 8 cm -> Y = 100% (valde lleno); x = 23 cm -> y = 0% (valde vacio)
  return Porciento;                                      
  }

//Definicion de funcion "impreimeValor" que muestra en monitor serial valor de "Distancia"
void imprimeValor(float Distancia) {
  Serial.print("Distancia: ");
  Serial.print(Distancia);
  Serial.println(" cm");
  return;
  }
//Definicion de funcion "imprimeValor1" que muestra en monitor serial valor de "Nivel" en %
void imprimeValor1(long int Nivel) {
  Serial.print("Nivel: ");
  Serial.print(Nivel);
  Serial.println(" %");
  return;
  }
  
