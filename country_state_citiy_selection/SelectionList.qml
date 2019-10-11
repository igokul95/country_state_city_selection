import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Country 1.0
import State 1.0
import City 1.0

ColumnLayout {
    height: parent.height - 200
    RowLayout {
        width: parent.width
        height: parent.height
        Frame {
            Layout.fillWidth: true
            height: parent.height

            ListView {
                onCurrentIndexChanged: {
                    countries.activeCountry = currentIndex
                    stateModel.states = countries.statesOfActiveCountry
                    cityModel.cities = countries.citiesOfActiveCountry
                }

                id: listview
                implicitWidth: 200
                implicitHeight: parent.height
                anchors.fill: parent
                clip: true

                model: CountryModel {
                    countries: countries
                }
                header: Text {
                    id: name
                    text: qsTr("Countries")
                    font.bold: true
                }

                delegate:
                    Item {
                    id: countryDelegate
                    width: parent.width
                    height: 50
                    RowLayout {
                        width: parent.width
                        TextField {
                            text: model.name
                            width: parent.width
                            height: parent.height
                            Layout.fillWidth: true
                            background: Rectangle {
                                width: parent.width
                                height: parent.height
                                color: listview.currentIndex === index ? "#70baff" : "#ffffff"
                            }
                        }
                    }
                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        onClicked: {
                            listview.currentIndex = index

                        }
                    }
                }

            }
        }
        Frame {
            Layout.fillWidth: true

            ListView {
                id: stateList
                implicitWidth: 200
                implicitHeight: 200
                anchors.fill: parent
                clip: true
                header: Text {
                    id: stateTitle
                    text: qsTr("States")
                    font.bold: true
                }
                model: StateModel {
                    id: stateModel
                    states: countries.statesOfActiveCountry
                }
                delegate:
                    Item {
                    id: stateDelegate
                    width: parent.width
                    height: 50
                    RowLayout {
                        width: parent.width
                        TextField {
                            text: stateName
                            width: parent.width
                            height: parent.height
                            Layout.fillWidth: true
                            background: Rectangle {
                                width: parent.width
                                height: parent.height
                                color: stateList.currentIndex === index ? "#70baff" : "#ffffff"
                            }
                        }
                    }
                    MouseArea {
                        id: mouseAreaState
                        anchors.fill: parent
                        onClicked: {
                            stateList.currentIndex = index
                        }
                    }
                }

            }
        }
        Frame {
            Layout.fillWidth: true

            ListView {
                id: cityList
                implicitWidth: 200
                implicitHeight: 200
                anchors.fill: parent
                clip: true
                header: Text {
                    id: cityTitle
                    text: qsTr("Cities")
                    font.bold: true
                }
                model: CityModel {
                    id: cityModel
                    cities: countries.citiesOfActiveCountry
                }
                delegate:
                    Item {
                    id: cityDelegate
                    width: parent.width
                    height: 50
                    RowLayout {
                        width: parent.width
                        TextField {
                            text: model.cityName
                            width: parent.width
                            height: parent.height
                            Layout.fillWidth: true
                            background: Rectangle {
                                width: parent.width
                                height: parent.height
                                color: cityList.currentIndex === index ? "#70baff" : "#ffffff"
                            }
                        }
                    }
                    MouseArea {
                        id: mouseAreacity
                        anchors.fill: parent
                        onClicked: {
                            cityList.currentIndex = index
                        }
                    }
                }

            }
        }
    }
}
