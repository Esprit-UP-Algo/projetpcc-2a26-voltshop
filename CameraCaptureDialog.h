#ifndef CAMERACAPTUREDIALOG_H
#define CAMERACAPTUREDIALOG_H

#include <QDialog>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QVideoWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QDir>
#include <QDebug>

class CameraCaptureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraCaptureDialog(QWidget *parent = nullptr)
        : QDialog(parent),
        camera(new QCamera(this)),
        captureSession(new QMediaCaptureSession),
        imageCapture(new QImageCapture(this)),
        videoWidget(new QVideoWidget(this))
    {
        setWindowTitle("Capture Employee Photo");
        setMinimumSize(600, 500);

        // Attach camera -> capture session -> video output -> widget
        captureSession->setCamera(camera);
        captureSession->setImageCapture(imageCapture);
        captureSession->setVideoOutput(videoWidget);

        QPushButton *btnCapture = new QPushButton("Capture Image");
        QPushButton *btnCancel = new QPushButton("Cancel");

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(videoWidget);
        layout->addWidget(btnCapture);
        layout->addWidget(btnCancel);
        setLayout(layout);

        connect(btnCapture, &QPushButton::clicked,
                this, &CameraCaptureDialog::captureImage);

        connect(btnCancel, &QPushButton::clicked,
                this, &CameraCaptureDialog::reject);

        connect(imageCapture, &QImageCapture::imageSaved,
                this, &CameraCaptureDialog::onImageSaved);

        camera->start();
    }

    QString getSavedImagePath() const { return savedPath; }

private slots:
    void captureImage()
    {
        QString dirPath = "C:/Users/IMDS/Downloads/integration2026 (3) (1)/integration2026 (3)/integration2026/integrationtest/employees_photos";

        // Make sure the folder exists
        QDir().mkpath(dirPath);

        // Temporarily change working directory
        QDir::setCurrent(dirPath);

        QString fileName = "employee_temp_photo.jpg"; // Just file name, now relative to new working directory

        qDebug() << "Saving image to:" << QDir::current().absoluteFilePath(fileName);

        imageCapture->captureToFile(fileName);
    }

    void onImageSaved(int id, const QString &fileName)
    {
        savedPath = fileName;
        accept();
    }

private:
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QImageCapture *imageCapture;
    QVideoWidget *videoWidget;
    QString savedPath;
};

#endif // CAMERACAPTUREDIALOG_H
