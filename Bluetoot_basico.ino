#include <LiquidCrystal.h>

#include <SoftwareSerial.h> //Para trabajar con modulo Bluetooth



SoftwareSerial BT1(10, 11); // RX, TX
int LED = 13; // El LED on-board 
int Data; // Dato recibido
 
void setup() {
  Serial.begin(9600);
  BT1.begin(9600);
  Serial.println("Esperando comando...");
  pinMode(LED,OUTPUT);
  digitalWrite(LED, LOW);
 
}
 
void loop() {
  if (BT1.available()){ //Esperando dato recibido
    Data=BT1.read();
    Serial.println("Dato disponilbe");
    Serial.write(Data);
    if(Data=='1'){  
      digitalWrite(LED,HIGH);
      Serial.println("LED Encendido!");
    }
    else if(Data=='0'){
       digitalWrite(LED,LOW);
       Serial.println("LED Apagado!");
    }
  }
  delay(100);
}
