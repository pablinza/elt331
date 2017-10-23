#include <Servo.h>
const int SERVOpin = 9;
Servo Motor1;	//Declara el objeto Servo con el nombre Motor1
unsigned int val;
void setup() 
{
  Serial.begin(9600);
  Motor1.attach(SERVOpin);	//Asigna el pin 9 al Servo Motor1
}

void loop() 
{
  val = analogRead(0);	//Realiza una lectura analogica del pot
  val = map(val, 0, 1023, 10, 170); //mapea los valores adc al rango del servo
  Motor1.write(val); //Mueve el servo un angulo 0-180
  delay(15);	//retardo
}
