import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    title: "Hospital Management"
    id: window
    visible: true
    width: 1024
    height: 768
    header: ToolBar {
        contentHeight: toolButton.implicitHeight
        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.2
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: "Add Doctor"
                width: parent.width
                onClicked: {
                    stackView.push("adddoctor.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: "Add Patient"
                width: parent.width
                onClicked: {
                    stackView.push("addpatient.qml")
                    drawer.close()
                }


            }
            ItemDelegate {
                text: "Set Visit"
                width: parent.width
                onClicked: {
                    stackView.push("setvisit.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: "Doctor Information"
                width: parent.width
                onClicked: {
                    stackView.push("doctorinformation.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: "Patient Information"
                width: parent.width
                onClicked: {
                    stackView.push("patientinformation.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: "Hospital Information"
                width: parent.width
                onClicked: {
                    stackView.push("hospitalinformation.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "hospital.qml"
        anchors.fill: parent
    }
}

/*##^##
Designer {
    D{i:0;height:768;width:1024}
}
##^##*/
