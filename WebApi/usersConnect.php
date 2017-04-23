 <?php 

    function findOpenChatRequest()
    {
    
        global $conn;
    
        //TODO: Don't just ignore expiration date
        $query = 'SELECT * FROM openChatRequests WHERE id2 IS NULL AND chatId IS NULL';
        $result = $conn->query($query);
        
        if(mysqli_num_rows($result) == 0)
		{
			//echo "Failed to find any openRequests";
			return false;
		}
		
		$chatClientData = mysqli_fetch_assoc($result);
		$chatClientID = $chatClientData['id1'];
		
		if($chatClientID == NULL)
		{
            // TODO: Remove this if using a bool return value
			$errMessage['errorMessage'] = 'Invalid chat client info retrieved from database';
            echo json_encode($errMessage);
            return false;
		}
		
		$userId = $_SESSION['userID'];
		
		$query = "INSERT INTO openChat (id1, id2) VALUES ($chatClientID, $userId)";
		$result = $conn->query($query);
		
		if($result === false)
		{ 
			$errMessage['errorMessage'] = 'Failed to insert into openChat';
            echo json_encode($errMessage);
            return false;
        }
         
        $query = "SELECT chatId FROM openChat WHERE id1=$chatClientID AND id2=$userId";
        $result = $conn->query($query);
        
        if($result === false)
        {
			$errMessage['errorMessage'] = 'Failed to select chatId';
            echo json_encode($errMessage);
            return false;
        }   
        
        if(mysqli_num_rows($result) == 0)
		{
			$errMessage['errorMessage'] = 'Failed to get chat ID';
            echo json_encode($errMessage);
			return false;
		}
            
        $openChatAssoc = mysqli_fetch_assoc($result);
        $chatId = $openChatAssoc['chatId'];
        
        if($chatId == null)
        {
			$errMessage['errorMessage'] = 'Chat ID is null';
            echo json_encode($errMessage);
            return false;
		}
		$query = "UPDATE openChatRequests SET id2=$userId, chatId=$chatId WHERE id1=$chatClientID";
		
		if($conn->query($query) === false)
        {
			$errMessage['errorMessage'] = 'Failed to claim open chat connection';
            echo json_encode($errMessage);
            return false;
        }
        
        $chatInfo['chatId'] = $chatId;
        
        $query = "SELECT username, id FROM users WHERE id=$chatClientID";
        $result = $conn->query($query);
        if($result === false || mysqli_num_rows($result) == 0)
        {
			$errMessage['errorMessage'] = 'Failed to get chat partners username';
            echo json_encode($errMessage);
            return false;
        }
        
        $chatPartnerInfo = mysqli_fetch_assoc($result);
        $chatInfo['partnerUsername'] = $chatPartnerInfo["username"];
        $chatInfo['partnerId'] = $chatPartnerInfo["id"];
        
        echo json_encode($chatInfo);
        exit();
    }
    
    function createOpenChatRequest()
    {
        global $conn;
        $userId = $_SESSION['userID'];
        // TODO: Don't ignore expiration date
        $query = "INSERT INTO openChatRequests (id1) VALUES ($userId)";
        
        $result = $conn->query($query);
        
        if($result === false)
		{
			$errMessage['errorMessage'] = 'Failed to create an openChatRequest';
			echo json_encode($errMessage);
            return false;
		}
		
        return true;
    }
    
    function pollOpenChatRequest()
    {
        global $conn;
        $userId = $_SESSION['userID'];
        
        $query = "SELECT id2, chatId FROM openChatRequests WHERE id1=$userId AND id2 IS NOT NULL AND chatId IS NOT NULL";
        
        for($i = 0; $i < 10; $i++)
        {
            $result = $conn->query($query);
            if($result === false)
            {
				$errMessage['errorMessage'] = 'Failed to query database for connection request update';
				echo json_encode($errMessage);
                break;
            }
            
            if(mysqli_num_rows($result) == 0)
            {
                sleep(1);
                continue;
            }
            
            $chatRequestData = mysqli_fetch_assoc($result);
            $partnerId = $chatRequestData['id2'];
 
            $query = "SELECT username FROM users WHERE id=$partnerId";
            $result = $conn->query($query);
            if($result === false || mysqli_num_rows($result) == 0)
            {
                $errMessage['errorMessage'] = 'Failed to get partners username';
                echo json_encode($errMessage);
				
				$query = "DELETE FROM openChatRequests WHERE id1=$userId";
				if($conn->query($query) === false)
				{
					echo "Warning: Failed to delete chat connection request from database</br>";
				}
			
                exit();
            }
            
            $chatPartnerInfo = mysqli_fetch_assoc($result);
            $chatInfo['partnerUsername'] = $chatPartnerInfo['username'];
            $chatInfo['partnerId'] = $partnerId;
            $chatInfo['chatId'] = $chatRequestData['chatId'];
            
            echo json_encode($chatInfo);
			
			$query = "DELETE FROM openChatRequests WHERE id1=$userId";
			if($conn->query($query) === false)
			{
				echo "Warning: Failed to delete chat connection request from database</br>";
			}
			exit();
            
        }

        $errMessage['errorMessage'] = 'Request to find chat partner timed out';
        echo json_encode($errMessage);
    }
    
    require('dbConnect.php');

    if($_SERVER['REQUEST_METHOD'] != "POST")
	{
        $errMessage['error_message'] = 'Not a POST Request';
        echo json_encode($errMessage);
        exit();
	}
	
    if( !isset($_COOKIE['PHPSESSID']))
    {
        $errMessage['error_message'] = 'Invalid POST params';
        echo json_encode($errMessage);
        exit();
    }
    
    session_start();
    
    if(findOpenChatRequest() === false)
    {
        createOpenChatRequest();
        pollOpenChatRequest();
    }
?>
