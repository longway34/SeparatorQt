#ifndef SPRSTTINGSSPECTRUMRANGESTABLE_H
#define SPRSTTINGSSPECTRUMRANGESTABLE_H

#include <QObject>
#include <QWidget>
#include <QDomDocument>
#include <QPoint>

#include "isprwidget.h"
#include "sprspectrumranges.h"
#include "models/sprspectrumrangestablemodel.h"

class SPRSpectrumRangesTable : public QTableWidget, ISPRWidget
{
public:
    SPRSpectrumRangesTable(QWidget *parent = nullptr);

    // ISPRWidget interface

    SPRSpectrumRangesTableModel *model;
public:
    virtual ISPRModelData *getModel();

    void setModel(SPRSpectrumRangesTableModel *value);

public slots:
    virtual void viewChange(QTableWidget *table, int row, int col);
    virtual void widgetsShow();
    QPoint getSelectedPosition();
    EnumElements getSelectedElement(){
        return ((SPRSpectrumRanges*)focusWidget())->getSelectedElement();
    }
signals:
    tableChange(QTableWidget *table, int row, int col);
};

#endif // SPRSTTINGSSPECTRUMRANGESTABLE_H
