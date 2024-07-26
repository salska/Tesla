import QtQuick 2.15

Rectangle {
    id: bottomBar
    anchors {
        left: leftBar.right
        right: parent.right
        bottom: parent.bottom
    }

    color: "#24292b"
    height: parent.height / 12

    border.color: "black"
    border.width: 1
}
