#ifndef FACE_RECOGNITION_H
#define FACE_RECOGNITION_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <QString>
#include <QMap>
#include <vector>

class FaceRecognition
{
public:
    static FaceRecognition& instance()
    {
        static FaceRecognition fr;
        return fr;
    }

    bool loadTrainingData(const QString &folder);
    int recognize(const cv::Mat &frame);

private:
    FaceRecognition() {}

    cv::CascadeClassifier faceCascade;

    // Store face templates: CIN -> face image
    QMap<int, cv::Mat> faceDatabase;

    // Compare two face images (returns similarity score)
    double compareFaces(const cv::Mat &face1, const cv::Mat &face2);
};

#endif // FACE_RECOGNITION_H
