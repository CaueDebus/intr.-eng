byte rows[] = {13,12,11,10};
byte columns[] = {9,8,7,6};

char getKey(){
  char keys[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
  };
  
  char k = '\0';
  
  for (int r=0; r<4; r++){
    digitalWrite(rows[r], LOW);
    
    for (int c=0; c<4; c++){
      if (digitalRead(columns[c]) == LOW){
        k = keys[r][c];
        break;
      }
    }
    
    digitalWrite(rows[r], HIGH);
    
    if (k) {
      break;
    }
  }
  
  return k;
}

char getKeyOnce(){
  static char lastVal = '\0';
  static unsigned long m = 0;
  char val = getKey();
  if (lastVal != val && millis() > (m+100) ) { //M+100 -->DEBOUNCING 100ms
    lastVal = val;
    m = millis();
    
    return lastVal;
  } 
  return '\0';
}

void setup() {
  for (int i=0; i<4; i++){
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], INPUT_PULLUP);
    
    digitalWrite(rows[i], HIGH);
  }
  
  Serial.begin(9600);
}

void loop(){
  
  char k = getKeyOnce();
  if (k) {
    Serial.println(k);
  }
  
  delay(10); //apenas para o simulador. 
}
