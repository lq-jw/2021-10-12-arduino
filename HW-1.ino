#include <Servo.h>  //匯入函式庫
Servo myservo;  // 建立伺服馬達控制

const int servoPin = 14;  //用常態變數設定pin腳位，與之前define方式差不多
int pos = 0;

void setup() {
  myservo.attach(servoPin);  // 將伺服馬達連接的GPIO pin連接伺服物件
  Serial.begin(115200); //設定傳輸鮑率，跟電腦傳輸資料的頻率
  pinMode(13, INPUT); //設定腳位為輸入用
}


void loop() {
  int input = analogRead(13);
  int input_map = map(input, 0, 4095, 0, 180);
  Serial.println(input_map);

 //ledcWrite(0, input_map);  //頻道0
  myservo.write(input_map); //Servo設定角度
  Serial.println(input_map);
  delay(50);

}

