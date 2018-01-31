#ifndef MAINTABWIDGET_H
#define MAINTABWIDGET_H

#include "ui_maintabwidget.h"
#include "isprwidget.h"

class MainTabWidget : public QTabWidget, public ISPRWidget
{
    Q_OBJECT

    QDomDocument document;
    QDomDocument *doc;

public:
    explicit MainTabWidget(QWidget *parent = 0);
    MainTabWidget(QDomDocument *_doc, QWidget *parent = 0);

    SPRMainModel *mainModel;
    Ui::MainTabWidget ui;

signals:
    void doStore();
    void doShow();

    // ISPRWidget interface
public:
    virtual ISPRModelData *getModel(){return ui.tabSettings->getModel();}
public slots:
    virtual void viewChange(){}
    virtual void viewChange(int){}
    virtual void viewChange(QTableWidget *, int, int){}
    virtual void widgetsShow(){}
};

#endif // MAINTABWIDGET_H
