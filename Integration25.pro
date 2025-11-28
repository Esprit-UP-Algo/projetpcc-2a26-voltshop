<<<<<<< HEAD
QT += core gui widgets sql quick printsupport charts multimedia multimediawidgets

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 5): QT += charts

TARGET = Integration25
TEMPLATE = app

# ==========================
# SOURCES
# ==========================
SOURCES += \
    Login.cpp \
    article_dao.cpp \
    chatbotdialog.cpp \
    client_dao.cpp \
    commande.cpp \
    face_recognition.cpp \
=======
QT       += core gui sql \
    quick

QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Login.cpp \
    article_dao.cpp \
    client_dao.cpp \
    commande.cpp \
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
    gestion_employee.cpp \
    transaction.cpp \
    piechartwidget.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

<<<<<<< HEAD
# ==========================
# HEADERS
# ==========================
HEADERS += \
    CameraCaptureDialog.h \
    Login.h \
    article_dao.h \
    chatbotdialog.h \
    client_dao.h \
    commande.h \
    face_recognition.h \
=======
HEADERS += \
    Login.h \
    article_dao.h \
    client_dao.h \
    commande.h \
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
    gestion_employee.h \
    piechartwidget.h \
    transaction.h \
    connection.h \
    mainwindow.h

<<<<<<< HEAD
# ==========================
# FORMS
# ==========================
FORMS += \
    Login.ui \
    chatbotdialog.ui \
    mainwindow.ui

# ==========================
# RESOURCES
# ==========================
RESOURCES += resources.qrc


# ============================================================
#                🔷 CONFIG OPENCV 4.5.5 🔷 (IMPORTANT)
# ============================================================
OPENCV_PATH = C:/Users/IMDS/Downloads/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/OpenCV-MinGW-Build-OpenCV-4.5.5-x64

INCLUDEPATH += $$OPENCV_PATH/include

# 🔥 Corrigé : on lie avec lib, pas bin !
LIBS += -L$$OPENCV_PATH/x64/mingw/bin \
        -lopencv_core455 \
        -lopencv_imgproc455 \
        -lopencv_imgcodecs455 \
        -lopencv_videoio455 \
        -lopencv_objdetect455 \
        -lopencv_highgui455

# ============================================================
# INSTALLATION
# ============================================================
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
=======
FORMS += \
    Login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
>>>>>>> fa065ab36e11e25d1251f5a8cdc9329a165d3f94
