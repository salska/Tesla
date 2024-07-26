import QtQuick 2.15
import Tesla 1.0

Rectangle {
    id: leftBar
    anchors {
        left: parent.left
        bottom: parent.bottom
        top: parent.top
    }

    color: "#24292b"
    width: parent.width / 6
    border.color: "black"
    border.width: 1

    ListView {
        width: parent.width
        height: parent.height

        model: TitleModel {}

        delegate: Item {
            width: parent.width
            height: 50

            Rectangle {
                width: parent.width
                height: 50
                color: "transparent"

                Text {
                    text: model.title
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 30
                    anchors.topMargin: 50
                    font.bold: true
                    font.pointSize: 16
                    color: "white"
                }
            }
        }
    }

}
