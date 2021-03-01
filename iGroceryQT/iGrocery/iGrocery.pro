QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administratorwindow.cpp \
    db/goodsdb.cpp \
    db/usersdb.cpp \
    entities/good.cpp \
    entities/user.cpp \
    gooddialog.cpp \
    main.cpp \
    loginwindow.cpp \
    storewindow.cpp \
    userdialog.cpp \
    viewmodels/usersviewmodel.cpp

HEADERS += \
    administratorwindow.h \
    db/goodsdb.h \
    db/usersdb.h \
    entities/good.h \
    entities/user.h \
    gooddialog.h \
    loginwindow.h \
    storewindow.h \
    userdialog.h \
    viewmodels/usersviewmodel.h

FORMS += \
    administratorwindow.ui \
    gooddialog.ui \
    loginwindow.ui \
    storewindow.ui \
    userdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
