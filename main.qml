import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.8
import QtQuick.Extras 1.4
import WorkerThreadButton 1.0
import Backend 1.0


ApplicationWindow {
    visible: true
    width: 800
    height: 480
    title: qsTr("Sentinel")



    StackView{
        id:pageStack
        initialItem:StartPage{}

    }



}
