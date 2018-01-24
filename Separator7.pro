#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T12:57:18
#
#-------------------------------------------------

QT       += core gui xml network
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
    _types.cpp \
    colorbutton.cpp \
    firstcolumn.cpp \
    ipvalidator.cpp \
    isprcontroller.cpp \
    isprwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    sprformulaelement.cpp \
    sprformulaitemwidget.cpp \
    sprporogswidget.cpp \
    sprsettingscontrolwidget.cpp \
    sprsettingsformulawidget.cpp \
    sprsettingsimswidget.cpp \
    sprsettingsmainwidget.cpp \
    sprsettingsporogswidget.cpp \
    sprsettingsrentgenautosetwidget.cpp \
    sprsettingsrentgencontrolwidget.cpp \
    sprsettingsrentgenmainwidget.cpp \
    sprsettingsrentgenwidget.cpp \
    sprspectrumbasedlisttable.cpp \
    sprspectrumlisttable.cpp \
    sprspectrumlisttablewidget.cpp \
    sprspectrumranges.cpp \
    sprspectrumrangestable.cpp \
    sprspectrumrangestablewidget.cpp \
    sprspectrumtableadv.cpp \
    models/imodelvariable.cpp \
    models/isprmodeldata.cpp \
    models/isprvariable.cpp \
    models/sprcolorvariable.cpp \
    models/sprdatevariable.cpp \
    models/sprelementvariable.cpp \
    models/sprformulaitemmodel.cpp \
    models/sprgrspectrumitemmodel.cpp \
    models/sprkprvariable.cpp \
    models/sprporogsmodel.cpp \
    models/sprqstringvariable.cpp \
    models/sprsettingscontrolmodel.cpp \
    models/sprsettingsformulamodel.cpp \
    models/sprsettingsimsmodel.cpp \
    models/sprsettingsmainmodel.cpp \
    models/sprsettingsporogsmodel.cpp \
    models/sprsettingsrentgenmodel.cpp \
    models/sprsettingsrmtautosetmodel.cpp \
    models/sprsettingsspectrumrangesmodel.cpp \
    models/sprspectrumitemmodel.cpp \
    models/sprspectrumrangesmodel.cpp \
    models/sprspectrumrangestablemodel.cpp \
    models/sprvariable.cpp \
    tcp/tcpcommand.cpp \
    tcp/tcpcommandset.cpp \
    tcp/tcpgetstatecommand.cpp \
    verticallabel.cpp \
    tabwidget.cpp

HEADERS += \
    _types.h \
    colorbutton.h \
    firstcolumn.h \
    ipvalidator.h \
    isprcontroller.h \
    isprwidget.h \
    mainwindow.h \
    sprformulaelement.h \
    sprformulaitemwidget.h \
    sprporogswidget.h \
    sprsettingscontrolwidget.h \
    sprsettingsformulawidget.h \
    sprsettingsimswidget.h \
    sprsettingsmainwidget.h \
    sprsettingsporogswidget.h \
    sprsettingsrentgenautosetwidget.h \
    sprsettingsrentgencontrolwidget.h \
    sprsettingsrentgenmainwidget.h \
    sprsettingsrentgenwidget.h \
    sprspectrumbasedlisttable.h \
    sprspectrumlisttable.h \
    sprspectrumlisttablewidget.h \
    sprspectrumranges.h \
    sprspectrumrangestable.h \
    sprspectrumrangestablewidget.h \
    sprspectrumtableadv.h \
    models/imodelvariable.h \
    models/isprmodeldata.h \
    models/isprvariable.h \
    models/sprcolorvariable.h \
    models/sprdatevariable.h \
    models/sprelementvariable.h \
    models/sprformulaitemmodel.h \
    models/sprgrspectrumitemmodel.h \
    models/sprkprvariable.h \
    models/sprporogsmodel.h \
    models/sprqstringvariable.h \
    models/sprsettingscontrolmodel.h \
    models/sprsettingsformulamodel.h \
    models/sprsettingsimsmodel.h \
    models/sprsettingsmainmodel.h \
    models/sprsettingsporogsmodel.h \
    models/sprsettingsrentgenmodel.h \
    models/sprsettingsrmtautosetmodel.h \
    models/sprsettingsspectrumrangesmodel.h \
    models/sprspectrumitemmodel.h \
    models/sprspectrumrangesmodel.h \
    models/sprspectrumrangestablemodel.h \
    models/sprvariable.h \
    tcp/itcpcommand.h \
    tcp/tcpcommand.h \
    tcp/tcpsenddatacommand.h \
    tcp/tcptimeoutcommand.h \
    tcp/tcpcommandset.h \
    tcp/tcpgetstatecommand.h \
    verticallabel.h \
    tabwidget.h

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
    firstcolumn.ui \
    tabwidget.ui

RESOURCES += \
    icons.qrc

#DISTFILES += \
#    models.pri


#include(models/models.pri)
#include(tcp/tcp.pri)
