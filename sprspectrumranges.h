#ifndef SPRSPECTRUMRANGES_H
#define SPRSPECTRUMRANGES_H

//#include "ui_sprspectrumranges.h"
#include <QTableWidget>
#include <QPoint>

#include "models/sprspectrumrangesmodel.h"
#include "isprwidget.h"

class SPRSpectrumRanges : public QTableWidget, ISPRWidget
{
    Q_OBJECT

    SPRSpectrumRangesModel *model;
public:
    explicit SPRSpectrumRanges(QWidget *parent = 0);
//    Ui::SPRSpectrumRanges ui;

    virtual ISPRModelData *getModel();
    QSize sizeHint() const;
    QSize actualSize;
private:

    // ISPRWidget interface
public:
    virtual void widgetsShow();
    void setModel(SPRSpectrumRangesModel *value);
    QPoint getSelectedPosition();
    EnumElements getSelectedElement();
//public slots:
//    virtual void viewChange(QTableWidget *table, int row, int col);

//    void onFocus(QFocusEvent *event);
signals:
    void tableChange(QTableWidget*, int row, int col);

    // ISPRWidget interface
protected slots:
    virtual void viewChange();
};

#endif // SPRSPECTRUMRANGES_H
