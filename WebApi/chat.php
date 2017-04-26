 <?php
 /*
    You use this endpoint you must have the following:
    Valid session
    Chat ID
    [lastMessage ID]
    [newMessage]
 */
    
    require('dbConnect.php');
    
    if($_SERVER['REQUEST_METHOD'] != "POST")
	{
        $errMessage['error_message'] = 'Not a POST Request';
        echo json_encode($errMessage);
        exit();
	}
	
    if( !isset($_COOKIE['PHPSESSID']) || !isset($_POST['chatId']) )
    {
        $errMessage['error_message'] = 'Invalid POST params';
        echo json_encode($errMessage);
        exit();
    }
 
    session_start();
    
    $chatId = $_POST['chatId'];
    $query = "SELECT id1, id2 FROM openChat WHERE chatId=$chatId";
    $result = $conn->query($query);
    if($result === false || mysqli_num_rows($result) != 1)
    {
        $errMessage['errorMessage'] = 'Failed to select id from openChat';
        echo json_encode($errMessage);
        exit();
    }
    
    $chatInfo = mysqli_fetch_assoc($result);
    $userId = $_SESSION['userID'];
    
    if($userId != $chatInfo['id1'] && $userId != $chatInfo['id2'])
    {
        $errMessage['errorMessage'] = 'You are not part of this chat';
        echo json_encode($errMessage);
        exit();
    }
    
    if(!isset($_POST['lastMessageId']))
    {
        $lastMessageId = -1;
    }else
    {
        $lastMessageId = $_POST['lastMessageId'];
    }
	
	// Add new message
	if(isset($_POST['newMessage']))
	{
		$message = $_POST['newMessage'];
			
		$query = "INSERT INTO message (chatId, senderId, content) VALUES ($chatId, $userId, '$message')";
		$result = $conn->query($query);
		if($result === false)
		{
			$errMessage['errorMessage'] = "Error, failed to update db with new message (chatId, userId, message) Valued ($chatId, $userId, $message)";
			echo json_encode($errMessage);
			exit();
		}
    }
	
    $query = "SELECT senderId, content, id FROM message WHERE chatId=$chatId AND id>$lastMessageId";
    $result = $conn->query($query);
    if($result === false)
    {
        $errMessage['errorMessage'] = 'Failed to select message data';
        echo json_encode($errMessage);
        exit();
    }
	
	$messages;
	
	if(mysqli_num_rows($result) == 0)
	{
		//json_encode($messages);
		echo "No new messages";
		exit();
	}
    
    $i = 0;
    
    while( ($row = mysqli_fetch_assoc($result) ) != false)
    {
        $messages[$i] = $row;
        $i++;
        if($i > 100)
        {
            $errMessage['errorMessage'] = 'Infinite loop';
            echo json_encode($errMessage);
            exit();
        }
    }
    
    echo json_encode($messages);
	echo "    \n end";
 ?>
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
