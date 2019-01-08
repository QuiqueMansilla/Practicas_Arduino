//Autor Quique Mansilla
//Escuela Tecnica N° 2 Obispo Colombres
//Control de Nivel de cisterna automatico usando un sensor ultrasonico 
//La variable "NivelxDistancia" contiene la distancia desde el sensor hasta el espejo de agua
//A mayor valor de "NivelxDistancia" menor nivel de agua

const int EchoPin = 11;
const int TriggerPin = 12;
const int BombaPin = 13;//Pin de salida para encender bomba
const int Maximo = 4; //Adaptar el valor de esta constante para el caso particular en que se aplique
const int Minimo = 8; //Idem linea anterior
int NivelxDistancia = 32; //Condicion inical, tanque vacio, valor se adapta al caso particular en que se aplique

void setup() {
  Serial.begin(9600);
  pinMode(BombaPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  void apagarBomba(int BombaPin); //Apaga la Bomba cuando inicia
  
  //Ejecuta la condicion inicial: El sistema cuando inicia, supone cisterna vacia
  //Entonces encendera la bomba hasta llenar cisterna, luego ingresa en modo trabajo normal
  while (NivelxDistancia > Maximo){
    int cm = ping(TriggerPin, EchoPin); // Se mide distancia al sensor para determinar nivel
    int imprimeValor(int cm);// Se imprime el valor de la medicion en cm
    NivelxDistancia = cm;
    delay(1000);
    void encenderBomba(int BombaPin); //Enciende la bomba para llenar la cisterna
    Serial.println("Iniciando llenado de cisiterna");
    }
    void apagarBomba(int BombaPin);
    Serial.println("Cisterna llena");  
}

void loop() {
  Serial.println("Iniciando modo normal de trabajo");
  int cm = ping(TriggerPin, EchoPin); // Se mide la distancia al sensor en cm, que es el nivel
  int imprimeValor(int cm);
  delay(1000);
  //Si el nivel es menor que el Maximo mantiene la Bomba apagada hasta que este por debajo del minimo
  if (NivelxDistancia > Maximo){
    do {
      int cm = ping(TriggerPin, EchoPin); // Se mide la distancia al sensor en cm, que es el nivel
      int imprimeValor(int cm);
      NivelxDistancia = cm;
      void apagarBomba(int BombaPin);//Apaga la bomba si el nivel supera el Maximo ó si el nivel
                                    // se encutra en el minimo y el maximo
      delay(1000);
    } while (NivelxDistancia < Minimo);                             
  }
  NivelxDistancia = cm;
  
  // Si el nivel esta por debajo del Minimo enciente la bomba hasta que alcamce el maximo
  if (NivelxDistancia > Minimo) {
    do {
    Serial.println("Reponer nivel de cisterna");
    int cm = ping(TriggerPin, EchoPin); // Se mide la distancia al sensor en cm, que es el nivel
    int imprimeDistancia(int cm);
    NivelxDistancia = cm;
    void encenderBomba(int BombaPin);
    delay(1000);
    } while (NivelxDistancia > Maximo);
  }
}

//Area de definicion de Funciones

// Se define la funcion "ping" para medir la distancia al sensor usando las caracteristicas del 
//sensor ultrasonico que determina el nivel
int ping(int TriggerPin, int EchoPin) { 
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  
  distanceCm = duration * 10 / 292/ 2;   //convertimos ese tiempo a distancia, en cm
  return distanceCm; //La funcion "ping" devuelve el valor distancia en cm
}
//Se define la funcion "imprimeValor" para abreviar lectura del codigo
int imprimeValor(int cm){
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println("cm");
    }

//Se define la funcion "encenderBomba"
void encenderBomba(int BombaPin){
  digitalWrite(BombaPin, HIGH); // Enciende la bomba para que se llene la cisterna
  Serial.println("Bomba Encendida");
  }
  
//Se define la funcion "apagarBomba"
void apagarBomba(int BombaPin){
  digitalWrite(BombaPin, LOW); //Apaga la bomba
  Serial.println("Bomba Apagada");
  }  
