#define UPPERLOWER_RED 2
#define UPPERLOWER_YELLOW 3
#define UPPERLOWER_GREEN 4 //위쪽 불
/*#define LOWER_RED 22
#define LOWER_YELLOW 24
#define LOWER_GREEN 26  //아래쪽 불*/
#define RIGHTLEFT_RED 11
#define RIGHTLEFT_YELLOW 12
#define RIGHTLEFT_GREEN 13  //오른쪽 불
/*#define LEFT_RED 23
#define LEFT_YELLOW 25
#define LEFT_GREEN 27  //왼쪽 불*/
#define UD_SW 30       //위아래 스위치
#define LR_SW 32       //양옆 스위치

int interval = 5000;
unsigned long TimeUD;
unsigned long TimeLR;

void setup()  // 초기 한번 실행
{
  pinMode(UPPERLOWER_RED, OUTPUT);
  pinMode(UPPERLOWER_YELLOW, OUTPUT);
  pinMode(UPPERLOWER_GREEN, OUTPUT);
 /* pinMode(LOWER_RED, OUTPUT);
  pinMode(LOWER_YELLOW, OUTPUT);
  pinMode(LOWER_GREEN, OUTPUT);*/
  pinMode(RIGHTLEFT_RED, OUTPUT);
  pinMode(RIGHTLEFT_YELLOW, OUTPUT);
  pinMode(RIGHTLEFT_GREEN, OUTPUT);
  /*pinMode(LEFT_RED, OUTPUT);
  pinMode(LEFT_YELLOW, OUTPUT);
  pinMode(LEFT_GREEN, OUTPUT);*/
  pinMode(UD_SW, INPUT_PULLUP);
  pinMode(LR_SW, INPUT_PULLUP);
  initLeftRight();
  TimeLR = interval;
}

void loop() //반복
{
  if(digitalRead(LR_SW) == LOW && digitalRead(UPPERLOWER_GREEN) == HIGH){
    delay(3000);
    Blink_UD_LED();
    initLeftRight();
  }
  else if(digitalRead(UD_SW) == LOW && digitalRead(RIGHTLEFT_GREEN) == HIGH){
    delay(3000);
    Blink_LR_LED();
    initUpDown();
  }
  else{
    unsigned long currentTime = millis();
    
    if(currentTime > TimeUD + interval && currentTime > TimeLR + interval*2){
      
      Blink_UD_LED();
      initLeftRight(); 
    }
    else if(currentTime > TimeLR + interval && currentTime > TimeUD + interval*2){
      
      Blink_LR_LED();
      initUpDown();
    }
 }
}
 
void Blink_LR_LED(){
  digitalWrite(RIGHTLEFT_GREEN, LOW);/*  digitalWrite(LEFT_GREEN, LOW);*/
   for(int i = 0; i<10; i++){
  digitalWrite(RIGHTLEFT_YELLOW, HIGH);  /* digitalWrite(RIGHT_YELLOW, HIGH);*/
  delay(500);
  digitalWrite(RIGHTLEFT_YELLOW, LOW);  /* digitalWrite(RIGHT_YELLOW, LOW);*/
  delay(500);
 }
}

void Blink_UD_LED(){
  digitalWrite(UPPERLOWER_GREEN, LOW);  /*digitalWrite(LOWER_GREEN, LOW);*/
   for(int i = 0; i<10; i++){
  digitalWrite(UPPERLOWER_YELLOW, HIGH);   /*digitalWrite(LOWER_YELLOW, HIGH);*/
  delay(500);
  digitalWrite(UPPERLOWER_YELLOW, LOW);  /* digitalWrite(LOWER_YELLOW, LOW);*/
  delay(500);
 }
}

void initUpDown(){
  digitalWrite(UPPERLOWER_GREEN, HIGH);/* digitalWrite(LOWER_GREEN, HIGH);*/
  digitalWrite(RIGHTLEFT_RED, HIGH); /*digitalWrite(RIGHT_RED, HIGH);*/
  
  digitalWrite(UPPERLOWER_YELLOW, LOW);  /* digitalWrite(LOWER_YELLOW, LOW);*/
  digitalWrite(RIGHTLEFT_YELLOW, LOW);  /* digitalWrite(RIGHT_YELLOW, LOW);*/
  digitalWrite(UPPERLOWER_RED, LOW);  /*digitalWrite(LOWER_RED, LOW);*/
  digitalWrite(RIGHTLEFT_GREEN, LOW);  /*digitalWrite(LEFT_GREEN, LOW);*/
  TimeUD = millis();
  }
  
 void initLeftRight(){
  digitalWrite(RIGHTLEFT_GREEN, HIGH);  /*digitalWrite(LEFT_GREEN, HIGH);*/
  digitalWrite(UPPERLOWER_RED, HIGH);  /*digitalWrite(LOWER_RED, HIGH);*/

  digitalWrite(UPPERLOWER_YELLOW, LOW);   /*digitalWrite(LOWER_YELLOW, LOW);*/
  digitalWrite(RIGHTLEFT_YELLOW, LOW);   /*digitalWrite(RIGHT_YELLOW, LOW);*/
  digitalWrite(RIGHTLEFT_RED, LOW);  /*digitalWrite(RIGHT_RED, LOW);*/
  digitalWrite(UPPERLOWER_GREEN, LOW); /* digitalWrite(LOWER_GREEN, LOW);*/
  TimeLR = millis();
 }
