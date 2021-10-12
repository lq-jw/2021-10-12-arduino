#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 15; //馬達旋轉速度
const int Button1_Pin = 25, Button2_Pin = 26; 

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速

  pinMode(Button1_Pin, INPUT);
  pinMode(Button2_Pin, INPUT);
}

void loop() {
  if(digitalRead(Button1_Pin) == HIGH){
      myStepper.step(60);
  }
  
  else if(digitalRead(Button2_Pin) == HIGH){
      myStepper.step(-60);
    }
}
