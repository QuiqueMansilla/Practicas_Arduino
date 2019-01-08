//Autor Quique Mansilla
//Escuela Tecnica N° 2 Obispo Colombres
//Control de Nivel de cisterna automatico usando un sensor ultrasonico 
//La variable "NivelxDistancia" contiene la distancia desde el sensor hasta el espejo de agua
//A mayor valor de "NivelxDistancia" menor nivel de agua

const int EchoPin = 11;
const int TriggerPin = 12;
const int BombaPin = 13;
const int Maximo = 4; //Adaptar el valor de esta constante para el caso particular en que se aplique
const int Minimo = 8; //Idem linea anterior
int NivelxDistancia = 30; //Condicion inical, tanque vacio, valor se adapta al caso particular en que se aplique

void setup() {
  Serial.begin(9600);
  pinMode(BombaPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  digitalWrite(BombaPin, LOW); //Inicia el sistema cono la Bomba apagada
  //Ejecuta la condicion inicial: El sistema cuando inicia, supone cisterna vacia
  //Entonces encendera la bomba hasta llenar cisterna, luego ingresa en modo trabajo normal
  while (NivelxDistancia > Maximo){
    int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println("cm");
    NivelxDistancia = cm;
    delay(1000);
    digitalWrite(BombaPin, HIGH); //Enciende la bomba
    Serial.println("Iniciando llenado cisiterna");
    }
    digitalWrite(BombaPin, LOW); //Apaga la bomba
    Serial.println("Cisterna llena");
    Serial.println("Bomba Apagada");
      
}

void loop() {
  Serial.println("Iniciando modo normal de trabajo");
  int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
      Serial.print("Distancia: ");
      Serial.print(cm);
      Serial.println("cm");
      NivelxDistancia = cm;
      delay(1000);
  //Si el nivel es menor que el Maximo mantiene la Bomba apagada hasta que este por debajo del minimo
  if (NivelxDistancia > Maximo){
    do {
      int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
      Serial.print("Distancia: ");
      Serial.print(cm);
      Serial.println("cm");
      NivelxDistancia = cm;
      digitalWrite(BombaPin, LOW);  //Apaga la bomba si el nivel supera el Maximo ó si el nivel
                                    // se encutra en el minimo y el maximo
      Serial.println("Bomba Apagada");
      delay(1000);
    } while (NivelxDistancia < Minimo);                             
  }
  NivelxDistancia = cm;
  delay(500);
  // Si el nivel esta por debajo del Minimo enciente la bomba hasta que alcamce el maximo
  if (NivelxDistancia > Minimo) {
    do {
    Serial.println("Reponer nivel de cisterna");
    int cm = ping(TriggerPin, EchoPin); // La variable "cm" guarda el valor del nivel en cm
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println("cm");
    NivelxDistancia = cm;
    digitalWrite(BombaPin, HIGH); // Enciende la bomba para que se llene la cisterna
    Serial.println("Bomba Encendida");
    delay(1000);
    } while (NivelxDistancia > Maximo);
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
