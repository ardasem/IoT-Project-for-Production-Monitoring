import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4

Page{
    id:loadingScreen
    Component.onCompleted: loadTimer.running=true
    visible:true
    Item {
        Timer {
            id:loadTimer
            interval: 2000; running: false; repeat: false
            onTriggered: {

                if(visible){
                visible=false
                pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
                }

            }

        }

        Text { id: time }
    }


     Rectangle{
        id:loadingBg
        width:800
        height:480
        Image{ anchors.rightMargin: 0; anchors.bottomMargin: 0; anchors.leftMargin: 0; anchors.topMargin: 0;source: "qrc:/images/4.jpg"; fillMode: Image.Tile; anchors.fill: parent;  opacity:1}


        Text {
            id: pleaseText
            text: qsTr("Lütfen parçayı uygun kasaya atınız.")
            anchors.verticalCenterOffset: 52
            anchors.horizontalCenterOffset: 0
            font.pixelSize: 22
            anchors.centerIn: parent
            color: "white"
        }

        Image{
            x: 313
            y: 102
            width: 175
            height: 170
            source: "images/box.png"
        }



    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
