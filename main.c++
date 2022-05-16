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
  int governador1 = 0;
  int governador2 = 0;
  int governador3 = 0;
  int governador4 = 0;
  int governador5 = 0;
  int governadorNulo = 0;
  
  while(validator == true){
    /*início novo voto*/
    Serial.println("Nova votacao iniciada");
    
    /*variáveis cpf*/
    int cpfSize = 9;
    char k[9] = {0};
    long long stdCpf = 11122244;
    long long stdBreaker = 99999999;
    
    unsigned int govNumber = 0;
    unsigned int presNumber = 0;
    
   	Serial.println("cpf requisitado");
    lcd.print("Digite CPF:");
    
    ++LCDRow;
    lcd.setCursor (LCDCol, LCDRow);
    
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
              k[i] = {0};//eu tentei null mas o compilador não deixa;
              i--;
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
            lcd.print(".");
          }
          if(i == 6)
          {
            lcd.print("-");
          }

          k[i] = keypad.waitForKey();

          switch(k[i]){
            case '0':
              Serial.println("keypad: 0");
              lcd.print("0");
              break;
            case '1':
              Serial.println("keypad: 1");
              lcd.print("1");
              break;
            case '2':
              Serial.println("keypad: 2");
              lcd.print("2");
              break;
            case '3':
              Serial.println("keypad: 3");
              lcd.print("3");
              break;
            case '4':
              Serial.println("keypad: 4");
              lcd.print("4");
              break;
            case '5':
              Serial.println("keypad: 5");
              lcd.print("5");
              break;
            case '6':
              Serial.println("keypad: 6");
              lcd.print("6");
              break;
            case '7':
              Serial.println("keypad: 7");
              lcd.print("7");
              break;
            case '8':
              Serial.println("keypad: 8");
              lcd.print("8");
              break;
            case '9':
              Serial.println("keypad: 9");
              lcd.print("9");
              break;
            case '*':
              Serial.println("keypad: backspace");
              k[i] = {0};//eu tentei null mas o compilador não deixa;
              i--;
              break;
        	}     
    	}
    }

    /*conversão do vetor de caracteres k[] para um inteiro*/

    /*variáveis*/
    int size = sizeof(k)/sizeof(char);
    String s = "";

    for (int i = 0; i < size - 1; i++) {
        s = s + k[i];
      	Serial.println(k[i]);
      	Serial.println(s);
    }

    int cpfNumber = s.toInt();
    Serial.println(cpfNumber);

    if(11122244 == stdCpf){
        Serial.println("cpf verificado com sucesso!");
        lcd.clear();
        LCDRow=0;

        /*variáveis presidente*/
        int k1Size = 3;
        char k1[3] = {0};

        Serial.println("voto presidente requisitado");
        lcd.print("PRESIDENTE:");

        for(int i=0; i<k1Size; i++){

          k1[i] = keypad.waitForKey();

          switch(k1[i]){
            case '0':
              Serial.println("keypad: 0");
              lcd.print("0");
              break;
            case '1':
              Serial.println("keypad: 1");
              lcd.print("1");
              break;
            case '2':
              Serial.println("keypad: 2");
              lcd.print("2");
              break;
            case '3':
              Serial.println("keypad: 3");
              lcd.print("3");
              break;
            case '4':
              Serial.println("keypad: 4");
              lcd.print("4");
              break;
            case '5':
              Serial.println("keypad: 5");
              lcd.print("5");
              break;
            case '6':
              Serial.println("keypad: 6");
              lcd.print("6");
              break;
            case '7':
              Serial.println("keypad: 7");
              lcd.print("7");
              break;
            case '8':
              Serial.println("keypad: 8");
              lcd.print("8");
              break;
            case '9':
              Serial.println("keypad: 9");
              lcd.print("9");
              break;
            case '*':
              Serial.println("keypad: backspace");
              k1[i] = {0};//eu tentei null mas o compilador não deixa;
              i--;
              break;
            }   
        }

        /*conversão do vetor de caracteres k1[] para um inteiro*/

        /*variáveis*/
        int size1 = sizeof(k1)/sizeof(char);
        String s1 = "";

        for (int i = 0; i < size1; i++) {
            s1 = s1 + k1[i];
        }

        presNumber = s1.toInt();

        Serial.println("voto para presidente computado");
        lcd.clear();

        /*variáveis governador*/
        int k2Size = 3;
        char k2[3] = {0};

        Serial.println("voto governador requisitado");
        lcd.print("GOVERNADOR:");

        for(int i=0; i<k2Size; i++){

          k2[i] = keypad.waitForKey();

          switch(k2[i]){
            case '0':
              Serial.println("keypad: 0");
              lcd.print("0");
              break;
            case '1':
              Serial.println("keypad: 1");
              lcd.print("1");
              break;
            case '2':
              Serial.println("keypad: 2");
              lcd.print("2");
              break;
            case '3':
              Serial.println("keypad: 3");
              lcd.print("3");
              break;
            case '4':
              Serial.println("keypad: 4");
              lcd.print("4");
              break;
            case '5':
              Serial.println("keypad: 5");
              lcd.print("5");
              break;
            case '6':
              Serial.println("keypad: 6");
              lcd.print("6");
              break;
            case '7':
              Serial.println("keypad: 7");
              lcd.print("7");
              break;
            case '8':
              Serial.println("keypad: 8");
              lcd.print("8");
              break;
            case '9':
              Serial.println("keypad: 9");
              lcd.print("9");
              break;
            case '*':
              Serial.println("keypad: backspace");
              k2[i] = {0};//eu tentei null mas o compilador não deixa;
              i--;
              break;
            }   
        }

        /*conversão do vetor de caracteres k2[] para um inteiro*/

        /*variáveis*/
        int size2 = sizeof(k2)/sizeof(char);
        String s2 = "";

        for (int i = 0; i < size2; i++) {
            s2 = s2 + k2[i];
        }

        govNumber = s2.toInt();

        Serial.println("voto para governador computado");
        lcd.clear();
        lcd.print("Votos enviados!");

        switch(presNumber){
          case 100:
              Serial.println("voto para presidente: pipoca");
          	  presidente1++;
              break;
          case 201:
              Serial.println("voto para presidente: claudio");
          	  presidente2++;
              break;
          case 302:
              Serial.println("voto para presidente: cleber");
          	  presidente3++;
              break;
          case 403:
              Serial.println("voto para presidente: mauricio");
          	  presidente4++;
              break;
          case 504:
              Serial.println("voto para presidente: jhonathan");
          	  presidente5++;
              break;
          default:
              Serial.println("voto para presidente: nulo");
          	  presidenteNulo++;
              break;
        }
        switch(govNumber){
         case 100:
              Serial.println("voto para governador: pipoca");
          	  governador1++;
              break;
          case 201:
              Serial.println("voto para governador: claudio");
          	  governador2++;
              break;
          case 302:
              Serial.println("voto para governador: cleber");
          	  governador3++;
              break;
          case 403:
              Serial.println("voto para governador: mauricio");
          	  governador4++;
              break;
          case 504:
              Serial.println("voto para governador: jhonathan");
          	  governador5++;
              break;
          default:
              Serial.println("voto para governador: nulo");
          	  governadorNulo++;
              break;
        }
      	delay(3000);
      	lcd.clear();
    }
    else if(cpfNumber == stdBreaker){
      	Serial.println("Votacao finalizada");
      	Serial.println("resultado:");
      	Serial.println("");
    }
    else {
        Serial.println("cpf incorreto!");
        lcd.clear();
        lcd.print("Cpf invalido!");
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
  
  Serial.print("Votos para governador pipoca: ");
  Serial.println(governador1);
  Serial.print("Votos para governador claudio: ");
  Serial.println(governador2);
  Serial.print("Votos para governador cleber: ");
  Serial.println(governador3);
  Serial.print("Votos para governador mauricio: ");
  Serial.println(governador4);
  Serial.print("Votos para governador jhonathan: ");
  Serial.println(governador5);
  Serial.print("Votos para governador nulo: ");
  Serial.println(governadorNulo);
  
  Serial.println("");
  
  delay(5000);
}