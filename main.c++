#include <Keypad.h>
#include <LiquidCrystal.h>
#include <WString.h>

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};
int LCDCol = 0;
int LCDRow = 0;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(LCDCol, LCDRow);
}
  
void loop(){
  mainProgram();
  lcd.clear();
}

void mainProgram(){
  /*variável de verificação de final da votação*/
  bool validator = true;
  
  /*aviso de funcionamento do serial*/
  Serial.println("O programa de votacao foi iniciado, o serial debugara o programa e imprimira o voto do participante");
  
  /*candidatos*/
  int presidente1 = 0;
  int presidente2 = 0;
  int presidente3 = 0;
  int presidente4 = 0;
  int presidente5 = 0;
  int presidenteNulo = 0;
  
  while(validator == true){
    /*início novo voto*/
    Serial.println("Nova votacao iniciada");
    
    /*variáveis cpf*/
    int cpfSize = 9;
    char k[9] = {0};
    
    LCDCol = 0;
    
   	Serial.println("cpf requisitado");
    lcd.print("Digite CPF:");
    
    ++LCDRow;
    lcd.setCursor(LCDCol, LCDRow);
    
    for(int i=0; i<cpfSize; i++){
        if(i == 8){
          k[i] = keypad.waitForKey();
          switch(k[i]){
            case '#':
              delay(200);
              Serial.println("keypad: confirma");
              break;
            case '*':
              Serial.println("keypad: backspace");
              k[i] = {0};
              k[i -1] = {0};
              i -= 2;
              lcd.setCursor(LCDCol -1,1);
              lcd.print(" ");
              LCDCol--;
              break;
            default:
              delay(200);
              Serial.println("keypad: confirma");
              break;
          }
        }
        else {
          if(i == 3)
          {
            lcd.setCursor(LCDCol, LCDRow);
            lcd.print(".");
            LCDCol++;
          }
          if(i == 6)
          {
            lcd.setCursor(LCDCol, LCDRow);
            lcd.print("-");
            LCDCol++;
          }

          k[i] = keypad.waitForKey();

          switch(k[i]){
            case '0':
              Serial.println("keypad: 0");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("0");
              LCDCol++;
              break;
            case '1':
              Serial.println("keypad: 1");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("1");
              LCDCol++;
              break;
            case '2':
              Serial.println("keypad: 2");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("2");
              LCDCol++;
              break;
            case '3':
              Serial.println("keypad: 3");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("3");
              LCDCol++;
              break;
            case '4':
              Serial.println("keypad: 4");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("4");
              LCDCol++;
              break;
            case '5':
              Serial.println("keypad: 5");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("5");
              LCDCol++;
              break;
            case '6':
              Serial.println("keypad: 6");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("6");
              LCDCol++;
              break;
            case '7':
              Serial.println("keypad: 7");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("7");
              LCDCol++;
              break;
            case '8':
              Serial.println("keypad: 8");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("8");
              LCDCol++;
              break;
            case '9':
              Serial.println("keypad: 9");
              lcd.setCursor(LCDCol, LCDRow);
              lcd.print("9");
              LCDCol++;
              break;
            case '*':
              Serial.println("keypad: backspace");
              k[i] = {0};
              k[i -1] = {0};
              i -= 2;
              lcd.setCursor(LCDCol -1,1);
              lcd.print(" ");
              LCDCol--;
              break;
        	}     
    	}
    }

    /*conversão do vetor de caracteres*/

    /*variáveis*/
    int size = sizeof(k)/sizeof(char);
    String s = "";

    for (int i = 0; i < size - 1; i++) {
      	s = s + k[i];
    }

    if(s.equals("11122244")){
        Serial.println("cpf verificado com sucesso!");
        lcd.clear();
        LCDRow=0;

        /*variáveis presidente*/
        int k1Size = 3;
        char k1[3] = {0};

        Serial.println("voto presidente requisitado");
        lcd.print("PRESIDENTE:");
      	LCDCol = 11;

        for(int i=0; i<k1Size; i++){
          if(i == 2)
          {
            k1[i] = keypad.waitForKey();
            switch(k1[i]){
              case '#':
                delay(200);
                Serial.println("keypad: confirma");
                break;
              case '*':
                Serial.println("keypad: backspace");
                k1[i] = {0};
                k1[i -1] = {0};
                i -= 2;
              	lcd.setCursor(LCDCol -1, LCDRow);
			  	lcd.print(" ");
           	  	LCDCol--;
                break;
              default:
                delay(200);
                Serial.println("keypad: confirma");
                break;
            }
          }
          else
          {
            k1[i] = keypad.waitForKey();

            switch(k1[i]){
              case '0':
                Serial.println("keypad: 0");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("0");
                LCDCol++;
                break;
              case '1':
                Serial.println("keypad: 1");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("1");
                LCDCol++;
                break;
              case '2':
                Serial.println("keypad: 2");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("2");
                LCDCol++;
                break;
              case '3':
                Serial.println("keypad: 3");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("3");
                LCDCol++;
                break;
              case '4':
                Serial.println("keypad: 4");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("4");
                LCDCol++;
                break;
              case '5':
                Serial.println("keypad: 5");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("5");
                LCDCol++;
                break;
              case '6':
                Serial.println("keypad: 6");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("6");
                LCDCol++;
                break;
              case '7':
                Serial.println("keypad: 7");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("7");
                LCDCol++;
                break;
              case '8':
                Serial.println("keypad: 8");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("8");
                LCDCol++;
                break;
              case '9':
                Serial.println("keypad: 9");
                lcd.setCursor(LCDCol, LCDRow);
                lcd.print("9");
                LCDCol++;
                break;
              case '*':
                Serial.println("keypad: backspace");
                k1[i] = {0};
                k1[i -1] = {0};
                i -= 2;
              	lcd.setCursor(LCDCol -1, LCDRow);
			  	lcd.print(" ");
           	  	LCDCol--;
                break;
            }   
          }
        }

        /*conversão do vetor de caracteres*/

        /*variáveis*/
        int size1 = sizeof(k1)/sizeof(char);
        String s1 = "";

        for (int i = 0; i < size1 -1; i++) {
            s1 = s1 + k1[i];
        }

        Serial.println("voto para presidente computado");
      
        lcd.clear();
        lcd.print("Votos enviados!");
      
      	if(s1.equals("10"))
      	{
        	  Serial.println("voto para presidente: pipoca");
          	presidente1++;
      	}
      	else if(s1.equals("21"))
        {
          	Serial.println("voto para presidente: claudio");
          	presidente2++;
        }
      	else if(s1.equals("32"))
        {
          	Serial.println("voto para presidente: cleber");
          	presidente3++;
        }
      	else if(s1.equals("43"))
        {
          	Serial.println("voto para presidente: mauricio");
          	presidente4++;
        }
      	else if(s1.equals("54"))
        {
          	Serial.println("voto para presidente: jhonathan");
          	presidente5++;
        }
      	else
        {
          	Serial.println("voto para presidente: nulo");
          	presidenteNulo++;
        }
        
      	delay(3000);
      	lcd.clear();
    }
    else if(s.equals("99999999")){
      	Serial.println("Votacao finalizada");
      	Serial.println("resultado:");
      	Serial.println("");
        lcd.clear();
      	break;
    }
    else {
        Serial.println("cpf incorreto!");
        lcd.clear();
        lcd.print("Cpf invalido!");
        delay(3000);
      	lcd.clear();
        break;
    }
  }
  
  /*resultado da votação*/
  
  Serial.print("Votos para presidente pipoca: ");
  Serial.println(presidente1);
  Serial.print("Votos para presidente claudio: ");
  Serial.println(presidente2);
  Serial.print("Votos para presidente cleber: ");
  Serial.println(presidente3);
  Serial.print("Votos para presidente mauricio: ");
  Serial.println(presidente4);
  Serial.print("Votos para presidente jhonathan: ");
  Serial.println(presidente5);
  Serial.print("Votos para presidente nulo: ");
  Serial.println(presidenteNulo);
  
  Serial.println("");
  
  delay(5000);
}