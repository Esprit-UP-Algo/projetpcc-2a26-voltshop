QT       += core gui sql quick printsupport widgets charts multimedia multimediawidgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += charts

CONFIG += c++17

# Windows-specific libraries for crash handling
win32: LIBS += -lDbghelp

# ==========================
# APPLICATION CONFIG
# ==========================
TARGET = Integration25
TEMPLATE = app

# ==========================
# SOURCES (Merged)
# ==========================
SOURCES += \
    Login.cpp \
    VoltShopFeedbackPanel.cpp \
    aiinsightsdialog.cpp \
    arduino.cpp \
    article_dao.cpp \
    client_dao.cpp \
    clientpiechartwidget.cpp \
    commande.cpp \
    gestion_employee.cpp \
    smtp.cpp \
    transaction.cpp \
    piechartwidget.cpp \
    barchartwidget.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    totphelper.cpp \
    qrdialog.cpp \
    logger.cpp \
    excelexporter.cpp \
    chatbotdialog.cpp \
    face_recognition.cpp

# ==========================
# HEADERS (Merged)
# ==========================
HEADERS += \
    CameraCaptureDialog.h \
    Login.h \
    VoltShopFeedbackPanel.h \
    aiinsightsdialog.h \
    arduino.h \
    article_dao.h \
    client_dao.h \
    clientpiechartwidget.h \
    commande.h \
    gestion_employee.h \
    piechartwidget.h \
    barchartwidget.h \
    smtp.h \
    transaction.h \
    connection.h \
    mainwindow.h \
    totphelper.h \
    qrdialog.h \
    logger.h \
    excelexporter.h \
    chatbotdialog.h \
    face_recognition.h

# ==========================
# FORMS (Merged)
# ==========================
FORMS += \
    Login.ui \
    mainwindow.ui \
    qrdialog.ui \
    chatbotdialog.ui

# ==========================
# RESOURCES (Merged)
# ==========================
RESOURCES += resources.qrc

DISTFILES += \
    build/map.html

# ==========================
# OPENCV 4.5.5 CONFIG (Static path for friend setup)
# ==========================
OPENCV_PATH = C:/OpenCV-VoltShop

INCLUDEPATH += $$OPENCV_PATH/include

LIBS += -L$$OPENCV_PATH/x64/mingw/bin \
    -lopencv_core455 \
    -lopencv_imgproc455 \
    -lopencv_imgcodecs455 \
    -lopencv_videoio455 \
    -lopencv_objdetect455 \
    -lopencv_highgui455


# ==========================
# INSTALLS
# ==========================
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
