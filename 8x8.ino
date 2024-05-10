#define ROW1 10
#define ROW2 9
#define ROW3 5
#define ROW4 A2
#define ROW5 4
#define ROW6 A0
#define ROW7 13
#define ROW8 7

#define COL1 A1
#define COL2 12
#define COL3 A3
#define COL4 11
#define COL5 6
#define COL6 A4
#define COL7 8
#define COL8 3

#define BUTTON 2

const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};



byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

byte circle[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}};

byte squaree[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0}};

byte heart[8][8] = {
  {1,0,0,1,1,0,0,1},
  {0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1}};

byte previousState=1, presentState=1, patternNumber=0;


void setup() {
  // put your setup code here, to run once:
  for (byte i = 0; i <= sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i <= sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }  
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
   presentState= digitalRead(BUTTON);
  if(presentState == 0 && previousState == 1){
    patternNumber++;
    if(patternNumber > 2){
      patternNumber = 0;
    }
  }
   Serial.println(presentState);
  // Serial.println(patternNumber);
  if(patternNumber == 0){ showPattern(circle);
  // for(int i=0;i<8;i++){
  //   for(int j=0;j<8;j++){
  //     // Serial.print(circle[i][j]);
  //     // Serial.print("  ");
  //   }
  //   // Serial.println("");

  // }
  
  }
  else if(patternNumber == 1) showPattern(squaree);
  else showPattern(heart);
  previousState = presentState;
  delay(2);



  // print out the state of the button:
 
 
}

void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], scan[i][j]);
      digitalWrite(col[j], matrix[i][j]);  
    }
        for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], LOW);
      digitalWrite(col[j], HIGH); 
    }
  }
}
