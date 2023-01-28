#include <SoftwareSerial.h>

int dedos_pot = A0;
int codo_pot = A1;
int lectura_dedos;
int lectura_codo;
SoftwareSerial hc05(2, 4); // RX, TX

void setup() {
  hc05.begin(9600);
  hc05.print("AT+NAME=Joystick"); // nombre del dispositivo
  delay(1000);
  hc05.print("AT+ROLE=1"); // configura el dispositivo como Master
  delay(1000);
  hc05.print("AT+CMODE=1"); // habilita la conexi�n autom�tica
  delay(1000);
  hc05.print("AT+INIT"); // inicia la conexi�n
  delay(1000);
}

void loop() {
  lectura_dedos = map(analogRead(dedos_pot), 0, 1023, 0, 180);
  lectura_codo = map(analogRead(codo_pot), 0, 1023, 0, 180);
  hc05.write(lectura_dedos);
  hc05.write(lectura_codo);
  delay(15);
}