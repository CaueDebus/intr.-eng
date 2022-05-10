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
}

void mainProgram(){
  bool active = true;
  
  while(active){
    /*aviso de funcionamento do serial*/
    Serial.println("O programa de votacao foi iniciado, o serial debugara o programa e imprimira o voto do participante");
    
    /*variáveis cpf*/
    int cpfSize = 3;
    char k[3] = {0};
    char cpf[] = {0};
    int stdCpf = 979;
    
    lcd.print("Digite seu CPF: ");
    
    for(int i=0; i<cpfSize; i++){
      
      k[i] = keypad.getKey();
      if(k[i]){
        switch(k[i]){
        case '1':
          Serial.println("keypad: 1");
		  lcd.print("1");
          cpf[i] = k[i];
          break;
        case '2':
          Serial.println("keypad: 2");
		  lcd.print("2");
          cpf[i] = k[i];
          break;
        case '3':
          Serial.println("keypad: 3");
		  lcd.print("3");
          cpf[i] = k[i];
          break;
        case '4':
          Serial.println("keypad: 4");
		  lcd.print("4");
          cpf[i] = k[i];
          break;
        case '5':
          Serial.println("keypad: 5");
		  lcd.print("5");
          cpf[i] = k[i];
          break;
        case '6':
          Serial.println("keypad: 6");
		  lcd.print("6");
          cpf[i] = k[i];
          break;
        case '7':
          Serial.println("keypad: 7");
		  lcd.print("7");
          cpf[i] = k[i];
          break;
        case '8':
          Serial.println("keypad: 8");
		  lcd.print("8");
          cpf[i] = k[i];
          break;
        case '9':
          Serial.println("keypad: 9");
		  lcd.print("9");
          cpf[i] = k[i];
          break;
        case '#':
          Serial.println("keypad: backspace");
		  i--;
          break;
    	}   
      } 
    }
    
    /*conversão do vetor de caracteres cpf[] para um inteiro*/
    
    /*variáveis*/
    int i;
    int size = sizeof(cpf)/sizeof(char);
    String s = "";
    
    for (i = 0; i < size; i++) {
        s = s + cpf[i];
    }
    
    int cpfNumber = 979;
    
    if(cpfNumber == stdCpf){
      Serial.println("cpf verificado com sucesso!");
    }
    else {
      Serial.println("cpf incorreto!");
      break;
    }
    
  }
  
  
}