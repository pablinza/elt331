/*  Practica de uso para un LCD
 * Se Conectara segun lo siguiente:
 * LCD VSS pin 1 a GND
 * LCD VCC pin 2 a 5V
 * LCD VO  pin 3 a Potenciometro 10K
 * LCD RS  pin 4 a Arduino pin 12
 * LCD RW  pin 5 a GND
 * LCD EN  pin 6 a Arduino pin 11
 * LCD D4  pin 11 a Arduino pin 5
 * LCD D5  pin 12 a Arduino pin 4
 * LCD D6  pin 13 a Arduino pin 3
 * LCD D7  pin 14 a Arduino pin 2
*/
#include <LiquidCrystal.h>
LiquidCrystal mylcd(12, 11, 5, 4, 3, 2); //Define el objeto para el LCD
int seco = 0, minu = 0;
void setup() 
{
  mylcd.begin(16, 2); //Inicializa el LCD tipo 16 columnas x 2 lineas
  mylcd.print("  **[U.E.B]**");
}
void loop() 
{
  mylcd.setCursor(5, 1); //Posicion Columna 6 , linea 2
  mylcd.print(minu);  //Imprime el minuto
  mylcd.print(':');  
  mylcd.print(seco);  //Imprime el segundo
  delay(1000);  //Retardo de 1 segundo
  seco++;
  if(seco > 59)
  {
    minu ++;
    seco = 0;
  }
}

