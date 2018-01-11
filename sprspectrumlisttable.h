#ifndef SPRSPECTRUMLISTTABLE_H
#define SPRSPECTRUMLISTTABLE_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QVector>

#include "models/sprspectrumitemmodel.h"
#include "isprwidget.h"
#include "firstcolumn.h"

class SPRSpectrumListTable : public QTableWidget, public ISPRWidget
{
    Q_OBJECT

    QVector<SPRSpectrumItemModel*> model;

    void addRowTable(SpectrumData *data, int pastRow = -1);
    QLineEdit *setCellMyWidget(QTableWidget *table, int row, int col, QString value, bool editable=false, QString tt="");
public:
    explicit SPRSpectrumListTable(QWidget *parent = 0);

    ISPRModelData *setModel(QFile *inp, SPRSpectrumRangesTableModel *ranges);
    // ISPRWidget interface
public slots:
    virtual void widgetsShow();
    virtual ISPRModelData *getModel();
    virtual void viewChange(QColor color);
    virtual void viewChange();
    void hideCol(bool);
    void showCols(bool);
signals:
    void doShow();
};

#endif // SPRSPECTRUMLISTTABLE_H
