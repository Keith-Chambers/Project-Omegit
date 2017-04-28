# Project-Omegit


----------

## Project Overview / Description ##

Project-Omegit allows users to create accounts and chat with other registered members.
It consists of a desktop client application and a http web api. 

It requires that users create an account using a valid college email address(*Not currently implemented, any address will do). 
To register you must authenticate your account with Google's api and give the application permission to access basic account information(Full name and age).

Once logged in you are able to start a chat, which if another member is also attempting to start a chat, will connect you and that user so that you can chat via text. Otherwise the request will timeout after ~10 seconds.

## Language & Platform ##

The project makes use of C++, Qt, QML(Qt Gui language), PHP, Mysql and Json. 
It is a cross platform application that runs on Windows and Linux. The program has been tested on Linux but only with a previous version of the program, the current source code may need small changes before being built for a Linux system.

## Contributers ##

The project was developed entirely by Keith Chambers.

## What I'm most proud of ##

I'm most proud of the structure of the code in the client application and being able to authenticate and get user's information using the google+ api.

**Client Structure**

The client is structured so that all the classes are reasonable reusable, easy to read/understand and expose a simple and intuitive set of public methods and signals. 

The DitalkBackEndController class for example is built without the assumption that it is going to be used in a GUI application. It could easily be used in a CLI project, even an event driven one as it emits signals when events occur such as when the application successfully receives an acknowledgement response for a login request(I.e The user successfully logged in). The DitalkGuiLayer class contains lots of extra and obsure code that is required to expose methods and data to the front end. DitalkState and MessageThread also require that they're exposed to the frontend and this is achieved without using messy code that breaks encapsulation. This was a challanging issue that arose in the early working versions of the application before refactering the program completely.

**Google+ Api**

Getting the application to use the Google+ Api took quite a bit of time to get working as I had no experience with using web api's at all. The following steps take place to register a user and get their age and name from Google.

**1**) A get request is sent to **https://accounts.google.com/o/oauth2/auth** with the following parameters set:

1. **client_id**: This is obtained by registering your 'product' with google
2. 	**redirect_url**: The url to send the resulting access token and other context info to. Set as `https://ditalk/auth.php` which handles finalizing the registration
3. **response_type**: Set to `code` to receive information back as json
4. **scope**: Set to `openid` and `profile` to obtain access code for profile information. 
5. **state**: Extra information that can be passed that will be returned to your redirect url. Username, hashed password, email prefix and email suffix are passed here are they are required to register the account.

**2**) Google redirects back to my server with an access code and the state information that was set beforehand

**3**) Access code is used to obtain the required information about the user. This along with the parsed state information is enough to create a users account. Based on the users Google+ settings the request mightn't be able to return the users age, in this case age is simply set to -1.

## Client Overview ##

The client program is called DiTalk. It is written in C++ and Qt. It makes use of Qt's QtQuick(QML) technology for creating fluid UIs. 
The program is organised into 7 Classes as follows:

**DitalkBackEndController**: This is the main controller class. It is designed to be reuseable in other applications that may want to use the core functionality of the program. It handles logging in, registering, state management and delegation of other tasks.

**ChatManager**: This class manages open chats between the client and another user. It holds chat specific information such as who it is you're talking with and handles setting up a new chat, sending messages, polling the server for new chat information and adding new verified messages to the message thread model.

**Config**: Config holds global config properties in a namespace to avoid namespace/scope pollution. 
It holds the following: 

- Domain address for server 
- A Hash of endpoint translations 
- Path to json file holding google Api client information
- The interval in milliseconds between each poll request to the server

**DitalkState**: This simply holds a State enum with the functionality to expose it as an instantiable type to QML.
The State enum is defined as follows:
	
	enum State { LoggedOut, LoggedIn, Chatting, Size};

**MessageThread**: MessageThread is a dynamic QML model that inherits from  the abstract class QAbstractListModel. It holds the messages and context information that needs to be exposed to QML. 

**Util**: Util has a static function to read json from a file

**DitalkGuiLayer**: DitalkGuiLayer's job is to sit in between the front ends QML and DitalkBackEndController. It exposes many functions and dynamically updated properties to QML as well as providing translating between QML friendly parameters to the parameters required by DitalkGuiLayer exposed functions.

## Web Api ##

The web api is written in PHP and MySQL, it is structured as follows:

**Auth**: This handles authenticating an account with Google+ and requesting information through the Google+ api. It is only meant to be used as a redirection url from googles own servers.

**dbConnect**: This connects the php instance to the data base. It is required in most other end points.

**Login**: Logs in the user. Returns the php session id and other user infomation encoded as json back to the client.

**logout**: Simply destroys session data so that a user must log in again to obtain a valid session id.

**usersConnect**: Lets users connect and create a new chat instance. If successful it will return a chat id and other infomation about the chat encoded as json. Otherwise it will return a json encoded error message

**chat**: Chat requires a valid chat id and session id that matches one of those stored in the chat table. It allows the validated user to access and add to the message thread shared between both participents.

## ScreenShots ##

![Alt text](/Screenshots/login_empty.png?raw=true "Login Page")
![Alt text](/Screenshots/register_empty.png?raw=true "Register Page")
![Alt text](/Screenshots/start_chat.png?raw=true "Start Chat Page")
![Alt text](/Screenshots/start_chat_waiting.png?raw=true "Start Chat Waiting")
![Alt text](/Screenshots/active_chat_old.png?raw=true "Active Chat")

## Youtube ##

[![OOP Assignment 3](https://img.youtube.com/vi/Q0LjEigryfQ/0.jpg)](https://www.youtube.com/watch?v=Q0LjEigryfQ)


## How to run the application ##

For Windows simple run the executable inside the Release folder. 

## Issues ##

Currently there are some significant issues with the application, which are outlined below.


1. **Email missmatch**: There is currently nothing linking the users email account inputted in the application with the one you use to authenticate with Googles api. For example you could enter the email address C15324461 with the extension @mydit.ie into the app and then give permission to access data from a completely differenct account. As far as I'm aware this can be fixed by setting the hint parameter in of the requests to Googles Api. 
2. **Messages stop sending after a while**: When you log in and start a chat you will only be able to send ~5 messages before the applications starts receiving empty responses from the server and can't update the database with you're new messages. I currently have no idea why this is, I've looked at the code extensively for a reason behind this and couldn't find anything. I have confirmed that the requests are being sent properly via debugging information and that there is no scenario at all where the chat end point should be returning an empty response. I will attempt monitoring the packets being sent and received by the application via wireshark at some point to see if that sheds any light on the issue.
3. **No end chat feature**: The program doesn't allow you to end your chat. Functionality wise this isn't an issue as it isn't possible to access that same chat 'entry point' again. Instead a new chat will be created and you'll be able to load previous messages between users from that new entry point. However, it means that every new chat creates an entry in the openChats table that doesn't get deleted.
4. **Input text boxes retain focus**: On the register and login pages the text boxes will be cleared of text but still show the cursor after you have submitted a form. This is because I made those elements manually as there wasn't anything pre built that was suitable and the focus property isn't updating as expected.

**General Note:**

Originally the application was meant to use a peer to peer connection for messages being sent between users, alot of the issues in the program as well as the current lack of features are due to the time spent trying to build a working prototype that would connect two users directly and having to use php as a replacement, which was never my intention. In hindsight I could have built and hosted a simple server in C++ that would connects users together with via sockets if the peer to peer connection could not be established. 

