 import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4

Page{
    Rectangle{

        width:800
        height:480
        Image{ anchors.rightMargin: 0; anchors.bottomMargin: 0; anchors.leftMargin: 0; anchors.topMargin: 0;source: "qrc:/images/4.jpg"; fillMode: Image.Tile; anchors.fill: parent;  opacity:1}

        Text{
            width: 167
            height: 90
            anchors.centerIn: parent
            text : "EDNI"
            anchors.verticalCenterOffset: -20
            anchors.horizontalCenterOffset: -18
            color: "white"
            font.family: "Trebuchet MS"
            font.bold: false
            font.pointSize: 60
            }
        Text{
            anchors.centerIn: parent
            text : "TECHNOLOGY"
            anchors.verticalCenterOffset: 39
            anchors.horizontalCenterOffset: 1
            color: "white"
            font.family: "Helvetica"
            font.bold: false
            font.pointSize: 25
        }

        Text{
            width: 309
            height: 49
            anchors.centerIn: parent
            text : "Üretim " + "Takip "+"Sistemi"
            anchors.verticalCenterOffset: 208
            anchors.horizontalCenterOffset: 219
            color: "white"
            font.family: "Helvetica"
            font.bold: false
            font.pointSize: 24
        }
       }

    Item{
     Timer {
          interval: 2000; running: true; repeat: false
          onTriggered:{
              pageStack.replace(Qt.resolvedUrl("MainPage.qml"))

          }
      }
    }

    }



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
