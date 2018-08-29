
$(document).ready(function()
{
	var socket = io();


	var orders = {
		'base'   :'A',
		'bottom' :'Q',
		'middle' :'W',
		'top'    :'E',
		'wrist'  :'D',
		'hand'   :'C',
		'latency':'L'
	};



	/*
		Engines
	*/
	$('input,select').on('input', function()	// on change || on input
	{
		var key = orders[ $(this).attr('name') ];
		var value = normalize( $(this).val() );

		order(key+value);
	});



	/*
		Predefined positions
	*/
	$('#predefined button:not(#log)').on('click', function(){
		order( $(this).data('order') );
	});



	/*
		Log positions
	*/
	$('#log').on('click', function(){
		var data = $('#engines').serializeArray();

		for(var i in data)
		{
			data[i]['key'] = orders[data[i]['name']];
			console.log( data[i] );
		}
	});



	/*
		Interface update by Socket.io
	*/
	socket.on('server_order', function(o)
	{
		var name = {
			'A': 'base',
			'Q': 'bottom',
			'W': 'middle',
			'E': 'top',
			'D': 'wrist',
			'C': 'hand',
			'L': 'latency' 	
		};

		for( var i=0 ; i<o.length ; i+=4)
		{
			var key = o.substring(i,i+1);
			var value = o.substring(i+1,i+4);

			$('*[name=' + name[key] + ']').val(value);
		}

	});



	function normalize( val )
	{
		// n = number of ZERO to add
		var n = 3 - val.toString().length;

		// concat the right number of ZERO to val
		return '0'.repeat(n) + val;
	}


	function order( o )
	{
		socket.emit('order', o);
	}
});

