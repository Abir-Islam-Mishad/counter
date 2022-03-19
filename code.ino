#include <Wire.h> 
#include <Servo.h>       //servo
#include <LiquidCrystal_I2C.h>
#include "TMRpcm.h"
#include "SPI.h"
#include "SD.h"


LiquidCrystal_I2C lcd(0x27,16,2);
Servo counter1;     //servo01
Servo counter2;      //servo02
#define SD_ChipSelectPin 2
TMRpcm tmrpcm;


#define RT0 10000   
#define B 3977     
float pin=A6;
#define VCC 5    
#define R 10000 
float RT, VR, ln, Temp, T0, Read;

int buzzer = 4;



void setup(){
  
  lcd.init();
  lcd.backlight(); 
  lcd.setCursor(0,0);
  lcd.print("Devise is Working");
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;
  counter1.attach(3);            //servo1
  counter1.attach(5);            //servo2
  pinMode(buzzer,OUTPUT); 
  pinMode(A6,INPUT);
  T0 = 25 + 273.15;

 if (!SD.begin(SD_ChipSelectPin)) {
 Serial.println("SD fail");
 return;
 }
 
}

void loop(){ 
 
  

 int sensorValue  = analogRead(A0);
 int sensorValue1 = analogRead(A1);
 int sensorValue2 = analogRead(A2);
 int sensorValue3 = analogRead(A3);




//case01
if(sensorValue>1000){

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring Temp..");
tmrpcm.setVolume(5);
tmrpcm.play("1.wav");
Serial.println("ok");
delay(5000);

 tune();


  Read = analogRead(A6);             
  Read = (5.00 / 1023.00) * Read;      
  VR = VCC - Read;
  RT = Read / (VR / R);               
  ln = log(RT / RT0);
  Temp = (1 / ((ln / B) + (1 / T0))); 
  Temp = Temp - 273.15;               
  Serial.print("Temperature:");
  Serial.print("\t");
  Serial.print(Temp);    
  Serial.print("C\t\t");
  Serial.print(Temp + 273.15);    
  Serial.print("K\t\t");
  Serial.print((Temp * 1.8) + 32 + 6);   
  Serial.println("F");

  
  lcd.setCursor(0,1);
  lcd.print("Temp:  ");
  lcd.print((Temp * 1.8) + 32 + 6);
  delay(1000);
  lcd.clear();
  
//overload
if(((Temp * 1.8) + 32 + 5.8)>=200){



digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);

counter1.write(180);        //servo
delay(500);
counter1.write(90);

tmrpcm.setVolume(5);
tmrpcm.play("1.wav");
Serial.println("ok");
delay(5000);

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);
}

}

//case02
else if(sensorValue1>1000){



digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);

counter1.write(0);            //servo
delay(500);
counter1.write(90);


tmrpcm.setVolume(5);
tmrpcm.play("1.wav");
Serial.println("ok");
delay(5000);

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);
}

//case03
else if(sensorValue2>1000){

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);

counter2.write(0);             //servo
delay(500);
counter2.write(90);


tmrpcm.setVolume(5);
tmrpcm.play("1.wav");
Serial.println("ok");
delay(5000);

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);
}

//case04
else if(sensorValue3>1000){
  
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);

counter2.write(180);         //servo
delay(500);
counter2.write(90);

tmrpcm.setVolume(5);
tmrpcm.play("1.wav");
Serial.println("ok");
delay(5000);

digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(10);
}


else{
  
}

}



void tune()
{  
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000);
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
tone(buzzer,450);
delay(1000);
noTone(buzzer);
delay(2000); 
}
