import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    title: "Set Visit"
    Rectangle{
        color: "#3F51B5"
        anchors.rightMargin: 0
        anchors.fill: parent

        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "3.jpg"

            Button {
                id: pay
                x: 437
                y: 236
                width: 162
                height: 59
                text: ""
                onClicked: {
                    visit.open()
                    pay.text = ""
                }
            }
        }
    }

    Dialog {
        id: visitErr
        title: "Faild"
        Text {
            id: visitErrorText
            text: "Visiting faild for one of following reasons
                   1: Bad Doctor choice
                   2: Patient Already Visited
                   3: Invalid information"
        }
    }

    Dialog {
        id: visit
        title: "Successful"
        Text {
            id: visitsuc
            text: "Visit was Successful"
        }
    }

    TextField{
        id: pfname
        x: 311
        y: 54
        placeholderText: "Patient First Name"
    }

    TextField{
        id: plname
        x: 523
        y: 54
        placeholderText: "Patinet Last Name"
    }

    TextField{
        id: dfname
        x: 311
        y: 114
        placeholderText: "Doctor First Name"
    }

    TextField{
        id: dlname
        x: 523
        y: 114
        placeholderText: "Doctor Last name"
    }

    Button {
        id: procceed
        x: 437
        y: 173
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

            if (dfname.text == "") {
                dfname.placeholderTextColor = "red"
                ok = false
            }

            if (dlname.text == "") {
                dlname.placeholderTextColor = "red"
                ok = false
            }

            else if (ok)
            {
                if(!bknd.setvisit(dfname.text, dlname.text, pfname.text, plname.text))
                {
                    visitErr.open()
                }
                else
                {
                    pay.text = bknd.get_pat_fee(pfname.text, plname.text)
                }

                dfname.clear()
                dlname.clear()
                pfname.clear()
                plname.clear()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}D{i:2;anchors_height:100;anchors_width:100;anchors_x:76;anchors_y:238}
}
##^##*/
