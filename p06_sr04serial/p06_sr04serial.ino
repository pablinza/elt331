/*
 * Practica 6. Uso del sensor ultrasonico HC-SR04
 * Muestra el valor de distancia en cm cada segundo
 * la informacion se envia por el puerto serie
*/
const int Echo = 9;
const int Trig = 10;
long tus, dcm;
void setup()
{
  Serial.begin(9600); //Configura el Serial Port 9600bps
  pinMode(Echo, INPUT); //Entrada Echo SR04
  pinMode(Trig, OUTPUT); //Disparo salida SR04
  digitalWrite(Trig, LOW); //Nivel 0 para trigger
}

void loop()
{
  digitalWrite(Trig, HIGH);
  delay(10);
  digitalWrite(Trig, LOW);
  tus = pulseIn(Echo, HIGH);
  dcm = tus / 29 / 2; //1cm/29us
  Serial.print("dist:");
  Serial.print(dcm);
  Serial.println();
  delay(990);
}

