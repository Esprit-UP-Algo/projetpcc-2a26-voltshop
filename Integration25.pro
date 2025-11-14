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
    gestion_employee.cpp \
    transaction.cpp \
    piechartwidget.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Login.h \
    article_dao.h \
    client_dao.h \
    commande.h \
    gestion_employee.h \
    piechartwidget.h \
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
