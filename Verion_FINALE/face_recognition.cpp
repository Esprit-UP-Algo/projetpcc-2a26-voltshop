#include "face_recognition.h"
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include <QString>
#include <vector>

bool FaceRecognition::loadTrainingData(const QString &folder)
{
    // Load Haar Cascade for face detection
    // Try multiple locations for the cascade file
    QStringList cascadePaths = {
        "C:/Users/IMDS/Downloads/integration2026 (3) (1)/integration2026 (3)/integration2026/integrationtest/haarcascade_frontalface_default.xml",
        QCoreApplication::applicationDirPath() + "/haarcascade_frontalface_default.xml",
        "haarcascade_frontalface_default.xml"
    };


    bool cascadeLoaded = false;
    for (const QString &path : cascadePaths) {
        if (faceCascade.load(path.toStdString())) {
            qDebug() << "✅ Haar Cascade loaded from:" << path;
            cascadeLoaded = true;
            break;
        }
    }

    if (!cascadeLoaded) {
        qDebug() << "❌ Haar Cascade not found! Tried paths:";
        for (const QString &path : cascadePaths) {
            qDebug() << "   -" << path;
        }
        return false;
    }

    QDir dir(folder);
    if (!dir.exists()) {
        qDebug() << "❌ Training folder does not exist:" << folder;
        return false;
    }

    QStringList images = dir.entryList({"*.jpg", "*.png", "*.jpeg"}, QDir::Files);

    if (images.isEmpty()) {
        qDebug() << "❌ No training images found in:" << folder;
        return false;
    }

    qDebug() << "📂 Found" << images.size() << "images in training folder";

    // Load all face templates from training folder
    for (const QString &imgName : images)
    {
        QString fullPath = folder + "/" + imgName;
        cv::Mat img = cv::imread(fullPath.toStdString(), cv::IMREAD_GRAYSCALE);

        if (img.empty()) {
            qDebug() << "⚠️ Could not read:" << imgName;
            continue;
        }

        // Extract CIN from filename (e.g., "12345678.jpg" -> 12345678)
        int cinValue = imgName.section(".", 0, 0).toInt();

        if (cinValue == 0) {
            qDebug() << "⚠️ Invalid CIN in filename:" << imgName;
            continue;
        }

        // Detect face in the image
        std::vector<cv::Rect> detected;
        faceCascade.detectMultiScale(img, detected, 1.3, 5);

        if (detected.empty()) {
            qDebug() << "⚠️ No face detected in:" << imgName;
            continue;
        }

        // Extract and resize face region
        cv::Mat faceROI = img(detected[0]).clone();
        cv::resize(faceROI, faceROI, cv::Size(150, 150));

        // Store in database
        faceDatabase[cinValue] = faceROI;
        qDebug() << "✅ Loaded face for CIN:" << cinValue << "from" << imgName;
    }

    if (faceDatabase.isEmpty()) {
        qDebug() << "❌ No valid faces found in training dataset!";
        return false;
    }

    qDebug() << "✅ Training complete! Loaded" << faceDatabase.size() << "face(s)";
    return true;
}

double FaceRecognition::compareFaces(const cv::Mat &face1, const cv::Mat &face2)
{
    // Ensure both images have the same size
    if (face1.size() != face2.size()) {
        return 999999.0;
    }

    // Calculate absolute difference between two faces
    cv::Mat diff;
    cv::absdiff(face1, face2, diff);

    // Return mean pixel difference (lower = more similar)
    return cv::mean(diff)[0];
}

int FaceRecognition::recognize(const cv::Mat &frame)
{
    if (faceDatabase.isEmpty()) {
        qDebug() << "❌ No training data loaded!";
        return -1;
    }

    // Convert to grayscale
    cv::Mat gray;
    if (frame.channels() == 3) {
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = frame.clone();
    }

    // Detect faces in the frame
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(gray, faces, 1.3, 5);

    if (faces.empty()) {
        return -1; // No face detected
    }

    // Extract and resize the first detected face
    cv::Mat face = gray(faces[0]).clone();
    cv::resize(face, face, cv::Size(150, 150));

    // Find best match in database
    int bestMatch = -1;
    double bestScore = 999999.0;

    for (auto it = faceDatabase.begin(); it != faceDatabase.end(); ++it)
    {
        double score = compareFaces(face, it.value());

        if (score < bestScore) {
            bestScore = score;
            bestMatch = it.key();
        }
    }

    qDebug() << "🔍 Best match CIN:" << bestMatch << "| Score:" << bestScore;

    // Return CIN if confidence is good enough (lower score = better match)
    // Adjust threshold based on your testing (30-40 works well)
    return (bestScore < 35.0) ? bestMatch : -1;
}
