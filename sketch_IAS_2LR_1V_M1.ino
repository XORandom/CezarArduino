#include <SoftwareSerial.h>

void setup() {
  //#define txPin 1
  //#define rxPin 0
  
  Serial.begin(9600);//скорость в бодах
 
}

void loop() {
    String str=Serial.readString();//Строка, что принимает от ПК
    char strC[20];//Массив с которым будем работать, шифровать
    char encStr[20]; //зашифрованная строка
    
    str.toCharArray(strC, 10); //Преобразуем строку в массив
    
    uint8_t shift = 3; //Шифр Цезаря
    uint8_t strNmbChar = 65, endNmbChar = 90;
    int i=0;
    
  while (strC[i] != '\0')
  {
    if (strC[i] > (endNmbChar - shift)) 
      encStr[i] = ((strC[i] + shift - 1) - (endNmbChar - strNmbChar));
    else 
      encStr[i] = strC[i] + shift;
    
    Serial.print(encStr[i]);
    i++;
  }
  
delay(5000);

}
