#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include "Motor.h"


Motor m0(2);
Motor m1(3);
Motor m2(4);
Motor m3(5);
Motor m4(6);
Motor m5(8);

//SoftwareSerial bluetooth(4,3); // RX, TX

//String order = "";


void setup()
{
  m0.start();
  m1.start();
  m2.start();
  m3.start();
  m4.start();
  m5.start();

  //m0.setLatency(1500);
  m4.setLatency(400);
  m5.setLatency(400);

  Serial.begin(9600);
  //bluetooth.begin(9600);
} 


void loop() 
{
  m0.update();
  m1.update();
  m2.update();
  m3.update();
  m4.update();
  m5.update();

  //-- SoftwareSerial (BT)
/*
  bluetooth.listen();
  while( bluetooth.available()>0 )
  {
    order += bluetooth.read();
  }
  serialEvent();
  order="";
*/
}


//-- Serial

void serialEvent()
{
  String order = Serial.readString();
  Serial.println(order);

  for(int i=0 ; i<order.length() ; i+=4)
  {
    String key = order.substring(i,i+1);
    String value = order.substring(i+1,i+4);

    Serial.println( key + '.' + value );

    if(key =="A"){ m0.moveTo(value.toInt()); } // base
    if(key =="Q"){ m1.moveTo(value.toInt()); }
    if(key =="W"){ m2.moveTo(value.toInt()); }
    if(key =="E"){ m3.moveTo(value.toInt()); }
    if(key =="D"){ m4.moveTo(value.toInt()); }
    if(key =="C"){ m5.moveTo(value.toInt()); } // hand
  
    if(key =="L")
    {
      m0.setLatency( value.toInt() );
      m1.setLatency( value.toInt() );
      m2.setLatency( value.toInt() );
      m3.setLatency( value.toInt() );
     }
     
    if(key =="R")
    {
      m0.stop();
      m1.stop();
      m2.stop();
      m3.stop();
      m4.stop();
      m5.stop();
    }
  }
}


