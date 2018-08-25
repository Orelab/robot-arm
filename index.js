
const express = require('express');
const app = express();

const serv = require('http');
const http = serv.Server(app);
var io = require('socket.io')(http);

var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyUSB0');



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
 
