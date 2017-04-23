<?php
		if(!isset($_COOKIE['PHPSESSID']))
		{
			echo "Failed to logout, no session ID found";
			exit();
		}
		
		session_start();
		session_destroy();
		
		unset($_COOKIE['PHPSESSID']);
		
		echo "Successfully logged out";
?>