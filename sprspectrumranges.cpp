//#include "algorithm"
#include <QSize>
#include "QLineEdit"
#include "QHeaderView"
#include "sprspectrumranges.h"

void SPRSpectrumRanges::setModel(SPRSpectrumRangesModel *value)
{
    model = value;
    this->clear();
    QStringList nameH; nameH << tr("<<") << tr(">>");
    setColumnCount(2);
    this->setHorizontalHeaderLabels(nameH);
    setRowCount(model->elements.size());
//    setRowCount(1);
    QStringList nameV;
    int count = 0;
    actualSize = QSize(0,horizontalHeader()->height());
    foreach(EnumElements el, model->elements.keys()){
        nameV.append(DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].sname);
        QString tt = tr("Минимальное значение канала для елемента'") +
                QString::number(model->tIndex)+tr(" елемента '") + DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].sname +"'";
        QLineEdit *cell = setNumberCell(this, count, 0, model->elements[el].min->getData(), 0, MAX_SPR_SPECTOR_CHANNELS,tt);
        cell->setProperty("element", QVariant(el));
        cell->setMaximumSize(std::max(fontMetrics().width("9999999"),fontMetrics().width(horizontalHeaderItem(0)->text())), 16777215);
        cell->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        connect(cell, SIGNAL(editingFinished()), this, SLOT(changeCellLe()));
        tt = tr("Максимальное значение канала ")+
                QString::number(model->tIndex)+tr(" елемента '") + DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].sname +"'";
        cell = setNumberCell(this, count, 1, model->elements[el].max->getData(), 0, MAX_SPR_SPECTOR_CHANNELS,tt);
        cell->setProperty("element", QVariant(el));
        cell->setMaximumSize(std::max(fontMetrics().width("9999999"),fontMetrics().width(horizontalHeaderItem(1)->text())), 16777215);
        cell->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        connect(cell, SIGNAL(editingFinished()), this, SLOT(changeCellLe()));
        actualSize.setHeight(actualSize.height()+rowHeight(count));
        if(count == 0){
            actualSize.setWidth(columnWidth(0) * 2);
        }
        count++;
    }
    if(model->tIndex == 0){
        this->setVerticalHeaderLabels(nameV);
        actualSize.setWidth(actualSize.width() + verticalHeader()->size().width());
    } else {
//        this->setVerticalHeader(nullptr);
        this->verticalHeader()->setVisible(false);
    }
    resizeColumnsToContents();
    resizeRowsToContents();

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QPoint SPRSpectrumRanges::getSelectedPosition()
{
    if(!focusWidget()){
        return QPoint(-1, -1);
    } else {
        QLineEdit le = (QLineEdit*)focusWidget();
        EnumElements el = static_cast<EnumElements>(le.property("element"));
        int row = DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].index;
        int col = focusWidget() == cellWidget(row, 0) ? 0 : 1;
        return QPoint(row, col);
    }
}

EnumElements SPRSpectrumRanges::getSelectedElement(){
    if(!focusWidget()){
        return QPoint(-1, -1);
    } else {
        QLineEdit le = (QLineEdit*)focusWidget();
        EnumElements el = static_cast<EnumElements>(le.property("element"));
        return el;
    }
}

void SPRSpectrumRanges::changeCellLe()
{
    QLineEdit *le = qobject_cast<QLineEdit*>(sender());
    QTableWidget *tw = qobject_cast<QTableWidget*>(le->parentWidget()->parentWidget());
    int row = le->property("row").toInt();
    int col = le->property("col").toInt();
    viewChange(tw, row, col);
}

void SPRSpectrumRanges::viewChange(QTableWidget *table, int row, int col)
{
    int value = ((QLineEdit*)(cellWidget(row, col)))->text().toInt();
    QLineEdit *le = qobject_cast<QLineEdit*>(sender());
    EnumElements element = static_cast<EnumElements>(QVariant(le->property("element")).toInt());
    if(col == 0){ // изиенили минимум для канала
       model->elements[element].min->setData(value);
    } else if(col == 1){ // изиенили максимум для канала
       model->elements[element].min->setData(value);
    }
    emit tableChange(this, row, col);
    return;
}

SPRSpectrumRanges::SPRSpectrumRanges(QWidget *parent) :
    QTableWidget(parent)
{
    model = nullptr;

}

void SPRSpectrumRanges::widgetsShow()
{
}

ISPRModelData *SPRSpectrumRanges::getModel()
{
    return model;
}

QSize SPRSpectrumRanges::sizeHint() const
{
    QSize s = QTableWidget::sizeHint();

    int h = this->horizontalHeader()->sizeHint().height();
    for(int i=0; i<model->elements.size(); i++){
        h += rowHeight(i);
    }

.    int w = columnWidth(0) + columnWidth(1) + 2 * lineWidth();

    if(model->tIndex == 0){
        w += this->verticalHeader()->sizeHint().width() + lineWidth();
    }

    QSize res(w,h);
    return res;
}
