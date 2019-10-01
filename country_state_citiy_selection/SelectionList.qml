import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Country 1.0
import State 1.0

ColumnLayout {
    Frame {
        Layout.fillWidth: true

        ListView {
            id: listview
            implicitWidth: 250
            implicitHeight: 200
            anchors.fill: parent
            clip: true
            Component.onCompleted: function() {
                                       console.log('model', countries.getStatesAt(0))
                                   }
            model: CountryModel {
                countries: countries
            }
            delegate:
                Item {
                  id: element1
                  property variant myData: model
                  width: parent.width
                  height: 50

                RowLayout {
                width: parent.width
                Component.onCompleted: function() {
                    console.log("inside delegate list 1", model.name);
                }


                CheckBox {
                    checked: true
                    onClicked: {
                        console.log("index", storageHelper.getDisksof(index), listview.currentItem )
                        model.done = checked

//                        diskList.appendDisk();
                    }
                }
                TextField {
                    text: name
                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {listview.currentIndex = index

                    console.log("mouse clicked", listview.currentItem.myData.name, listview.currentIndex)}
                }
            }
        }

}
    Frame {
        Layout.fillWidth: true

        ListView {
            id: secondList
            implicitWidth: 250
            implicitHeight: 100
            anchors.fill: parent
            clip: true
//            Component.onCompleted: {
//                secondList.model = testingList.getDisksAt(0)
//            }

            model: StateModel {
                states: countries.getStatesAt(listview.currentIndex)
            }

            delegate: RowLayout {
                width: parent.width
                Component.onCompleted: function() {
                    console.log("inside delegate", model.stateName);
                }
                CheckBox {
                    checked: true
//                    onClicked: model.done = checked
                }
                TextField {
                    text: stateName
//                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }
            }
        }

    }
}
