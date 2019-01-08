//Autor Quique Mansilla
//Escuela Tecnica N°2 Obispo Colombres
//Medicion de volumen en litros de una cisterna usando sensor ultrasonico 
 
const int EchoPin = 11;
const int TriggerPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  float litros = ping(TriggerPin, EchoPin);
  float imprimir_valor(float litros);
  delay(1000);
}
// Se crea la funcion "ping" para medir la distancia usando las caracteristicas del sensor ultrasonico
float ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm, Volumen; 
  float VolLitros;
  const float ancho = 17.5 ;//Ancho en cm
  const float largo = 12.5; //Largo en cm
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm

  Volumen = distanceCm*ancho*largo; // Calculamos el volumen en cm3

  VolLitros = Volumen / 1000.0; //Pasamos de cm3 a litros 
  
  return VolLitros;
}
void imprimir_valor(float litros){
  Serial.print("Volumen: ");
  Serial.print(litros, 3);
  Serial.println(" litros");
  }
