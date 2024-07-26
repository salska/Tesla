import QtQuick
import "ui/LeftBar"
import "ui/BottomBar"

Window {
    width: 1280
    height: 800
    visible: true
    title: qsTr("PKM")

    LeftBar {
        id: leftBar
    }

    BottomBar {
        id: bottomBar
    }

    Rectangle {
        id: mainBox
        anchors {
            left: leftBar.right
            bottom: bottomBar.top
            top: parent.top
            right: parent.right
        }
        color: "black"
    }
}
