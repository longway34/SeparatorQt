#ifndef SPRPOROGSWIDGET_H
#define SPRPOROGSWIDGET_H

#include <QLineEdit>
#include <QValidator>
#include <QDomDocument>

#include "ui_sprporogswidget.h"
#include "_types.h"
#include "models/sprporogsmodel.h"
#include "models/sprvariable.h"
#include "isprwidget.h"

class SPRPorogsWidget : public QWidget, public ISPRWidget
{
    Q_OBJECT
    SPRPorogsModel *model;
//    SPRVariable<uint> *threads;

public:
    explicit SPRPorogsWidget(QWidget *parent = 0);
    Ui::SPRPorogsWidget ui;

    void setThreads(SPRVariable<uint>* threads) {this->model->setThreads(threads);}
    ISPRModelData *setModel(ISPRModelData *model);

public slots:
    void changeCellLe();
private:

    // ISPRWidget interface
signals:
    void tableChange(QTableWidget *table, int row, int col);
protected:


    // ISPRWidget interface
public slots:
    virtual ISPRModelData *getModel();
    virtual void widgetsShow();


    // ISPRWidget interface
protected:
    virtual void viewChange(QTableWidget*, int, int);
};

#endif // SPRPOROGSWIDGET_H
