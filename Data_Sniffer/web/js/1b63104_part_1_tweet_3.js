function auto_reload(){
    $('body').trigger('hover');
    setTimeout(function(){
	auto_reload();
    }, 2000);
}

$('body').ready(function(){
    $('body').on('click', function(){
	$aff = $('div.total').text();
	console.log($aff);
    });
    $('body').on('hover', function(){
	$.ajax({
	    type: 'get',
	    url: 'http://163.5.245.71/app_dev.php/act/' + $('div.total').text(),
	    success: function(data){
		if(data.index > $('div.total').text())
		{
		    $('div.total').text(data.index);
		    $('.ClassementTweet table tr:first td').text('TOTAL TWEETS: ' + data.index);
		    $('table.LesTweets').prepend('<tr><td class="Tweet"><img src="' + data.tweet[0].picture + '"><a href="http://twitter.com/' + data.tweet[0].screen_name + '">' + data.tweet[0].screen_name + '</a>' + data.tweet[0].tweet + '</td></tr>');
		}
	    },
	    error: function(data){
		console.log('ERROR');
	    }
	});
    });
    auto_reload();
});
