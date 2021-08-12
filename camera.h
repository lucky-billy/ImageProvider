#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <opencv2/opencv.hpp>

class Camera : public QObject
{
    Q_OBJECT

public:
    Camera(QObject *parent = nullptr);
    ~Camera();

    bool openCamera(int interval);      // 打开相机
    void closeCamera();                 // 关闭相机
    void startWork();                   // 开始工作
    void stopWork();                    // 停止工作

signals:
    void updateImage(QImage image);     // 更新一帧图像

public slots:
    void updateFrame();

private:
    QTimer m_timer;
    cv::VideoCapture m_camera;
};

#endif // CAMERA_H
