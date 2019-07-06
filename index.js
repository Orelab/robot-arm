
const express = require('express');
const app = express();

const serv = require('http');
const http = serv.Server(app);
var io = require('socket.io')(http);


//-- Serial port

const fs = require('fs');
var SerialPort = require('serialport');

var port = new SerialPort('/dev/ttyUSB1');
//var port = new SerialPort('/dev/rfcomm0');

/*

// The following code is an unsuccessfull attempt to 
// automatically discover the correct serial port...

var devices = [
	'/dev/ttyUSB0', '/dev/ttyUSB1', '/dev/ttyUSB2',
	'/dev/ttyACM0', '/dev/ttyACM1', '/dev/ttyACM2',
	'/dev/ttyACM3', '/dev/ttyACM4'
];

devices.forEach((dev) => {
	try
	{
		if( fs.existsSync(dev) )
		{
			var d = 0;
			var p = new SerialPort(dev);
			p.on('data',function(err)
			{
				if( port )
				{
					p = undefined;
				}
				if( d++ > 10 )
				{
					port = p;
					delete(p);
					console.log(dev +  ' found');
				}
			});
		}
	}
	catch(err)
	{
		console.error(err);
	}
});

*/


app.use(express.static('public'));


http.listen(3000, function()
{
  console.log('Listening orders on port 3000 !');
});


io.on('connection', function(socket)
{
	socket.on('order', function(order)
	{
		console.log( order );
		io.emit('server_order', order);

		port.write(order, function(err)
		{
			if(err)
				console.log(err.message);
			else
				console.log('ok');
		});
	});
});
 
