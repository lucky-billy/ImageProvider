import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1024; height: 768
    title: qsTr("ImageProvider")
    visible: true

    Image {
        id: image
        anchors.fill: parent

        Component.onCompleted: cameraCtl.openCamera(100)    // 打开相机，每 100 ms 取一张图片

        Connections {
            target: cameraCtl

            // 收到信号刷新图片
            onCallQmlRefeshImg: image.source = "image://QYCamera/" + Math.random()
        }
    }
}
