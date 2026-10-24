const int pinSensor = 4;     
const int pinLED1 = 8;       
const int pinLED2 = 9;       

const unsigned long tiempoEncendido = 10000; 
bool temporizadorActivo = false;
unsigned long tiempoInicio = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(pinSensor, INPUT);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
}

void loop() {
  
  if (!temporizadorActivo) {
    if (digitalRead(pinSensor) == HIGH) {
      
      
      delay(50);
      if (digitalRead(pinSensor) == HIGH) {
        
        
        delay(50);
        if (digitalRead(pinSensor) == HIGH) {
          Serial.println("¡Movimiento real validado por triple filtro!");
          
          digitalWrite(pinLED1, HIGH);
          digitalWrite(pinLED2, HIGH);
          
          temporizadorActivo = true;
          tiempoInicio = millis();
        }
      }
    }
  }

  
  if (temporizadorActivo) {
    if (millis() - tiempoInicio >= tiempoEncendido) {
      digitalWrite(pinLED1, LOW);
      digitalWrite(pinLED2, LOW);
      
      temporizadorActivo = false;
      Serial.println("Tiempo cumplido. Esperando...");
    }
  }

  delay(50);
}
