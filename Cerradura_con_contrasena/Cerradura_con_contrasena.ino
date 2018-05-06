

//Diego Vargas Gonzalez

   //Codigo compatible con Arduino Uno


   #include <Keypad.h>
   #include <LiquidCrystal.h>
   #include <Servo.h>

  Servo servo1;
  int puerto_servo=12; //pin del servo o cerradura
  int boton_1=13; //pin donde se conecta el boton
  int contA=0;
  int contB=0;
  int longitud=0;
  String palabra;

  const byte ROWS = 4; //four rows+
  const byte COLS = 4; //three columns
  char hexakeys[ROWS][COLS]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
  };
  
  byte colPins[COLS] = {8,9,10,11 }; // 1 2 3 4
  byte rowPins[ROWS] = {15,16,17,18}; //A B C D
                      // A1, A2, A3, A4


 Keypad customKeypad = Keypad( makeKeymap(hexakeys),rowPins,colPins,ROWS,COLS);
  
 LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //los pines que se usan para el display
  
  void setup()
  {
    for(int a=15;a<=18;a++){  //esto es para convertir los pines analogicos en digitales
      pinMode(a,INPUT);
     digitalWrite(a,HIGH);
    
    }
  
     pinMode(boton_1,INPUT);
     digitalWrite(boton_1,LOW);
     servo1.attach(puerto_servo);       
                       
    Serial.begin(9600); 
    lcd.print("Clave->");


   
  }
  
  void loop()

  {
      servo1.write(0);
      char key = customKeypad.getKey();
      
    if(digitalRead(boton_1)==HIGH)
      {
        lcd.clear();
        servo1.write(180);
        lcd.print("-----Abierto-----");
        delay(1000);
        lcd.clear();
        lcd.print("Clave->");
        
        
        
        
       }

      if(key)
      {
       
      palabra+=key;      
      longitud=palabra.length();
      lcd.print("*");
          if(longitud>=5)
          {
            verifica_contrasena(palabra);
          }
      
      }
  }

  
  void verifica_contrasena(String pal)
  {

    if(pal.equals("D1000"))
    {
      lcd.clear();
      lcd.print("Acceso Correcto");
      servo1.write(180);
      palabra="";
      delay(5000);
      lcd.clear();
      lcd.print("Clave->");
    }
    else
    {
      lcd.clear();
      lcd.print("Clave incorrecta");
      palabra="";
      delay(2000);
      lcd.clear();
      lcd.print("Clave->");
    }
  }

