//Autor: Quique Mansilla
//Escuelta tecnica N° 2 Obispo Colombres
//Codigo que lee muestra en un LCD Winstar WH1602A el valor de la temperatura ambiente en Grados Celsius

#include <LiquidCrystal.h>
float tempC; //Define una variable: tempC de tipo float, es decir de tipo numerica con coma flotante

//Configuramos Pines que manejaran el LCD en el Arduino Uno
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //parametros (RS, EN, D4, D5, D6, D7)

//Se crea caracter personalizado " ° " Caracter en matriz de 5x8 pixeles
//ya que el LCD WH1602A no mustra el simbolo de Grados usando ASCII extendido
byte smiley[8] = {
  B01110,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); // Configura el pin analógico A0 como entrada
  
  //Crea el carater personalizado definido arriba " ° "
  lcd.createChar(0, smiley);
  
  // Configura el lcd con los siguientes parametros (Columnas, Filas)
  lcd.begin(16, 2); //LCD de 16 columnas x 2 filas
  
  // Imprime un mensaje en el lcd
  lcd.print("LM35 Temperatura");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Lee el valor desde el sensor
  tempC = analogRead(A0); // Es decir lee el valor que ingresa por el pin analogico A0 y lo guarda
                          // en la variable tempC
  // Convierte el valor a temperatura
  tempC = (5.0 * tempC * 100.0) / 1024.0; //Aplica la formula de conversion de la lectura guardada en
                                          //en tempC y la vuelve a guardar en tempC, asi se obtiene
                                          //el valor de la temperatura en grados centigrados
  
  lcd.setCursor(0, 1); //Posiciona el cursor en (Columna, fila)
                                          
  // Envia el valor al dsiplay LCD y lo muestra en Grados Celsius
  lcd.print(" Valor: ");
  lcd.print(tempC);
  lcd.write(byte(0));
  lcd.print("C");
  delay(3000);
  
}
