#include "camera.h"

Camera::Camera(QObject *parent) : QObject(parent)
{

}

Camera::~Camera()
{
    stopWork();
    closeCamera();
}

bool Camera::openCamera(int interval)
{
    m_timer.setInterval(interval);
    connect(&m_timer, &QTimer::timeout, this, &Camera::updateFrame);

    return m_camera.open(0, cv::CAP_DSHOW);
}

void Camera::closeCamera()
{
    m_camera.release();
}

void Camera::startWork()
{
    if ( m_camera.isOpened() ) {
        m_timer.start();
    }
}

void Camera::stopWork()
{
    if ( m_camera.isOpened() ) {
        m_timer.stop();
    }
}

void Camera::updateFrame()
{
    if ( m_camera.isOpened() ) {
        cv::Mat3b mat;
        m_camera >> mat;

        QImage image((const unsigned char *)(mat.data), mat.cols, mat.rows, mat.cols * 3, QImage::Format_RGB888);
        QImage ret = image.rgbSwapped();

        emit updateImage(ret.convertToFormat(QImage::Format_RGB888));
    }
}
