import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4
import QtQuick.Dialogs 1.3



Page{
    id:mainPage
    property int partQuantity: backend.truePartQuantityGetter()
    property int partNum: backend.partNumGetter()

    visible:true


    Rectangle{
        id:mainBg
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


        //Rectangle for the Name background.
        Rectangle {
            id: rectangle
            x: 350
            y: 0
            width: 450
            height: 71
            border.color:"orange"
            border.width: 2



        }

        Text   {
            x: 427

            y:17
            width: 408
            height: 26
            text: "Operatör:"+ backend.json_Info[0]
            font.pixelSize: 30
            font.bold: true

        }

        Text{
            x: 350
            y:80
            text: "Parça Adı:"+"T-Stuck"
            color:"white"
            font.pixelSize: 25
        }

        Text{
            x: 350
            y:110
            text: "Parça Adedi:"+ partNum
            color: "white"
            font.pixelSize: 25
        }


        Rectangle{
            width: 340
            height:322
            border.color:"grey"
            border.width: 8
            focus:false

            Image{
                anchors.centerIn: parent
                width: 324
                height: 306
                focus:false
                source: "images/T-Stuck.jpg"
            }
        }




        Image {
            id: name
            x: 359
            y: 8
            width: 62
            height: 58
            source: "images/466667-200.png"
        }

        Image{
            id:gpmainlogo
            source:"images/gplogo.png"
            x:15
            y:368
            width: 107
            height: 104
        }




        ProgressCircle {
            id:pc

            x: 427
            y: 154
            width: 284
            height: 295
            Text{
                anchors.centerIn: parent
                text: partQuantity +"/"+ partNum
                font.pixelSize: 30
                color: "white"
            }


            size: 350
            colorCircle: "#779933"
            colorBackground: "#E6E6E6"
            showBackground: true
            isPie: false
            arcBegin:0
            arcEnd: partQuantity*360/partNum


        }

        Button{
            text: 'Green'
            x:100
            y:400
            onClicked: {
            backend.truePartQuantityAddition()
            backend.done(partQuantity)//QVariant kullanmayı bıraktık ama örnek olarak durması için bunu burada tutuyorum.
            mainPage.visible=false
            pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
        }
        }

        Button{
            text: 'Red'
            x:200
            y:400
            onClicked: {if(mainPage.visible){
                    if(backend.batchGetter()===1){
                        mainPage.visible=false
                        pageStack.replace(Qt.resolvedUrl("ListPage.qml"))
                    }
                    else{
                        pageStack.replace(Qt.resolvedUrl("BatchPage.qml"))
                    }
                }
        }

        }
        Button {
            text: 'Yellow'
            x:300
            y:400
            onClicked: {
           if(mainPage.visible){
                    mainPage.visible=false
                    pageStack.replace(Qt.resolvedUrl("BreakPage.qml"))}
        }

        }

        Connections{
            target: threadbutton


            onGsign: {

                if(mainPage.visible){

                    if(pc.arcEnd>=360){
                        backend.resetTruePartQuantity()
                       // backend.truePartQuantityAddition()
                       // backend.done(partQuantity)
                        pageStack.replace(Qt.resolvedUrl("WorkOrderFinished.qml"))


                    }


                    else{
                        backend.truePartQuantityAddition()
                        backend.done(partQuantity)//QVariant kullanmayı bıraktık ama örnek olarak durması için bunu burada tutuyorum.
                        mainPage.visible=false
                        pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
                    }
                }




            }

            onRsign: {
                if(mainPage.visible){
                    if(backend.batchGetter()===1){
                        mainPage.visible=false
                        pageStack.replace(Qt.resolvedUrl("ListPage.qml"))
                    }
                    else{
                        pageStack.replace(Qt.resolvedUrl("BatchPage.qml"))
                    }
                }

            }

            onYsign: {
                if(mainPage.visible){
                    mainPage.visible=false
                    pageStack.replace(Qt.resolvedUrl("BreakPage.qml"))}


            }


        }



    }
}





/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
