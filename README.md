# Project-Omegit

Project-Omegit allows users to create accounts and chat with other members.
It consists of a desktop client application and a http web api. 

It requires that users create an account using a valid college email address(*Not currently implemented, any address will do). 
To register you must authenticate your account with Google's api.
After that the application will request permission to access your name and age from your Google account.

Once logged in you are able to start a chat, which if another member is also attempting to start a chat, will connect you and that user so that you can chat via text.

## Client ##

The client program is called DiTalk. It is written in C++ and Qt. It makes use of Qt's QuickQuick technology for creating fluid UI's. 
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

**chat**: Chat requirs a valid chat id and session id that matches one of those stored in the chat table. It allows the validated user to access and add to the message thread shared between both participents.

## ScreenShots ##

![Alt text](/Screenshots/login_empty?raw=true "Login Page")