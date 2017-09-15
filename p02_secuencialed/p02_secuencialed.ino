/*
 *  Practica 2 para prueba de los puertos digitales
 *  El circuito tiene 8 diodoes led conectados, se 
 *  activa un led por vez haciendo un barrido en 
 *  sentido horario y antihorario. 
 */
const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;
const int led5 = 10;
const int led6 = 11;
const int led7 = 12;
const int led8 = 13;
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
}
void loop()
{
  der(); //sencuencia en sentido horario
  izq(); //secuencia en sentido anti
}

void der() //procedimiento en sentido horario
{
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(100);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW);
  delay(100);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW);
  delay(100);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, LOW);
  delay(100);
  digitalWrite(led8, HIGH);
}
void izq() //procedimiento en sentido anti
{
  digitalWrite(led8, LOW);
  delay(100);
  digitalWrite(led8, HIGH);
  digitalWrite(led7, LOW);
  delay(100);
  digitalWrite(led7, HIGH);
  digitalWrite(led6, LOW);
  delay(100);
  digitalWrite(led6, HIGH);
  digitalWrite(led5, LOW);
  delay(100);
  digitalWrite(led5, HIGH);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led4, HIGH);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
}
