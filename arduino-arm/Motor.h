#ifndef MOTOR_LIB_H__
#define  MOTOR_LIB_H__

#include <Servo.h>
#include <Arduino.h>


class Motor
{
  private:
    int _pin;                       // Arduino pin
    int _position;                  // Servo position (from 0 to 180)
    bool _started;                  // Servo is attached ?
    unsigned long _latency;         // The duration of a single movement, in ms
    unsigned long _previousMillis;  // When did the movement started ?
    int _previousPos;               // From where the movement moved
    Servo _s;                       // The Servo object

  public:
    Motor( int pin )
    {
      _pin = pin;
      _started = false;
      _position = _s.read();
      _previousPos = _position;
      _previousMillis = millis();
      _latency = 1000;
      //start();
    }
  
    void start()
    {
      if(_started)
        return;
        
      Serial.println("starting motor " + _pin);
      _s.attach(_pin);
      _started = true;
    }
  
    void stop()
    {
      if(!_started)
        return;
        
      Serial.println("stopping motor " + _pin);
      _s.detach();
      _started = false;
    }

    void moveTo( int pos )
    {
      if(!_started)
        start();
      
      _previousMillis = millis();
      _previousPos = _s.read(); // _position
      _position = pos;
    }

    void setLatency( int latency )
    {
      _latency = latency;
    }

    void update()
    {
      if( millis() > _previousMillis + _latency )
      {
        return;
      }
      
      int total = _latency;
      long parcouru = millis() - _previousMillis;
      int distance = _position - _previousPos;
      int pos = ( distance * parcouru / total ) + _previousPos;
      _s.write(pos);
    }
    
};


#endif
