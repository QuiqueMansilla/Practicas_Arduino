// Menejo basico de sensor ultrasonico 
const int EchoPin = 11;
const int TriggerPin = 12;
const int BombaPin = 13;
const int Maximo = 4; //Adaptar el valor de esta constante para el caso particular en que se aplique
const int Minimo = 8; //Idem linea anterior
int Nivel = 30; //Condicion inical, tanque vacio, valor se adapta al caso particular en que se aplique

void setup() {
  Serial.begin(9600);
  pinMode(BombaPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  digitalWrite(BombaPin, LOW); //Inicia el sistema cono la Bomba apagada
  //Ejecuta la condicion inicial: El sistema cuando inicia, supone cisterna vacia
  //Entonces encendera la cisterna hasta llenarla, luego ingresa en modo trabajo normal
  while (Nivel > Maximo){
    int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println("cm");
    Nivel = cm;
    delay(1000);
    digitalWrite(BombaPin, HIGH); //Enciende la bomba
    Serial.println("Iniciando llenado cisiterna");
    }
    digitalWrite(BombaPin, LOW);
    Serial.println("Cisterna llena");
    Serial.println("Iniciando modo normal de trabajo");  
}

void loop() {
  int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
      Serial.print("Distancia: ");
      Serial.print(cm);
      Serial.println("cm");
      Nivel = cm;
      delay(1000);
      //Mientras el nivel se encuentre entre el maximo y el minimo mantiene bomba apagada
  while ((Nivel < Minimo)&&(Nivel > Maximo)){
      int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
      Serial.print("Distancia: ");
      Serial.print(cm);
      Serial.println("cm");
      Nivel = cm;
      digitalWrite(BombaPin, LOW);  //Apaga la bomba si el nivel supera el Maximo ó si el nivel
                                    // se encutra en el minimo y el maximo
      Serial.println("Bomba Apagada");
      delay(1000);                             
      }
      Nivel = cm;
      delay(500);
  if (Nivel > Minimo) {
    do {
    Serial.println("Reponer nivel de cisterna");
    int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println("cm");
    Nivel = cm;
    digitalWrite(BombaPin, HIGH); // Enciende la bomba para que se llene la cisterna
    Serial.println("Bomba Encendida");
    delay(1000);
    } while (Nivel > Maximo);
  }
}
// Se crea el objeto "ping" para medir la distancia usando las caracteristicas del sensor ultrasonico
int ping(int TriggerPin, int EchoPin) { 
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
