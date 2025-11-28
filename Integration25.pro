QT       += core gui sql \
    quick

QT += network

QT += printsupport
QT += widgets sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Login.cpp \
    logger.cpp \
    article_dao.cpp \
    client_dao.cpp \
    commande.cpp \
    totphelper.cpp \
    gestion_employee.cpp \
    transaction.cpp \
    qrdialog.cpp \
    piechartwidget.cpp \
    barchartwidget.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Login.h \
    article_dao.h \
    client_dao.h \
    commande.h \
    totphelper.h \
    qrdialog.h \
    gestion_employee.h \
    piechartwidget.h \
    barchartwidget.h \
    transaction.h \
    connection.h \
    mainwindow.h

FORMS += \
    Login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

win32: LIBS += -lDbghelp
