# Project-Omegit

Project-Omegit (Or DiTalk) is a desktop chatting application that is written in C++ and qt. 
It also relies on a web api that is written in PHP and MySQL. 

It requires that users create an account using a valid college email address. 
To register you must authenticate your account with Googles api.
After that the application will request permission to access your name and age from your Google account.

Once logged in you can 'Start a chat'. This will query the web api to see if anyone else is also trying to start a chat, if so it will give both users a chatId that they can use to connect to their own chatting data on the chat.php endpoint.
Unfortunetly, this is of little us since I ran out of time to actually implement the GUI to allow users to talk to each other from this point.

YouTube: [https://youtu.be/SvN7Xky3eNY](https://youtu.be/SvN7Xky3eNY "OOP Assignment #3")

*Sound is off for some reason, just mute it.