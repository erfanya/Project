import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Window 2.12

Page {
    title: "Add Doctor"
    Rectangle{
        color: "#3F51B5"
        anchors.bottomMargin: 0
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Image {
            id: image
            x: 0
            y: 0
            width: 1024
            height: 768
            fillMode: Image.PreserveAspectFit
            source: "1.jpg"
        }
    }

    Dialog {
        id: addErr
        title: "Faild"
        Text {
            id: addErrorText
            text: "Adding faild for one of folloing reasons
              1: Invalid information
              2: Not enough manager xp"
        }
    }

    Dialog {
        id: add
        title: "Successful"
        Text {
            id: addsuc
            text: "Doctor Added"
        }
    }

    TextField{
        id: fname
        x: 412
        y: 111
        placeholderText: "First Name"
    }

    TextField{
        id: lname
        x: 412
        y: 157
        placeholderText: "Last Name"
    }

    TextField{
        id: age
        x: 412
        y: 203
        placeholderText: "Age (+18)"
    }

    TextField{
        id: gender
        x: 412
        y: 249
        placeholderText: "Gender (male & female)"
    }

    TextField{
        id: phonenumber
        x: 412
        y: 295
        placeholderText: "Phone Number"
    }

    TextField{
        id: specialization
        x: 398
        y: 358
        width: 228
        height: 53
        placeholderText: "Specialization (general & expert & surgeon)"
    }

    Button {
        id: procceed
        x: 431
        y: 433
        width: 162
        height: 59
        text: "Procceed"
        highlighted: false
        flat: false
        autoRepeat: false
        autoExclusive: false
        checked: false
        checkable: false
        display: AbstractButton.TextBesideIcon
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

            if (specialization.text == "") {
                specialization.placeholderTextColor = "red"
                ok = false
            }
            else if (ok)
            {
                if (!bknd.add_doc(fname.text, lname.text, age.text, gender.text, phonenumber.text, specialization.text))
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
                specialization.clear()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}
}
##^##*/
