## An Arduino robot arm

This project is related to a simple robot arm controlled with an Arduino.
A webserver is included is the project : the client side is the interface,
while the server side have the charge to get the orders from the interface
and send it to the robot arm throw the serial port.

The project also provide the sketch (aka the program) - located into the
'arduino' folder - which must be uploaded into the Arduino board.


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
 - A 6V power supply (with at minimum 2A)
 - of course, some wiring cables
