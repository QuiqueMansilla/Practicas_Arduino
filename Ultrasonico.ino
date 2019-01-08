// Menejo basico de sensor ultrasonico 
const int EchoPin = 11;
const int TriggerPin = 12;
const int LedPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000);
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
