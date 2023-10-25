import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    minimumWidth: 500
    minimumHeight: 120
    maximumWidth: 500
    maximumHeight: 120
    visible: true

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

        Rectangle {
            id: leftRect
            x: parent.x + 10
            y: parent.height / 2 - 50
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            Text {
                anchors.centerIn: parent
                text: "move"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += ((rightRect.x - leftRect.x) / 3)

                    if(ball.x >= rightRect.x)
                        scene.state = "InitialState"
                    else
                        scene.state = "OtherState"
                }
            }
        }

        Rectangle {
            id: rightRect
            x: parent.width - width - 10
            y: parent.height / 2 - 50
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            Text {
                anchors.centerIn: parent
                text: "return"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }
        }

        Rectangle {
            id: ball
            x: leftRect.x + 5
            y: leftRect.y + 5
            width: leftRect.width - 10
            height: leftRect.height - 10
            color: "green"
            radius: width / 2
        }

        states: [
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRect.x + 5
                }
            },

            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x"
                    duration: 1000
                    easing.type: Easing.InOutBounce
                }
            }
        ]
    }
}
