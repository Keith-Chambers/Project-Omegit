<?php
	require("dbConnect.php");

	if(!(isset($_POST['username']) && isset($_POST['password'])))
	{
		echo "Invalid request";
		exit();
	}
	
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	$query = "SELECT * from users WHERE username='$username' AND password='$password'";
	
	$result = $conn->query($query);
	if($result === false)
	{
		echo "Failed to execute query";
		exit();
	}
		
	if(mysqli_num_rows($result) == 0)
	{
		echo "Account doesn't exist";
		exit();
	}
	
	if(mysqli_num_rows($result) > 1)
	{
		echo "An error occurred";
		exit();
	}
	
	$userData = mysqli_fetch_assoc($result);
	
	session_start();
	
	$_SESSION['username'] = $username;
	$_SESSION['firstName'] = $userData['firstname'];
	$_SESSION['lastName'] = $userData['lastname'];
	$_SESSION['emailAddress'] = $userData['emailAddress'];
	$_SESSION['userID'] = $userData['id'];
	
	$sessionData['sessionID'] = session_id();
	$sessionData['username'] = $username;
	$sessionData['firstName'] = $userData['firstname'];
	$sessionData['lastName'] = $userData['lastname'];
	
	echo json_encode($sessionData);
?>