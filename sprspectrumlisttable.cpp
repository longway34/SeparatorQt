#include "sprspectrumlisttable.h"
#include <QLabel>

void SPRSpectrumListTable::addRowTable(SpectrumData *data, int pastRow)
{
    int row = 0;
    if(pastRow >= 0 && pastRow < rowCount() - 1){
        insertRow(pastRow);
        row = pastRow + 1;
    } else {
        insertRow(this->rowCount());
        row = rowCount() - 1;
    }

    FirstColumn *fc = new FirstColumn(this);
    int r = *data->red;
    int g = *data->green;
    int b = *data->blue;
    QColor col(r,g,b);
    fc->setColor(col);
    fc->setNumber(rowCount());
    fc->setProperty("row", QVariant(row));
    QVariant vtw; vtw.setValue<QTableWidget*>(this);
    fc->setProperty("tw",vtw);
    connect(fc, SIGNAL(changeColor(QColor)), this, SLOT(viewChange(QColor)));
    connect(this, SIGNAL(doShow()), fc, SLOT(widgetsShow()));
    setCellWidget(row, 0, fc);

    setCellMyWidget(this, row, 1, QString::number(*data->thread), false, tr("Номер ручья"));
    setCellMyWidget(this, row, 2, QString(data->name), true, tr("Номер ручья"));
    setCellMyWidget(this, row, 3, QString::number(*data->summ), false, tr("Номер ручья"));
    setCellMyWidget(this, row, 4, QString::number(*data->H1, 'f', 4), false, tr("Расчетный параметр H1"));
    setCellMyWidget(this, row, 5, QString::number(*data->H2, 'f', 4), false, tr("Расчетный параметр H2"));
    setCellMyWidget(this, row, 6, QString::number(*data->H3, 'f', 4), false, tr("Расчетный параметр H3"));
    setCellMyWidget(this, row, 7, QString::number(*data->center, 'f', 0), false, tr(""));
    QString tt; tt.sprintf("Канал максимального значения спектра (%d)", *data->peak_value);
    setCellMyWidget(this, row, 8, QString::number(*data->peak), false, tr(tt.toStdString().c_str()));
    setCellMyWidget(this, row, 9, QString::number(*data->Rs, 'f', 0), false, tr(""));
    setCellMyWidget(this, row, 10, QString::number(*data->time, 'f', 0), false, tr("Количество секунд измерения спектра"));
    QString date; date.sprintf("%02d.%02d.%4d %02d:%02d:%02d",
                               *data->day, *data->month, *data->year,
                               *data->hours, *data->min, *data->sec);

    setCellMyWidget(this, row, 11, date, false, tr("Дита и время измерения спектра"));
    setCellMyWidget(this, row, 12, QString::number(*data->Ns), false, tr("Значения спектра в зоне рассеенки"));
    setCellMyWidget(this, row, 13, QString::number(*data->Fe), false, tr("Значения спектра в зоне железа"));
    setCellMyWidget(this, row, 14, QString::number(*data->Cu), false, tr("Значения спектра в зоне меди"));
    setCellMyWidget(this, row, 15, QString::number(*data->Mo), false, tr("Значения спектра в зоне молибдена"));
    setCellMyWidget(this, row, 16, QString::number(*data->Zn), false, tr("Значения спектра в зоне цинка"));
    setCellMyWidget(this, row, 17, QString::number(*data->Mg), false, tr("Значения спектра в зоне марганца"));

}

QLineEdit *SPRSpectrumListTable::setCellMyWidget(QTableWidget *table, int row, int col, QString value, bool editable, QString tt)
{
    QWidget *wid;
    QAction *actHide = new QAction(tr("Скрыть эту колонку"), this);
//    actHide->setData(col);
    connect(actHide, SIGNAL(triggered(bool)), this, SLOT(hideCol(bool)));
    QAction *actShow = new QAction(tr("Отобразить все"), this);
    connect(actShow, SIGNAL(triggered(bool)), this, SLOT(showCols(bool)));

    if(editable){
       QLineEdit *le = new QLineEdit(value);
       le->setFrame(false);
       connect(le, SIGNAL(editingFinished()), this, SLOT(viewChange()));
       le->setAlignment(Qt::AlignCenter); le->setTextMargins(3, 2, 3, 2);
       le->addAction(actHide); le->addAction(actShow);
       le->setContextMenuPolicy(Qt::ActionsContextMenu);
       wid = le;
    } else {
        QLabel *la = new QLabel(value);
        la->setAlignment(Qt::AlignCenter); la->setMargin(2);
//        la->addAction(actHide); la->addAction(actShow);
//        la->setContextMenuPolicy(Qt::ActionsContextMenu);
        wid = la;
    }
    QVariant vtw; vtw.setValue<QTableWidget*>(table);

    wid->setProperty("tw", vtw);
    wid->setProperty("row", QVariant(row)); wid->setProperty("col", QVariant(col));
    wid->setToolTip(tt);
    wid->setEnabled(editable);
//    le->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    setCellWidget(row, col, wid);
//    cellWidget(row, col)->addAction(actHide); cellWidget(row, col)->addAction(actShow);
}

SPRSpectrumListTable::SPRSpectrumListTable(QWidget *parent): QTableWidget(parent)
{
    QStringList hTitles;
    hTitles << tr("№") << tr("Ручей") << tr("Имя") << tr("I") << tr("H1") << tr("H2") << tr("H3")
            << tr("Центр") << tr("Пик") << tr("Rs") << tr("Время") << tr("Дата и время")
            << tr("Ns") << tr("Fe") << tr("Cu") << tr("Mo") << tr("Zn") << tr("Mg");

    setColumnCount(18);
    setHorizontalHeaderLabels(hTitles);
//    verticalHeader()->setVisible(false);
    horizontalHeader()->setSectionsMovable(true);
    verticalHeader()->setSectionsMovable(true);

    QAction *actHide = new QAction(tr("Скрыть эту колонку"), this);
    connect(actHide, SIGNAL(triggered(bool)), this, SLOT(hideCol(bool)));
    QAction *actShow = new QAction(tr("Отобразить все"), this);
    connect(actShow, SIGNAL(triggered(bool)), this, SLOT(showCols(bool)));

    this->addAction(actHide); this->addAction(actShow);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

ISPRModelData *SPRSpectrumListTable::setModel(QFile *inp, SPRSpectrumRangesTableModel *ranges)
{
    if(inp){
        uint8_t buf[DEF_SPECTRUM_DATA_BUF_LENGTH];
        if(!ranges){
            if(model.size() > 0){
                ranges = model[0]->getRangesTable();
            }
        }
        if(inp->open(QIODevice::ReadOnly)){
            char b[2];
           inp->read(b, 2);
            while(inp->read((char*)(buf), DEF_SPECTRUM_DATA_BUF_LENGTH)){
                SPRSpectrumItemModel *mod = new SPRSpectrumItemModel(ranges);
                mod->setSpData(buf);
                model.push_back(mod);
                addRowTable(mod->getSpData());
            }
        }
    }
    resizeColumnsToContents();

    return ranges;
}


void SPRSpectrumListTable::widgetsShow()
{
    for(int row=0; row < rowCount(); row++){
        SpectrumData *mod = model[row]->getSpData();
        FirstColumn *fc = ((FirstColumn*)cellWidget(row, 0));
        QColor col(*mod->red, *mod->green, *mod->blue);
        fc->setData(row, col);

        ((QLabel*)cellWidget(row, 1))->setText(QString::number(*mod->thread));
        ((QLineEdit*)cellWidget(row, 2))->setText(QString(mod->name));
        ((QLabel*)cellWidget(row, 3))->setText(QString::number(*mod->summ));
        ((QLabel*)cellWidget(row, 4))->setText(QString::number(*mod->H1, 'f', 4));
        ((QLabel*)cellWidget(row, 5))->setText(QString::number(*mod->H2, 'f', 4));
        ((QLabel*)cellWidget(row, 6))->setText(QString::number(*mod->H3, 'f', 4));
        ((QLabel*)cellWidget(row, 7))->setText(QString::number(*mod->center, 'f', 0));
        ((QLabel*)cellWidget(row, 8))->setText(QString::number(*mod->peak));
        ((QLabel*)cellWidget(row, 9))->setText(QString::number(*mod->Rs, 'f', 0));
        ((QLabel*)cellWidget(row, 10))->setText(QString::number(*mod->time, 'f', 0));
        QString date; date.sprintf("%02d.%02d.%4d %02d:%02d:%02d",
                                   *mod->day, *mod->month, *mod->year,
                                   *mod->hours, *mod->min, *mod->sec);
        ((QLabel*)cellWidget(row, 11))->setText(date);
        ((QLabel*)cellWidget(row, 12))->setText(QString::number(*mod->Ns));
        ((QLabel*)cellWidget(row, 13))->setText(QString::number(*mod->Fe));
        ((QLabel*)cellWidget(row, 14))->setText(QString::number(*mod->Cu));
        ((QLabel*)cellWidget(row, 15))->setText(QString::number(*mod->Mo));
        ((QLabel*)cellWidget(row, 16))->setText(QString::number(*mod->Zn));
        ((QLabel*)cellWidget(row, 17))->setText(QString::number(*mod->Mg));
    }
}

ISPRModelData *SPRSpectrumListTable::getModel()
{
    if(model.size() > 0){
        return model[0]->getRangesTable();
    }
    return nullptr;
}

void SPRSpectrumListTable::viewChange(QColor color)
{
    if(sender()->property("tw").value<QTableWidget*>() == this){
        int row = sender()->property("row").toInt();

        *model[row]->getSpData()->red = color.red();
        *model[row]->getSpData()->green = color.green();
        *model[row]->getSpData()->blue = color.blue();
    }
}

void SPRSpectrumListTable::viewChange()
{
    if(sender()->property("tw").value<QTableWidget*>() == this){
        int row = sender()->property("row").toInt();
        SpectrumData *data = model[row]->getSpData();
        const char *value = ((QLineEdit*)sender())->text().toStdString().c_str();
//        int len = ((QLineEdit*)sender())->text().length();
        strcpy(data->name, value);
    }
}

void SPRSpectrumListTable::hideCol(bool)
{
    hideColumn(currentColumn());
}

void SPRSpectrumListTable::showCols(bool)
{
    for(int col=0; col < columnCount(); col++){
        showColumn(col);
    }

}
