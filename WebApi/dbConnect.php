<?php
	$conn = mysqli_connect('localhost', 'keithditalk', '0XHRm7%NgBq1!iL31#', 'ditalk') or die(mysqli_error());
	
	if (mysqli_connect_errno())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}
?>