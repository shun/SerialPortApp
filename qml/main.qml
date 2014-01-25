import QtQuick 1.1

Rectangle {
    width: 800
    height: 600
    Text {
        text: qsTr("Hello World ###")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}

