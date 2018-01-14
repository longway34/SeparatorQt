#ifndef SPRSPECTRUMLISTTABLE_H
#define SPRSPECTRUMLISTTABLE_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QVector>
#include <QLabel>

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
    QVector<SPRSpectrumItemModel*> *getModels(){ return &model; }
    SPRSpectrumItemModel *getModel(int index){
        if(index < model.size()){
            return model[index];
        } else {
            return nullptr;
        }
    }

    QList<int> getSelectedItems(){
        QList<int> res;
        for(int row=0; row<rowCount(); row++){
            FirstColumn *fc = (FirstColumn*)cellWidget(row, 0);
            if(fc->isRowChecked()){
                res.push_back(row);
            }
        }
        return res;
    }
    bool isSelectedItem(int row){
        FirstColumn *fc = (FirstColumn*)cellWidget(row, 0);
        return fc->isRowChecked();
    }
    QColor getColorSpectrum(int row){
        FirstColumn *fc = (FirstColumn*)cellWidget(row, 0);
        return fc->getMyColor();
    }
    int getThread(int row){
        QLabel* lth = (QLabel*)cellWidget(row, 1);
        return lth->text().toInt();
    }
    int getSumm(int row){
        QLabel* lth = (QLabel*)cellWidget(row, 3);
        return lth->text().toInt();
    }
    QString getName(int row){
        QLabel* lth = (QLabel*)cellWidget(row, 2);
        return lth->text();
    }
public slots:
    virtual void widgetsShow();
    virtual ISPRModelData *getModel();
    virtual void viewChange(QColor color);
    virtual void viewChange();
    virtual void viewChange(int num);
    void hideCol(bool);
    void showCols(bool);
signals:
    void doShow();
    void rowSelected(int num);
    void rowChangeColor(int num);

};

#endif // SPRSPECTRUMLISTTABLE_H
