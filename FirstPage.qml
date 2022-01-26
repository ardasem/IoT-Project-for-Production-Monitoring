
import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4



Page{



    id:firstPage
    Rectangle{
        id:firstPageBg
        width:800
        height:480
        Image{ anchors.rightMargin: 0; anchors.bottomMargin: 0; anchors.leftMargin: 0; anchors.topMargin: 0;source: "qrc:/images/4.jpg"; fillMode: Image.Tile; anchors.fill: parent;  opacity:1}

        Image{
            id:gplogo
            source:"images/gplogo.png"
            x:10
            y:10
        }

        Image{
            id:rfidlogo

            source:"images/rfidlogo.png"
            x:256
            y:150
        }
        Text{
            x: 290
            y: 321
            color:"white"
            text:"Lütfen kartınızı okutunuz."
            font.pixelSize: 22
        }

       /* Connections{
            target: threadbutton

            OnRfsign:{

            }


        }*/



        }
    }


