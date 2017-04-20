import QtQuick 2.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.1

Item {
    width: 350
    height: 390

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 350
        height: 390
        color: "#E6E6E6"

        KTextInput {
            id: emailInput
            x: 15
            y: 182
            pFontSize: 20
            pWidth: 200
            pPlaceholderText: "Email"
        }

        KTextInput {
            id: usernameInput
            x: 15
            y: 129
            pFontSize: 20
            pWidth: 200
            pPlaceholderText: "Username"
        }

        KTextInput {
            id: passwordInput
            x: 15
            y: 237
            pFontSize: 20
            pWidth: 200
            enablePasswordEcho: true
            pHeight: 23
            pPlaceholderText: "Password"
        }

        CollegeSelection {
            id: collegeInput
            x: 222
            y: 185
        }

        Rectangle
        {
            y: 15
            height: 100
            width: 300
            color: "#E6E6E6"

            anchors
            {
                left: parent.left;
                right: parent.right
                leftMargin: 50
                rightMargin: 50
            }

            Text {
                id: text1
                anchors.fill: parent
                text: qsTr("Welcome to DiTalk! Fill out your registration details now.")
                font.family: "Arial"
                wrapMode: Text.WordWrap
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
            }
        }

        Button
        {
            id: regButton
            x: 109
            y: 300
            width: 133
            height: 32
            text: qsTr("Register")

            onClicked:
            {
                if(BackEnd.registerUser(usernameInput.text, passwordInput.text,
                                     emailInput.text, collegeInput.text) === true)
                {
                    usernameInput.text = "";
                    passwordInput.text = "";
                    emailInput.text = "";
                }else
                {
                    console.log("Error registrating, please try again");
                }
            }
        }
    }
}
