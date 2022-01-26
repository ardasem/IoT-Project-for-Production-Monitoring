import QtQuick 2.0
import Backend 1.0
import WorkerThread 1.0

Item{


    WorkerThread{
        id:worker

    }

    Timer{
        interval:200
        running:true
        repeat:false

        onTriggered: worker.start()
    }
}
