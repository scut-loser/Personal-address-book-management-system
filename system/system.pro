QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddata.cpp \
    adddata_1.cpp \
    amenddata.cpp \
    amenddata_1.cpp \
    birthcongratulation.cpp \
    birthinspecifiedmonth.cpp \
    centeraligndelegate.cpp \
    deletedata.cpp \
    listitemdelegate.cpp \
    login_verification.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    adddata.h \
    adddata_1.h \
    amenddata.h \
    amenddata_1.h \
    birthcongratulation.h \
    birthinspecifiedmonth.h \
    centeraligndelegate.h \
    deletedata.h \
    listitemdelegate.h \
    login_verification.h \
    mainwindow.h

FORMS += \
    adddata.ui \
    adddata_1.ui \
    amenddata.ui \
    amenddata_1.ui \
    birthcongratulation.ui \
    birthinspecifiedmonth.ui \
    deletedata.ui \
    login_verification.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
