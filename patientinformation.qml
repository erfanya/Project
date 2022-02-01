import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    title: "Patient Information"
    Rectangle{
        color: "#3F51B5"
        anchors.rightMargin: 0
        anchors.fill: parent

        Image {
            id: image
            anchors.bottomMargin: 0
            anchors.rightMargin: 0
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "6.jpg"
        }
    }

    TextField{
        id: pfname
        x: 317
        y: 54
        placeholderText: "Patient First Name"
    }

    TextField{
        id: plname
        x: 523
        y: 54
        placeholderText: "Patient Last Name"
    }

    Button {
        id: procceed
        x: 440
        y: 108
        width: 162
        height: 59
        text: "procceed"
        anchors.leftMargin: 453
        anchors.topMargin: 341
        anchors.rightMargin: 73
        anchors.bottomMargin: 84
        onClicked: {
            var ok = true

            if (pfname.text == "") {
                pfname.placeholderTextColor = "red"
                ok = false
            }

            if (plname.text == "") {
                plname.placeholderTextColor = "red"
                ok = false
            }

            else if (ok)
            {
                patname.text = bknd.get_pat_name(pfname.text, plname.text)
                patage.text = bknd.get_pat_age(pfname.text, plname.text)
                patgender.text = bknd.get_pat_gender(pfname.text, plname.text)
                patphone.text = bknd.get_pat_phonenumber(pfname.text, plname.text)
                patins.text = bknd.get_pat_insurance(pfname.text, plname.text)
                patill.text = bknd.get_pat_illness(pfname.text, plname.text)
                patstat.text = bknd.get_pat_status(pfname.text, plname.text)

                pfname.clear()
                plname.clear()
            }
        }

    }

    TextField{
        id: patname
        x: 421
        y: 316
        placeholderText: "Name Result"
        Text {
            id: patnametext
            text: ""
        }
    }

    TextField{
        id: patage
        x: 421
        y: 362
        placeholderText: "Age Result"
        Text {
            id: patagetext
            text: ""
        }
    }

    TextField{
        id: patgender
        x: 421
        y: 408
        placeholderText: "Gender Result"
        Text {
            id: patgendertext
            text: ""
        }
    }

    TextField{
        id: patphone
        x: 421
        y: 454
        placeholderText: "Phone Number Result"
        Text {
            id: patphonetext
            text: ""
        }
    }

    TextField{
        id: patins
        x: 421
        y: 500
        placeholderText: "Insurance Result"
        Text {
            id: patinstext
            text: ""
        }
    }

    TextField{
        id: patill
        x: 421
        y: 546
        placeholderText: "Illness Result"
        Text {
            id: patilltext
            text: ""
        }
    }

    TextField{
        id: patstat
        x: 421
        y: 592
        placeholderText: "Status Result"
        Text {
            id: patstattext
            text: ""
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}
}
##^##*/
