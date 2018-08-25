#include <Servo.h> 


Servo servos[6] = {};
int latency = 50;



void setup() 
{
  Serial.begin(9600);
} 


void loop() 
{
}


void serialEvent()
{
  String order = Serial.readString();

  //Serial.println(order);

  on();

  for(int i=0 ; i<order.length() ; i+=4)
  {
    String key = order.substring(i,i+1);
    String value = order.substring(i+1,i+4);

    //Serial.println( key + '.' + value );

    if(key =="A"){ move(0, value.toInt()); }
    if(key =="Q"){ move(1, value.toInt()); }
    if(key =="W"){ move(2, value.toInt()); }
    if(key =="E"){ move(3, value.toInt()); }
    if(key =="D"){ move(4, value.toInt()); }
    if(key =="C"){ move(5, value.toInt()); }
  
    if(key =="L"){ latency = value.toInt(); }
    if(key =="R"){ off(); }
  }
  



}




void move(int motor, int destination)
{
  //servos[motor].write(destination);
  //return;
  
  int origin = servos[motor].read();

  if(origin<destination)
  {
    for( int i=origin ; i<destination ; i+=1 )
    {
      servos[motor].write(i);
      delay(latency);
    }
  }
  
  if(origin>destination)
  {
    for( int i=origin ; i>destination ; i-=1 )
    {
      servos[motor].write(i);
      delay(latency);
    }
  }
  
  
}


void on()
{
  servos[0].attach(5);
  servos[1].attach(6);
  servos[2].attach(7);
  servos[3].attach(8);
  servos[4].attach(9);
  servos[5].attach(10);
}


void off()
{
  servos[0].detach();
  servos[1].detach();
  servos[2].detach();
  servos[3].detach();
  servos[4].detach();
  servos[5].detach();
}
