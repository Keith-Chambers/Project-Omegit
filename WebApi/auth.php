<?php
	require('dbConnect.php');
	
	function extractSection($parseString, $seperator, $section)
	{
		
		$offset = 0;
		
		for($i = 0; $i < $section; $i++)
		{
			$offset = stripos($parseString, $seperator, $offset) + 1;
		}
		
		$stringLen = stripos($parseString, $seperator, $offset) - $offset;
		
		if($stringLen === FALSE || $stringLen < 0)
		{
			$stringLen = strlen($parseString) - $offset;
		}
		
		$result = substr($parseString, $offset, $stringLen);
		if($result === false)
		{
			echo "Failed to get substring";
			return "";
		}
		
		return $result;
	}
	
	function extractValueFromPair($parseString)
	{
		return extractSection($parseString, '=', 1);
	}
	
	function parseValue($parseString, $seperator, $section)
	{
		return extractValueFromPair(extractSection($parseString, $seperator, $section));
	}
		
	if(isset($_GET['state']) && isset($_GET['code']))
	{

		$username = parseValue($_GET["state"], ";", 0);
		$password = parseValue($_GET["state"], ";", 1);
		$emailPrefix = parseValue($_GET["state"], ";", 2);
		$emailSuffix = parseValue($_GET["state"], ";", 3);
		
		echo "Username: $username <br/>";
		echo "Password: $password <br/>";
		echo "Email Prefix: $emailPrefix <br/>";
		echo "Email Suffix: $emailSuffix <br/>";
		
		$query = "SELECT username FROM users WHERE username=\"$username\"";
		
		if(($result = $conn->query($query)) === FALSE)
		{
			echo "Failed to execute query";
			exit();
		}
		
		if(mysqli_num_rows($result) != 0)
		{
			echo "User already exists";
			exit();
		}
		
		// Get access token from google
		
		$clientId = "923343160820-tmv5d69vrmusaq67d26fteedro2r2njm.apps.googleusercontent.com";
		$clientSecret = "hpW6n0BMLlFrCoio-BaR53XA";
		$code = $_GET['code'];
		$redirectUri = "https://ditalk.xyz/auth.php";
		$grantType = "authorization_code";
		$tokenRequestString = "https://accounts.google.com/o/oauth2/token?code=$code&client_id=$clientId&client_secret=$clientSecret&redirect_uri=$redirectUri&grant_type=$grantType";
		
		
		$curl = curl_init('https://accounts.google.com/o/oauth2/token');
		$curlPostString = "code=$code&client_id=$clientId&client_secret=$clientSecret&redirect_uri=$redirectUri&grant_type=authorization_code";

		curl_setopt($curl, CURLOPT_VERBOSE, true);
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($curl, CURLOPT_POST, true);
		curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_setopt($curl, CURLOPT_POSTFIELDS, $curlPostString);
		
		$result = curl_exec($curl);
		
		curl_error($curl);
		curl_close($curl);
		
		if($result === false)
		{
			echo "cUrl failed to execute";
			exit();
		}
		
		$jsonResponse = json_decode($result, 512, JSON_BIGINT_AS_STRING);
		
		if($jsonResponse === NULL || $jsonResponse === false)
		{
			echo "Json response failed(Or NULL)";
			exit();
		}
		
		$accessToken = $jsonResponse['access_token'];
		$expiresIn = $jsonResponse['expires_in'];
		$idToken = $jsonResponse['id_token'];
		$refreshToken = $jsonResponse['refresh_token'];
		
		$header = array();
		
		$header[] = 'Authorization: Bearer ' . $accessToken;
		
		$apiCallString = 'https://www.googleapis.com/plus/v1/people/me';
		
		$curl = curl_init($apiCallString);
		
		curl_setopt($curl, CURLOPT_VERBOSE, true);
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_setopt($curl, CURLOPT_HTTPHEADER, $header);
		
		$result = curl_exec($curl);
		
		curl_error($curl);
		curl_close($curl);
		
		if($result === false)
		{
			echo "cUrl failed - Could not info from google plus api";
			exit();
		}
		
		$jsonUserData = json_decode($result, true);
		$ageData = $jsonUserData['ageRange'];
		
		$age = (((int)$ageData['max'] - (int)$ageData['min']) == 2) ? ((int)$ageData['max'] )- 1 : "-1";
		$nameData = $jsonUserData['name'];
		$fName = $nameData['givenName'];
		$lName = $nameData['familyName'];
		
		echo "First Name = $fName <br/>";
		echo "Last Name = $lName <br/>";
		echo "Age = $age <br/>";
		
		$query = "INSERT INTO users (firstname, lastname, age, username, password, status, emailPrefix, emailSuffixId, emailAddress) " . 
						"VALUES (\"$fName\", \"$lName\", $age, \"$username\", \"$password\", 1, \"$emailPrefix\", 0, \"" . $emailPrefix . $emailSuffix . "\")";
						
		
		if(($result = $conn->query($query)) === FALSE)
		{
			echo "Failed to execute query";
			exit();
		}
		
		echo "Successfully Registered! You may now log in.";
		
	}else
	{
		echo "Invalid action";
	}
	
	//end
?>