#include <Keypad.h>
const byte ROWS = 4; //cuatro filas
const byte COLS = 4; //cuatro columnas
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //conecta las filas a los pines 9,8,7,6
byte colPins[COLS] = {5, 4, 3, 2}; //conecta las columnas a los pines 5,4,3,2

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );//Define el objeto
String cadena; //Variable para almacenar los digitos
char val; //variable de uso temporal para leer una tecla
void setup()
{
  Serial.begin(9600);
}
  
void loop()
{
  val = keypad.getKey(); //hace lectura del teclado  
  if (val > 0) //Si val es mayor a 0, entonces existe una tecla valida
  {
    if(val == 'D')  //si la tecla 'D' es presionada
    {
      Serial.println(cadena); //muestra la cadena con los digitos ingresados 
      if(cadena == "1234")  //si la cadena es igual a 1234
        Serial.println("Correcto"); //Muestra el mensaje correcto
       cadena = ""; //inicia la cadena
    }
    else
      cadena += String(val); //agrega el valor a la cadena
  }

}
