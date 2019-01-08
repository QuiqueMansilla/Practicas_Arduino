// Manejo de sensor de humedad de suelo
int humedad_suelo=2;
int rele = 4;
int buzzer = 7;
int valor_humedad_suelo;

void setup() {
  // put your setup code here, to run once:
  pinMode(rele, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  valor_humedad_suelo = analogRead(A0);
  Serial.print(valor_humedad_suelo);
  if (digitalRead(humedad_suelo)==LOW)
  {
    digitalWrite(rele, LOW);
    Serial.println("Humedo");
    
  }
  else
  {
    digitalWrite(rele, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Seco");
    delay(500);
    digitalWrite(buzzer, LOW);
    
  }
  delay(1000);

}
