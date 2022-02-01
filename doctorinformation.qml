import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    title: "Doctor Information"
    Rectangle{
        color: "#3F51B5"
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.fill: parent

        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "5.jpg"
        }
    }

    TextField{
        id: dfname
        x: 311
        y: 54
        placeholderText: "Doctor First Name"
    }

    TextField{
        id: dlname
        x: 523
        y: 54
        placeholderText: "Doctor Last Name"
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
                docname.text = bknd.get_doc_name(dfname.text, dlname.text)
                docage.text = bknd.get_doc_age(dfname.text, dlname.text)
                docgender.text = bknd.get_doc_gender(dfname.text, dlname.text)
                docphone.text = bknd.get_doc_phonenumber(dfname.text, dlname.text)
                docspe.text = bknd.get_doc_spelization(dfname.text, dlname.text)

                dfname.clear()
                dlname.clear()
            }
        }
    }

    TextField{
        id: docname
        x: 421
        y: 316
        placeholderText: "Name Result"
        Text {
            id: docnametext
            text: ""
        }
    }

    TextField{
        id: docage
        x: 421
        y: 362
        placeholderText: "Age Result"
        Text {
            id: docagetext
            text: ""
        }
    }

    TextField{
        id: docgender
        x: 421
        y: 408
        placeholderText: "Gender Result"
        Text {
            id: docgendertext
            text: ""
        }
    }

    TextField{
        id: docphone
        x: 421
        y: 454
        placeholderText: "Phone Number Result"
        Text {
            id: docphonetext
            text: ""
        }
    }

    TextField{
        id: docspe
        x: 421
        y: 500
        placeholderText: "Specialization Result"
        Text {
            id: docspetext
            text: ""
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}
}
##^##*/
