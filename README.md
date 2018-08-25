## An Arduino robot arm

This project is related to a simple robot arm controlled with an Arduino.
A webserver is included is the project : the client side is the interface,
while the server side have the charge to get the orders from the interface
and send it to the robot arm throw the serial port.

The project also provide the sketch (aka the program) - located into the
'arduino' folder - which must be uploaded into the Arduino board.

![An Arduino robot arm](/IMG_20180820_143853.resized.jpg)

### Installation

You should have installed the Node Package Manager to install the required
dependencies of the webserver, and the Arduino Software IDE (whatever the
version).

Then, go to the project, and install the dependencies :
```
npm install
```

You have to configure manually the serial port the webserver will control.
Change it in the file index.js, and configure the port here :
```
var port = new SerialPort('xxxx');
```

Finally, install the Arduino sketch :
 - open the Arduino IDE
 - open the file robot-arm.ino
 - select the correct board (Tools > Board > Arduino/Genuino Uno)
 - select the USB port of your board (Tools > Port > /dev/xxxx)
 - upload the program (Sketch > Upload)


### Let's play !

Launch the webserver
```
cd robot-arm/
node index.js
```
Plug the Arduino to your computer and the power supply to the arm.

Visit the following url :
```
http://localhost:3000
```


### Material list

 - a robot arm !

You can find the robot arm presented in the  previous photo in China for
a low price, or you could print one. A good one seem to be available here :

https://create.arduino.cc/projecthub/danny-van-den-heuvel/6dof-robotic-arm-50eab6

 - 6 good servos
The MG996R seems to be strong enough for your arm to be able to run, 
considering the weight of the total parts, but a stronger one should be ideal
in the case of the two ones which are at the base of the arm.

 - An Arduino/Genuino Uno
 - A 5~7V power supply (with at least 2A)
 - some wiring cables
 - and of course : patience, curiosity and temerity !


### Protocol

To make the interface (NodeJS webserver) communicate with the robot arm
(Arduino sketch), we had to think about a simple protocol. It simply
consists in a string, which is formed as follow :

- The first character is a capital letter which represent a servo or 
an action. Here is the list, sorted by servos from bottom to top of 
the arm, then the actions :
  - A : base servo (the one which turns the whole arm)
  - Q : bottom servo
  - W : middle servo
  - E : top servo
  - D : wrist (the servo which turn the wrist)
  - C : hand (the one which open and close the hand)

  - L : latency (increase this value, decrease the arm speed)
  - R : Release (or Repos in french), stops the Servos

- The next three characters are a number representing the servo position,
generally from 0 to 180, or the latency in milliseconds (for the action 
Latency of course). it is useless if the action is Release, but it remains 
necessary to give something (usually 000) as the next characters should be 
shifted and unreadable.

 #### Example

 The code 'Q028W004E012' will make the arm do the following stuff :

  - The bottom servo (Q) moves to position 28
  - The middle servo (W) moves to position 4
  - The top servo (E) moves to position 12


 #### Improvements to come

 I plan to add in the protocol the possibility to configure the notion of
 time. For now, the position are set one by one, and I'd like to be able
 to move each servo at the same time, so the arm should move smoother.