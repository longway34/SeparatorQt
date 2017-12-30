#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDomDocument>
#include "ui_mainwindow.h"
#include "isprwidget.h"

class MainWindow : public QMainWindow, public ISPRWidget
{
    Q_OBJECT

    QDomDocument document;
    QDomDocument *doc;

public:
    explicit MainWindow(QWidget *parent = 0);

    MainWindow(QDomDocument *_doc, QWidget *parent = 0);

    SPRSettingsMainModel *mainModel;
    Ui::MainWindow ui;
private:
//    ISPRWidget *addWidgetAndModel(ISPRWidget *widget, ISPRModelData *model);
signals:
    void doStore();
    void doShow();

    // ISPRWidget interface
public:
    virtual void widgetsShow();
    virtual ISPRModelData *getModel();
public slots:
    virtual void viewChange();
    virtual void viewChange(int);
    virtual void viewChange(QTableWidget *, int, int);

};

#endif // MAINWINDOW_H
