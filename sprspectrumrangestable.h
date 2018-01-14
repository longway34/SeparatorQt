#ifndef SPRSTTINGSSPECTRUMRANGESTABLE_H
#define SPRSTTINGSSPECTRUMRANGESTABLE_H

#include <QObject>
#include <QWidget>
#include <QDomDocument>
#include <QPoint>
#include <QTableWidget>

#include "isprwidget.h"
#include "sprspectrumranges.h"
#include "models/sprspectrumrangestablemodel.h"

class SPRSpectrumRangesTable : public QTableWidget, ISPRWidget
{
    Q_OBJECT

public:
    explicit SPRSpectrumRangesTable(QWidget *parent = nullptr);

    // ISPRWidget interface

    SPRSpectrumRangesTableModel *model;
public:
    virtual ISPRModelData *getModel();

    void setModel(SPRSpectrumRangesTableModel *value);
    void setFirtChannel(int ch);
    void setHddenChannels(QList<bool> hiddens);
    void setVisibleOneChannel(int ch);
//    QSize sizeHint() const;
public slots:
    virtual void viewChange(QTableWidget *table, int row, int col);
    virtual void widgetsShow();
    QPoint getSelectedPosition();
    void onChangeColor(EnumElements el, QColor color);
signals:
    void tableChange(QTableWidget *table, int row, int col);
    void tableChange(EnumElements element, int thread, int col);
    void changeColor(EnumElements, QColor);
};

#endif // SPRSTTINGSSPECTRUMRANGESTABLE_H
