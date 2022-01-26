import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4
import Batch 1.0

Page{
    id:batchPage
    property int batchIndex:batchlist.currentIndex

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


        Text{
            id:batchQuantity
            x: 8
            y: 0

            text: "Yanlis cikan parca adedi: " + backend.batchGetter() + "/"
            font.pixelSize: 22
            color: "white"
        }

        Rectangle{
            x:320
            width:800
            height:450
            color:"transparent"

            ListView {
                id: batchlist

                anchors.fill:parent
                x:380
                flickableDirection: Flickable.AutoFlickDirection


                model: BatchModel {

                    list: batchList
                }

                Connections{
                    target:threadbutton



                    onResign: {

                        if(batchPage.visible){

                            if(batchlist.currentIndex == 0){
                                batchPage.visible=false
                                pageStack.replace(Qt.resolvedUrl("MainPage.qml"))

                            }
                            else{
                                backend.falsePartNumSetter(batchIndex)
                                batchPage.visible=false
                                pageStack.replace(Qt.resolvedUrl("ListPage.qml"))
                            }
                        }




                    }



                    onRdsign: {


                        if (batchlist.currentIndex + 1 < batchlist.count)
                            batchlist.currentIndex += 1;
                    }

                    onRusign: {
                        if (batchlist.currentIndex - 1 >= 0)
                            batchlist.currentIndex -= 1;
                    }



                }





                delegate: Component {
                    Item {
                        width: 250
                        height: 40

                        Column {
                            Text {

                                text:  model.description
                                font.pixelSize: 22
                                color : "white"
                            }

                        }

                    }
                }
                highlight: Rectangle {
                    color: "orange"
                    border.color: "orange"
                    border.width: 2
                }
                focus: true



            }
        }
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
