import QtQuick 2.0


Rectangle{
    id:finishPage
    width:800
    height:480
    rotation: 0
    border.width: 0
    Image{
        id: blackbg
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source: "qrc:/images/4.jpg"
        fillMode: Image.Tile
        anchors.fill: parent
        opacity:1
    }

    Text{
        width: 309
        height: 49
        anchors.centerIn: parent
        text : "İş emri sona ermiştir yeniden başlamak için bir tuşa basınız."
        anchors.verticalCenterOffset: 76
        anchors.horizontalCenterOffset: -195
        color: "white"
        font.family: "Helvetica"
        font.bold: false
        font.pointSize: 20
    }

    Connections{
        target: threadbutton

        onGsign:{
            pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
        }
        onRsign:{
            pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
        }
        onYsign:{
            pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
        }
        onResign:{
            pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
        }
    }
   }



