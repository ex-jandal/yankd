import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Yankd - clipboard manager"

    Rectangle {
        anchors.fill: parent
        color: "#282828" // Gruvbox Background

        Text {
            anchors.centerIn: parent
            text: "Hello from QML!"
            color: "#ebdbb2" // Gruvbox Foreground
            font.pixelSize: 24
        }
    }
}
