#ifndef SPRSPECTRUMRANGESTABLEWIDGET_H
#define SPRSPECTRUMRANGESTABLEWIDGET_H

#include "ui_sprspectrumrangestablewidget.h"
#include "isprwidget.h"

class SPRSpectrumRangesTableWidget : public QWidget, public ISPRWidget
{
    Q_OBJECT

public:
    explicit SPRSpectrumRangesTableWidget(QWidget *parent = 0);

private:
    Ui::SPRSpectrumRangesTableWidget ui;

    // ISPRWidget interface
public:
    virtual ISPRModelData *getModel();

    ISPRModelData *setModel(ISPRModelData *data);
    void setThreads(SPRVariable<uint> *threads){ui.wSpectrumTable->model->setThreads(threads);}
public slots:
    virtual void widgetsShow();
    virtual void viewChange(QTableWidget *, int, int);
    virtual void viewChange(bool);
    virtual void onChangeColor(EnumElements el, QColor color){
        emit changeColor(el, color);
    }
signals:
    void doShow();
    void changeColor(EnumElements, QColor);

    // ISPRWidget interface
protected:
};

#endif // SPRSPECTRUMRANGESTABLEWIDGET_H
