import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    //    MainForm {
    //        anchors.fill: parent
    //        mouseArea.onClicked: {
    //            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
    //        }
    //    }



    //list view
    ListView
    {
        id: testListView
        width: 500
        height: 400
        delegate:testDelegate
        model:testListModel

    }

    Component{
        id: testDelegate
        Item{
            height: 90
            width: 100
            Text{
                text:name
            }
            Rectangle{
                anchors.fill: parent
                color: "red"
                opacity: 0.1 * index
            }
        }
    }

    ListModel{
        id: testListModel
        ListElement{
            name: "index1"
            index: 1
        }
        ListElement{
            name: "index2"
            index: 2
        }
        ListElement{
            name: "index3"
            index: 3
        }
        ListElement{
            name: "index4"
            index: 4
        }
    }





    //animation
}
