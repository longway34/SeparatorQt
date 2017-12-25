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
public slots:
    virtual void widgetsShow();
    virtual void viewChange(QTableWidget *, int, int);
    virtual void viewChange(bool);
signals:
    void doShow();

    // ISPRWidget interface
protected:
};

#endif // SPRSPECTRUMRANGESTABLEWIDGET_H
