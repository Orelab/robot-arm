#include <Servo.h> 
#include "Motor.h"


/*

  Some precious readings :
  - http://paulmurraycbr.github.io/ArduinoTheOOWay.html
  - https://learn.adafruit.com/multi-tasking-the-arduino-part-1/a-classy-solution
  - http://web.maths.unsw.edu.au/~lafaye/CCM/cpp/cppobjet.htm
  - https://arduino.stackexchange.com/questions/1216

*/

Motor m0(5);
Motor m1(6);
Motor m2(7);
Motor m3(8);
Motor m4(9);
Motor m5(10);



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
} 


void loop() 
{
  m0.update();
  m1.update();
  m2.update();
  m3.update();
  m4.update();
  m5.update();
}



void serialEvent()
{
  String order = Serial.readString();

  Serial.println(order);

  for(int i=0 ; i<order.length() ; i+=4)
  {
    String key = order.substring(i,i+1);
    String value = order.substring(i+1,i+4);

    Serial.println( key + '.' + value );

    if(key =="A"){ m0.moveTo(value.toInt()); }
    if(key =="Q"){ m1.moveTo(value.toInt()); }
    if(key =="W"){ m2.moveTo(value.toInt()); }
    if(key =="E"){ m3.moveTo(value.toInt()); }
    if(key =="D"){ m4.moveTo(value.toInt()); }
    if(key =="C"){ m5.moveTo(value.toInt()); }
  
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


