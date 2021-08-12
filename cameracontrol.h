#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H

#include <QObject>
#include "camera.h"
#include "imageprovider.h"

class CameraControl : public QObject
{
    Q_OBJECT
public:
    explicit CameraControl(QObject *parent = nullptr);
    ~CameraControl();

    Q_INVOKABLE void openCamera(int interval);

    inline ImageProvider *getImageProvider() { return m_imageProvider; }

signals:
    void callQmlRefeshImg();

private:
    ImageProvider *m_imageProvider;
    Camera *m_camera;
};

#endif // CAMERACONTROL_H
