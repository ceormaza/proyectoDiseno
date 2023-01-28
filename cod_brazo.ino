#include <Servo.h>
#include <SoftwareSerial.h>

Servo pulgar_mot;
Servo indice_mot;
Servo medio_mot;
Servo anular_mot;
Servo menique_mot;
Servo codo_mot;
int angulo_dedos;
int angulo_codo;
SoftwareSerial hc05(2, 4); // RX, TX

void setup() {
  pulgar_mot.attach(11);
  indice_mot.attach(10);
  medio_mot.attach(9);
  anular_mot.attach(6);
  menique_mot.attach(5);
  codo_mot.attach(3);
  hc05.begin(9600);
  hc05.print("AT+NAME=Brazo"); // nombre del dispositivo
  delay(1000);
  hc05.print("AT+ROLE=0"); // configura el dispositivo como Slave
  delay(1000);
  hc05.print("AT+CMODE=1"); // habilita la conexión automática
  delay(1000);
  hc05.print("AT+INIT"); // inicia la conexión
  delay(1000);
}

void loop() {
  if (hc05.available() >= 2) {
    angulo_dedos = hc05.read();
    angulo_codo = hc05.read();
    pulgar_mot.write(angulo_dedos);
    indice_mot.write(angulo.dedos); 
		medio_mot.write(angulo_dedos); 
		anular_mot.write(angulo_dedos); 
		menique_mot.write(angulo_dedos); 
		codo_mot.write(angulo_codo); 
		delay(15); 
	}
} 