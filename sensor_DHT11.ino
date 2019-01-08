#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE); //El objeto DHT lo instancio en PIN y Tipo

void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();
}

void loop() {
    // Esperamos 5 segundos entre medidas
  delay(5000);
 
  // Leemos la humedad relativa
  float humedad = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float temperatura_celsius = dht.readTemperature();// Grado centigrado no lleva argumento
  // Leemos la temperatura en grados Fahrenheit
  float temperatura_farenheit = dht.readTemperature(true);// Grado Farenheit lleva TRUE como argumento
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(humedad) || isnan(temperatura_celsius) || isnan(temperatura_farenheit)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en Fahrenheit
  float sensacion_termica_farenheit = dht.computeHeatIndex(temperatura_farenheit, humedad);
  // Calcular el índice de calor en grados centígrados
  float sensacion_termica_celsius = dht.computeHeatIndex(temperatura_celsius, humedad, false);
 
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print("%    ");
  Serial.print("Temperatura: ");
  Serial.print(temperatura_celsius);
  Serial.print("*C    ");
  Serial.print(temperatura_farenheit);
  Serial.print("*F    ");
  Serial.print("Sensación Térmica: "); //Tambien llamado indice de calor.
  Serial.print(sensacion_termica_farenheit);
  Serial.print("*F    ");
  Serial.print(sensacion_termica_celsius);
  Serial.println("*C    ");
 
}
