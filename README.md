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

Then, go to the project, and install the dépendencies :
```
npm install
```

Finally, install the Arduino sketch :
 - open the Arduino IDE
 - open the file robot-arm.ino
 - select the correct board (Tools > Board > Arduino/Genuino Uno)
 - select the USB port of your board (Tools > Port > /dev/....)
 - upload the program (Sketch > Upload)


 ## Let's play !

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
