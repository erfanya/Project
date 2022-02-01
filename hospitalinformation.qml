import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    title: "Hospital Information"
    Rectangle{
        anchors.fill: parent
        color: "#3F51B5"

        Image {
            id: image
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "7.jpg"

            Text {
                id: element
                x: 221
                y: 346
                width: 93
                height: 33
                text: "Manager XP"
                font.pixelSize: 12
            }

            Text {
                id: element1
                x: 221
                y: 421
                width: 80
                height: 30
                text: "Number of Patients"
                font.pixelSize: 12
            }

            Text {
                id: element2
                x: 221
                y: 500
                width: 73
                height: 29
                text: "Number of Doctors"
                font.pixelSize: 12
            }

            Text {
                id: element3
                x: 221
                y: 574
                width: 73
                height: 29
                text: "Hospital Money"
                font.pixelSize: 12
            }
        }
    }

    TextField{
        id: managerxp
        x: 221
        y: 364
        placeholderText: "Manager XP"
        text: ""
    }

    TextField{
        id: doctors
        x: 221
        y: 516
        placeholderText: "Number of Doctors"
        text: ""
    }

    TextField{
        id: patients
        x: 221
        y: 441
        placeholderText: "Number of Patients"
    }

    TextField{
        id: money
        x: 221
        y: 591
        placeholderText: "Hospital Money"
    }

    Button {
        id: result
        x: 240
        y: 131
        width: 162
        height: 59
        text: "Result"
        anchors.leftMargin: 453
        anchors.topMargin: 341
        anchors.rightMargin: 73
        anchors.bottomMargin: 84
        onClicked: {
            managerxp.text = bknd.get_manager_xp();
            doctors.text = bknd.get_doc_numbers();
            patients.text = bknd.get_pat_numbers();
            money.text = bknd.get_hos_money();
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:768;width:1024}
}
##^##*/
