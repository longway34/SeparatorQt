#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T12:57:18
#
#-------------------------------------------------

QT       += core gui xml
CONFIG   += qwt

win32:CONFIG += console
win32:TARGET  = ../XmlDOMRead

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Separator7
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    sprsettingsrentgenmainwidget.cpp \
    sprsettingsrentgencontrolwidget.cpp \
    sprsettingsrentgenautosetwidget.cpp \
    _types.cpp \
    sprformulaitemwidget.cpp \
    sprsettingsformulawidget.cpp \
    ipvalidator.cpp \
    isprcontroller.cpp \
    isprwidget.cpp \
    sprformulaelement.cpp \
    sprporogswidget.cpp \
    sprsettingsporogswidget.cpp \
    sprspectrumranges.cpp \
    sprspectrumrangestable.cpp \
    sprspectrumrangestablewidget.cpp \
    sprsettingsmainwidget.cpp \
    sprsettingsrentgenwidget.cpp \
    sprsettingsimswidget.cpp \
    sprsettingscontrolwidget.cpp \
    sprspectrumtableadv.cpp \
    sprspectrumlisttablewidget.cpp \
    firstcolumn.cpp \
    colorbutton.cpp \
    sprspectrumlisttable.cpp \
    sprspectrumbasedlisttable.cpp

HEADERS += \
        mainwindow.h \
    sprsettingsrentgenmainwidget.h \
    sprsettingsrentgencontrolwidget.h \
    sprsettingsrentgenautosetwidget.h \
    _types.h \
    sprformulaitemwidget.h \
    sprsettingsformulawidget.h \
    ipvalidator.h \
    isprcontroller.h \
    isprwidget.h \
    sprformulaelement.h \
    sprporogswidget.h \
    sprsettingsporogswidget.h \
    sprspectrumranges.h \
    sprspectrumrangestable.h \
    sprspectrumrangestablewidget.h \
    sprsettingsmainwidget.h \
    sprsettingsrentgenwidget.h \
    sprsettingsimswidget.h \
    sprsettingscontrolwidget.h \
    sprspectrumtableadv.h \
    sprspectrumlisttablewidget.h \
    firstcolumn.h \
    colorbutton.h \
    sprspectrumlisttable.h \
    sprspectrumbasedlisttable.h

FORMS += \
        mainwindow.ui \
    sprsettingsrentgenmainwidget.ui \
    sprsettingsrentgencontrolwidget.ui \
    sprsettingsrentgenautosetwidget.ui \
    sprformulaitemwidget.ui \
    sprsettingsformulawidget.ui \
    sprporogswidget.ui \
    sprsettingsporogswidget.ui \
    sprspectrumrangestablewidget.ui \
    sprsettingsmainwidget.ui \
    sprsettingsrentgenwidget.ui \
    sprsettingsimswidget.ui \
    sprsettingscontrolwidget.ui \
    sprspectrumlisttablewidget.ui \
    firstcolumn.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    models.pri

include(models.pri)
