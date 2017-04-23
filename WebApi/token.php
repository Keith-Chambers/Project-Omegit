<?php

	$postMethod = false;

	if($_SERVER['REQUEST_METHOD'] == "POST")
	{
		$postMethod = true;
		echo "Post found";
		exit();
		
	}
	echo "no post";
?>