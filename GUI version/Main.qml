import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Properties and Handler")

    property string first_name: "Minh" // WHen we define the first_name here, Qt will auto
    //matically generate a signal will be fired wheneber the first_name change
    onFirst_nameChanged: { // signal to generate the property when it changed
        console.log("First name: " + first_name)
    }

    Rectangle {
        id: myRectangle
        width: 300
        height: 100
        color:"greenyellow"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                first_name = "Ky Anh" // change the property then itwill display on the nameCHanged
                Qt.quit()
            }
        }
    }

    Component.onCompleted: {
        console.log("First name: " + first_name) // this will display first when component is loaded
    }
}
