#include "cameracontrol.h"

CameraControl::CameraControl(QObject *parent) : QObject(parent)
{
    m_imageProvider = new ImageProvider();

    m_camera = new Camera();
    connect(m_camera, &Camera::updateImage, [&](QImage image){
        m_imageProvider->updateImage(image);    // 更新图像
        emit callQmlRefeshImg();    // 发送信号，让QML也更新图像
    });
}

CameraControl::~CameraControl()
{
    delete m_camera;
}

void CameraControl::openCamera(int interval)
{
    m_camera->openCamera(interval);
    m_camera->startWork();
}

