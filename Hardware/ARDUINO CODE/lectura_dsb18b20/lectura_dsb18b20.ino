#include <OneWire.h>                
#include <DallasTemperature.h>
 
OneWire ourWire(14);                //Se establece el pin 2  como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

void setup() {
delay(1000);
Serial.begin(115200);
 pinMode(25,OUTPUT);
  digitalWrite(25,HIGH);
sensors.begin();   //Se inicia el sensor
}
 
void loop() {
 
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

Serial.print("Temperatura= ");
Serial.print(temp);
Serial.println(" C");
delay(100);                     
}
