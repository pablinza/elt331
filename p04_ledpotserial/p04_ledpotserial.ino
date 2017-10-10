/*
 * Practica 4. Manejo del puerto Serial y conversion ADC
 * Enviar por puerto serie el valor de conversión cada segundo, si el voltaje 
 * es menor a 1V activar led Rojo, si es mayor a 4V activar azul.
*/
const int ledR = 9;
const int ledA = 11;
int valoradc;
void setup()
{
  Serial.begin(9600); //Configura el Serial Port 9600bps
  pinMode(9, OUTPUT); //Salida led Rojo
  pinMode(11, OUTPUT); //Salida led Azul
}

void loop()
{
  valoradc = analogRead(A0); //Lectura del Pot 10k
  valoradc = map(valoradc, 0 , 1023, 0, 50); //Mapeo
  if(valoradc > 40)  //Si valor mayo a 4V
    digitalWrite(ledA, HIGH); //Activa led Azul
  else
    digitalWrite(ledA, LOW);
  if(valoradc < 10)  //Si valor menor a 1V
    digitalWrite(ledR, HIGH); //Activa el led Rojo
  else 
    digitalWrite(ledR, LOW);
  Serial.print("Valor ADC:"); 
  Serial.print(valoradc); //Envia la conversion ADC por el puerto
  Serial.println();
  delay(1000);  //Retardo de 1segundo
}

