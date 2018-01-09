//#include "algorithm"
#include <QSize>

#include <QLineEdit>
#include <QHeaderView>
#include <QFocusEvent>
#include <QFont>

#include "sprspectrumranges.h"

void SPRSpectrumRanges::setModel(SPRSpectrumRangesModel *value)
{
    model = value;
    if(model){
        this->clear();
        QStringList nameH; nameH << tr("<<") << tr(">>");
        setColumnCount(2);
        this->setHorizontalHeaderLabels(nameH);
        setRowCount(model->elements.size());
        setAlternatingRowColors(true);
//        setStyleSheet("alternate-background-color: rgb(201, 255, 198);");
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
            cell->setProperty("thread", model->tIndex);
            cell->setMaximumSize(std::max(fontMetrics().width("9999999"),fontMetrics().width(horizontalHeaderItem(0)->text())), 16777215);
            cell->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
            connect(cell, SIGNAL(editingFinished()), this, SLOT(viewChange()));
            tt = tr("Максимальное значение канала ")+
                    QString::number(model->tIndex)+tr(" елемента '") + DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].sname +"'";
            cell = setNumberCell(this, count, 1, model->elements[el].max->getData(), 0, MAX_SPR_SPECTOR_CHANNELS,tt);
            cell->setProperty("element", QVariant(el));
            cell->setProperty("thread", model->tIndex);
            cell->setMaximumSize(std::max(fontMetrics().width("9999999"),fontMetrics().width(horizontalHeaderItem(1)->text())), 16777215);
            cell->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
            connect(cell, SIGNAL(editingFinished()), this, SLOT(viewChange()));
    //        connect(cell, QWidget::focusInEvent(QFocusEvent * event), this, SLOT(onFocus(QFocusEvent*)));
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
}

QPoint SPRSpectrumRanges::getSelectedPosition()
{
    if(!focusWidget()){
        return QPoint(-1, -1);
    } else {
        QLineEdit *le = (QLineEdit*)focusWidget();
        EnumElements el = static_cast<EnumElements>(QVariant(le->property("element")).toInt());
        int row = DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].index;
        QWidget *wid = cellWidget(row, 0);
        int col = focusWidget() == cellWidget(row, 0) ? 0 : 1;
        return QPoint(row, col);
    }
}

EnumElements SPRSpectrumRanges::getSelectedElement(){
    if(!focusWidget()){
        return Ns;
    } else {
        QLineEdit *le = (QLineEdit*)focusWidget();
        EnumElements el = static_cast<EnumElements>(QVariant(le->property("element")).toInt());
        return el;
    }
}

//void SPRSpectrumRanges::viewChange(QTableWidget *table, int row, int col)
//{
//    if(model){
//        int value = ((QLineEdit*)(cellWidget(row, col)))->text().toInt();
//        QLineEdit *le = qobject_cast<QLineEdit*>(sender());
//        EnumElements element = static_cast<EnumElements>(QVariant(le->property("element")).toInt());
//        if(col == 0){ // изиенили минимум для канала
//           model->elements[element].min->setData(value);
//        } else if(col == 1){ // изиенили максимум для канала
//           model->elements[element].max->setData(value);
//        }
//        emit tableChange(this, row, col);
//        return;
//    }
//}

SPRSpectrumRanges::SPRSpectrumRanges(QWidget *parent) :
    QTableWidget(parent), model(nullptr)
{
}

void SPRSpectrumRanges::widgetsShow()
{
    if(model){
        foreach(EnumElements el, model->elements.keys()){
            int row = DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el].index;
            QLineEdit *le = (QLineEdit*)cellWidget(row, 0);
            le->setText(model->elements[el].min->toString());
            le = (QLineEdit*)cellWidget(row, 1);
            le->setText(model->elements[el].max->toString());
        }
    }
}

ISPRModelData *SPRSpectrumRanges::getModel()
{
    return model;
}

QSize SPRSpectrumRanges::sizeHint() const
{
    if(model){
        int h = this->horizontalHeader()->sizeHint().height();
        for(int i=0; i<model->elements.size(); i++){
            h += rowHeight(i);
        }

        int w = columnWidth(0) + columnWidth(1) + 3 * lineWidth();

        if(model->tIndex == 0){
            w += this->verticalHeader()->sizeHint().width() + lineWidth();
        }

        QSize res(w,h);
        return res;
    } else {
        return QTableWidget::sizeHint();
    }
}


void SPRSpectrumRanges::viewChange()
{
    QTableWidget *tw = sender()->property("tw").value<QTableWidget*>();
    QLineEdit *le = (QLineEdit*)sender();
    if(tw == this){
        EnumElements element = le->property("element").value<EnumElements>();
        int row = le->property("row").toInt();
        int col = le->property("col").toInt();
        uint value = le->text().toInt();
        if(col == 0){ // изиенили минимум для канала
           model->elements[element].min->setData(value);
        } else if(col == 1){ // изиенили максимум для канала
           model->elements[element].max->setData(value);
        }
        emit tableChange(this, row, col);

//        viewChange(tw, row, col);
    }
}
