/*
 * Programa practico para implementar un semaforo de dos vias
 * si se activa la alarma, la luz amarillo debe ser intermitente
 * el ajuste del tiempo se consigue enviando un mensaje por el 
 * monitor serial con la siguiente sintaxis, <va1>,<va2>,<va3>,<va4>
 * Ejemplo 100,200,300,400 tiempo 1 segundo entre cada estado
 */
const int R2led = 11;
const int A2led = 12;
const int V2led = 13;
const int R1led = 8;
const int A1led = 9;
const int V1led = 10;
const int BTpin = 2;
int cntloop = 0; //contador de bucles 10ms
int tp1 = 500, tp2 = 600, tp3 = 1100, tp4 = 1200;
int pos1, pos2, pos3;
String msg = "", msg2;
boolean msgOK = false; 
void setup() 
{
  pinMode(R2led, OUTPUT);
  pinMode(A2led, OUTPUT);
  pinMode(V2led, OUTPUT);
  pinMode(R1led, OUTPUT);
  pinMode(A1led, OUTPUT);
  pinMode(V1led, OUTPUT);
  pinMode(BTpin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  if(cntloop == 0) 
    estado1();
  if(cntloop == tp1) //primer valor cuenta de bucles
    estado2();
  if(cntloop == tp2) //segundo valor contador de bucles
    estado3();
  if(cntloop == tp3) //tercer valor contador de bucles
    estado4();
  cntloop ++;
  delay(10);
  if(cntloop >= tp4) //cuarto valor contador de bucles
    cntloop = 0;
  while(digitalRead(BTpin) == LOW) //Si se activa entrada
  {
    estado5();
    delay(100);
    estado6();
    delay(100);
  } 
  if(msgOK == true) //Si se recibe un mensaje serial
  {
    Serial.println(msg);
    msgOK = false;
    pos1 = msg.indexOf(',');
    msg2 = msg.substring(0, pos1); //extrae el primer valor del msg
    tp1 = msg2.toInt();

    pos1 ++;
    pos2 = msg.indexOf(',', pos1);
    msg2 = msg.substring(pos1, pos2); //extrae el segundo valor del msg
    tp2 = msg2.toInt();

    pos2 ++;
    pos3 = msg.indexOf(',', pos2);
    msg2 = msg.substring(pos2, pos3); //extrae el tercer valor del msg
    tp3 = msg2.toInt(); //Convierte la cadena a valor entero
    
    pos3 ++;
    msg2 = msg.substring(pos3); //extrae el cuarto valor del msg
    tp4 = msg2.toInt(); //Convierte la cadena a valor entero
  }
}
void serialEvent() //procedimiento para la recepcion de mensaje serial
{
  if(Serial.available())
  {
    msg = Serial.readString();
    msgOK = true; //bandera mansaje listo
  }
}
void estado1()
{
  digitalWrite(R1led, HIGH);
  digitalWrite(A1led, LOW);
  digitalWrite(V1led, LOW);
  digitalWrite(R2led, LOW);
  digitalWrite(A2led, LOW);
  digitalWrite(V2led, HIGH);
}
void estado2()
{
  digitalWrite(R1led, HIGH);
  digitalWrite(A1led, LOW);
  digitalWrite(V1led, LOW);
  digitalWrite(R2led, LOW);
  digitalWrite(A2led, HIGH);
  digitalWrite(V2led, LOW);
}
void estado3()
{
  digitalWrite(R1led, LOW);
  digitalWrite(A1led, LOW);
  digitalWrite(V1led, HIGH);
  digitalWrite(R2led, HIGH);
  digitalWrite(A2led, LOW);
  digitalWrite(V2led, LOW);
}
void estado4()
{
  digitalWrite(R1led, LOW);
  digitalWrite(A1led, HIGH);
  digitalWrite(V1led, LOW);
  digitalWrite(R2led, HIGH);
  digitalWrite(A2led, LOW);
  digitalWrite(V2led, LOW);
}
void estado5()
{
  digitalWrite(R1led, LOW);
  digitalWrite(A1led, LOW);
  digitalWrite(V1led, LOW);
  digitalWrite(R2led, LOW);
  digitalWrite(A2led, LOW);
  digitalWrite(V2led, LOW);
}
void estado6()
{
  digitalWrite(R1led, LOW);
  digitalWrite(A1led, HIGH);
  digitalWrite(V1led, LOW);
  digitalWrite(R2led, LOW);
  digitalWrite(A2led, HIGH);
  digitalWrite(V2led, LOW);
}

