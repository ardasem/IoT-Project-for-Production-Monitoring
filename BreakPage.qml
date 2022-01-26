import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4


Page{
    id:breakPage
    visible: true




    Rectangle{
        id:breakBg
        width:800
        height:480
        Image{ anchors.rightMargin: 0; anchors.bottomMargin: 0; anchors.leftMargin: 0; anchors.topMargin: 0;source: "qrc:/images/4.jpg"; fillMode: Image.Tile; anchors.fill: parent;  opacity:1}

        Connections{
            target: threadbutton

            onYsign:{
                if(breakPage.visible){
                    breakPage.visible=false
                    pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
                }
            }
        }
        Button{
            text: 'Geri'
            onClicked: {if(breakPage.visible){
                           breakPage.visible=false
                           pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
                       }
            }

        }

        Text {
            id: breakText
            text: "Operatör moladadır, başlamak için lütfen bir tuşa basın."
            color: "white"
            font.pixelSize: 22
            y:260
            x:120
        }
        Image{
            id:coffeelogo
            source:"images/coffeelogo.png"

            x:256
            y:40
        }


    }
}
