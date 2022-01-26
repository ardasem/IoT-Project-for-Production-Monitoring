import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4
import ToDo 1.0


Page{
    id:faultScreen
    property var errorIndex: list.currentIndex
    property int partQuantity: backend.truePartQuantityGetter()

    //kullanılacak butonları tek tek sinyal halinde backend içine yazıp butonların yapması gereken işleri burada dolduracağız iyi akşamlar. örnek sinyaller aşağıda
    //keys.onenterpressed keys.onUpPressed ve keys.onDownPressed sinyallerinin içindedir.
    visible:true

    Rectangle{
        id:faultBg
        width:800
        height:480
        Image{ anchors.rightMargin: 0; anchors.bottomMargin: 0; anchors.leftMargin: 0; anchors.topMargin: 0;source: "qrc:/images/4.jpg"; fillMode: Image.Tile; anchors.fill: parent;  opacity:1}


        Text{
            id:pleasechoose
            text: "Lütfen hata seçiniz:"
            font.pixelSize: 22
            color: "white"


        }


        Rectangle{
            x:230
            width:800
            height:450
            color:"transparent"

            ListView {
                id: list
                objectName: "errorList"
                anchors.fill:parent
                x:300

                model: ToDoModel {

                    list: toDoList
                }

                Connections{
                    target:threadbutton



                    onResign: {

                        if(faultScreen.visible){

                            if( list.currentIndex == 0){

                                pageStack.replace(Qt.resolvedUrl("BatchPage.qml"))

                            }
                            else if(backend.batchGetter()!== 1){
                            backend.falsePartQuantityAddition()
                            backend.error_Track(errorIndex)
                            backend.truePartQuantityAddition()
                            backend.truePartQuantitySubstraction()
                            backend.done(partQuantity)
                            faultScreen.visible=false
                            pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
                            }
                            else{
                                backend.falsePartQuantityAddition()
                                backend.error_Track(errorIndex)
                                faultScreen.visible=false
                                pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
                            }
                        }




                    }



                    onRdsign: {


                        if (list.currentIndex + 1 < list.count)
                            list.currentIndex += 1;
                    }

                    onRusign: {
                        if (list.currentIndex - 1 >= 0)
                            list.currentIndex -= 1;
                    }



                }



                delegate: Component {
                    Item {
                        width: 600
                        height: 40

                        Column {
                            Text {

                                text:  model.description
                                font.pixelSize: 20
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



         Button{
            x:50
            y:380
            text: "Tamam"
            onClicked: {

                if(faultScreen.visible){

                    if( list.currentIndex == 0){

                        pageStack.replace(Qt.resolvedUrl("BatchPage.qml"))

                    }
                    else if(backend.batchGetter()!== 1){
                    backend.falsePartQuantityAddition()
                    backend.error_Track(errorIndex)
                    backend.truePartQuantityAddition()
                    backend.truePartQuantitySubstraction()
                    backend.done(partQuantity)
                    faultScreen.visible=false
                    pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
                    }
                    else{
                        backend.falsePartQuantityAddition()
                        backend.error_Track(errorIndex)
                        faultScreen.visible=false
                        pageStack.replace(Qt.resolvedUrl("LoadingPage.qml"))
                    }
                }

            }
        }
    }
}

