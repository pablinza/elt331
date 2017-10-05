/*
 *  Practica 3 para prueba de los puertos digitales
 *  El circuito tiene 8 diodoes led conectados y, se 
 *  activa un led por vez haciendo un barrido en 
 *  sentido horario y antihorario de acuerdo a dos
 *  pulsadores SW. 
 */
const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;
const int led5 = 10;
const int led6 = 11;
const int led7 = 12;
const int led8 = 13;
const int sw1 = 14;
const int sw2 = 15;
byte val = B00000001;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP); 
}
void loop()
{
   if(digitalRead(sw1) == LOW)
   {
     val = val << 1;
     if(val == 0)
     {
       val = B00000001;
     }
   }
   if(digitalRead(sw2) == LOW)
   {
     val = val >> 1;
     if(val == 0)
     {
       val = B10000000;
     }
   }
   writeLEDS(val);
   delay(100);    
}
void writeLEDS(byte leds)
{
  digitalWrite(led1, bitRead(leds, 0));
  digitalWrite(led2, bitRead(leds, 1));
  digitalWrite(led3, bitRead(leds, 2));
  digitalWrite(led4, bitRead(leds, 3));
  digitalWrite(led5, bitRead(leds, 4));
  digitalWrite(led6, bitRead(leds, 5));
  digitalWrite(led7, bitRead(leds, 6));
  digitalWrite(led8, bitRead(leds, 7));
}
