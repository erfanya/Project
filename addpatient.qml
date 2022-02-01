import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    title: "Add Patient"
    Rectangle{
        color: "#3F51B5"
        anchors.fill: parent

        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "2.jpg"
        }
    }

    Dialog {
        id: addErr
        title: "Faild"
        Text {
            id: addErrorText
            text: "Adding faild for invalid information"
        }
    }

    Dialog {
        id: add
        title: "Successful"
        Text {
            id: addsuc
            text: "Patient Added"
        }
    }

    TextField{
        id: fname
        x: 412
        y: 54
        placeholderText: "First Name"
    }

    TextField{
        id: lname
        x: 412
        y: 100
        placeholderText: "Last Name"
    }

    TextField{
        id: age
        x: 412
        y: 146
        placeholderText: "Age (1-110)"
    }

    TextField{
        id: gender
        x: 412
        y: 192
        placeholderText: "Gender (male & female)"
    }

    TextField{
        id: phonenumber
        x: 412
        y: 238
        placeholderText: "Phone Number"
    }

    TextField{
        id: insurance
        x: 412
        y: 295
        placeholderText: "Insurance (yes & no)"
    }

    TextField{
        id: illness
        x: 404
        y: 341
        width: 216
        height: 40
        placeholderText: "Illness (surface & emergency & surgery)"
    }

    Button {
        id: procceed
        x: 431
        y: 400
        width: 162
        height: 59
        text: "procceed"
        anchors.leftMargin: 453
        anchors.topMargin: 341
        anchors.rightMargin: 73
        anchors.bottomMargin: 84
        onClicked: {
            var ok = true

            if (fname.text == "") {
                fname.placeholderTextColor = "red"
                ok = false
            }

            if (lname.text == "") {
                lname.placeholderTextColor = "red"
                ok = false
            }

            if (age.text == "") {
                age.placeholderTextColor = "red"
                ok = false
            }

            if (gender.text == "") {
                gender.placeholderTextColor = "red"
                ok = false
            }

            if (phonenumber.text == "") {
                phonenumber.placeholderTextColor = "red"
                ok = false
            }

            if (insurance.text == "") {
                insurance.placeholderTextColor = "red"
                ok = false
            }

            if (illness.text == "") {
                illness.placeholderTextColor = "red"
                ok = false
            }
            else if (ok)
            {
                if (!bknd.add_pat(fname.text, lname.text, age.text, gender.text, phonenumber.text, insurance.text, illness.text))
                {
                    addErr.open()
                }
                else
                {
                    add.open()
                }

                fname.clear()
                lname.clear()
                age.clear()
                gender.clear()
                phonenumber.clear()
                insurance.clear()
                illness.clear()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}D{i:2;anchors_height:113;anchors_width:108;anchors_x:130;anchors_y:183}
}
##^##*/
