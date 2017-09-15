/*
 *  Practica 1 para prueba de los puertos digitales
 *  El circuito tiene 1 pulsador y un diodo led, el led se activara solo 
 *  cuando se presione el pulsador. 
 */
const int led = 2; //define el led con el puerto P2
const int but = 7; //define el boton con el puerto P6
void setup()
{
  pinMode(led, OUTPUT); //puerto led configurado como salida
  pinMode(but, INPUT_PULLUP);//puerto boton configurado como entrada
}
void loop()
{
  if(digitalRead(but) == LOW) //si el boton es presionado
  {
    digitalWrite(led, HIGH); //activa el led
  }
  else
  {
    digitalWrite(led, LOW); //desactiva el led
  }
}

