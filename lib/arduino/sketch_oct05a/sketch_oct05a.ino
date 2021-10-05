#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo underservo;
Servo leftservo;
Servo rightservo;
int underangle=80;
int leftangle=35;
int rightangle=145;
int ledA=30;
int ledB=31;
int ledC=32;
int ledD=33;
int pinA=40;
int pinB=41;
int pinC=42;
int pinD=43;
int motorA=50;
int motorB=51;
int gearedmotor=10;
int leftgeared=11;
int rightgeared=12;
int x;
int y;
int z;
boolean a=true;
boolean b=true;
boolean c=true;
boolean d=true;
unsigned long time1=0;
unsigned long time2=0;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  underservo.attach(22);
  leftservo.attach(23);
  rightservo.attach(24);
  underservo.write(underangle);
  leftservo.write(leftangle);
  rightservo.write(rightangle);
  pinMode(pinA,INPUT_PULLUP);
  pinMode(pinB,INPUT_PULLUP);
  pinMode(pinC,INPUT_PULLUP);
  pinMode(pinD,INPUT_PULLUP);
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(ledC,OUTPUT);
  pinMode(ledD,OUTPUT);
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(gearedmotor,OUTPUT);
  pinMode(leftgeared,OUTPUT);
  pinMode(rightgeared,OUTPUT);
  digitalWrite(leftgeared,HIGH);
  digitalWrite(rightgeared,LOW);
  analogWrite(gearedmotor,0);
  analogWrite(motorA,0);
  analogWrite(motorB,0);
//  lcd.init();
  lcd.backlight();
}

void loop() {
  char temp = ' ';
  if(Serial1.available()){
    //Serial.write(Serial1.read());
    temp = Serial1.read();
    Serial.print(temp);
  }
  if(Serial.available()){
    Serial1.write(Serial.read());
  }
  
  if(digitalRead(pinA)==0||temp=='e'){
    digitalWrite(ledA,HIGH);
    Serial.println("reset");
    a=false;
    b=true;
    c=true;
    d=true;
    delay(1000);
    digitalWrite(ledA,LOW);
  }
  else if(digitalRead(pinB)==0||temp=='f'){
    digitalWrite(ledB,HIGH);
    Serial.println("level1");
    a=true;
    b=false;
    c=true;
    d=true;
    delay(1000);
    digitalWrite(ledB,LOW);
  }
  else if(digitalRead(pinC)==0||temp=='g'){
    digitalWrite(ledC,HIGH);
    Serial.println("level2");
    a=true;
    b=true;
    c=false;
    d=true;
    delay(1000);
    digitalWrite(ledC,LOW);
  }
  else if(digitalRead(pinD)==0||temp=='h'){
    digitalWrite(ledD,HIGH);
    Serial.println("level3");
    a=true;
    b=true;
    c=true;
    d=false;
    delay(1000);
    digitalWrite(ledD,LOW);
  }
  if(a==false){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("U I O");
    lcd.setCursor(5,1);
    lcd.print("STOP");
    while(a==false){
      analogWrite(gearedmotor,0);
      underangle=80;
      leftangle=35;
      rightangle=180-leftangle;
      underservo.write(underangle);
      leftservo.write(leftangle);
      rightservo.write(rightangle);
      analogWrite(motorA,0);
      analogWrite(motorB,0);
      if(digitalRead(pinB)==0|digitalRead(pinC)==0|digitalRead(pinD)==0||Serial1.read()=='f'||Serial1.read()=='g'||Serial1.read()=='h'){
        a=true;
      }
    }
  }
  if(b==false){
    lcd.setCursor(5,0);
    lcd.print("U I O");
    lcd.setCursor(4,1);
    lcd.print("LEVEL 1");
    analogWrite(gearedmotor,180);
    while(b==false){
      time1=millis();
      if(time1-time2>=2500){
        time2=time1;
        underangle=80;
        leftangle=40;
        rightangle=180-leftangle;
        underservo.write(underangle);
        leftservo.write(leftangle);
        rightservo.write(rightangle);
        x=130;
        analogWrite(motorA,x);
        analogWrite(motorB,x);
      }
      if(digitalRead(pinA)==0|digitalRead(pinC)==0|digitalRead(pinD)==0||Serial1.read()=='e'||Serial1.read()=='g'||Serial1.read()=='h'){
        b=true;
      }
    }
  }
  if(c==false){
    lcd.setCursor(5,0);
    lcd.print("U I O");
    lcd.setCursor(4,1);
    lcd.print("LEVEL 2");
    analogWrite(gearedmotor,220);
    while(c==false){
      time1=millis();
      if(time1-time2>=2200){
        time2=time1;
        underangle=random(75,86);
        leftangle=random(38,44);
        rightangle=180-leftangle;
        underservo.write(underangle);
        leftservo.write(leftangle);
        rightservo.write(rightangle);
        y=random(130,171);
        analogWrite(motorA,y);
        analogWrite(motorB,y);
      }
      if(digitalRead(pinA)==0|digitalRead(pinB)==0|digitalRead(pinD)==0||Serial1.read()=='e'||Serial1.read()=='f'||Serial1.read()=='h'){
        c=true;
      }
    }
  }
  if(d==false){
    lcd.setCursor(5,0);
    lcd.print("U I O");
    lcd.setCursor(4,1);
    lcd.print("LEVEL 3");
    analogWrite(gearedmotor,250);
    while(d==false){
      time1=millis();
      if(time1-time2>=2000){
        time2=time1;
        underangle=random(70,91);
        leftangle=random(35,48);
        rightangle=180-leftangle;
        underservo.write(underangle);
        leftservo.write(leftangle);
        rightservo.write(rightangle);
        z=random(130,201);
        analogWrite(motorA,z);
        analogWrite(motorB,z);
      }
      if(digitalRead(pinA)==0|digitalRead(pinB)==0|digitalRead(pinC)==0||Serial1.read()=='e'||Serial1.read()=='f'||Serial1.read()=='g'){
        d=true;
      }
    }
  }
}
