#include "sprsettingsporogswidget.h"

ISPRModelData *SPRSettingsPorogsWidget::setModel(ISPRModelData *value)
{
    model = (SPRSettingsPorogsModel*)value;
    ui.wPorogs->setModel(new SPRPorogsModel(model->getDoc()));
    widgetsShow();
    return model;
}

void SPRSettingsPorogsWidget::repaintGraphic(double)
{
    QVector<QPointF> grData = {
        {0, ui.leMinStone->value() * 10},
        {15, ui.leMinStone->value() * 10},
        {100, ui.leMaxStone->value() * 10},
        {115, ui.leMaxStone->value() * 10}
    };

//    double x[] = {0, 15, 100, 115};
//    double y[] = {ui.leMinStone->value() * 10,
//                 ui.leMinStone->value() * 10,
//                 ui.leMaxStone->value() * 10,
//                 ui.leMaxStone->value() * 10};


    curve->setSamples(grData);
    ui.plotKoeffLengths->replot();
}

SPRSettingsPorogsWidget::SPRSettingsPorogsWidget(QWidget *parent) :
    QWidget(parent), ISPRWidget()
{
    ui.setupUi(this);
    ui.wPorogs->ui.gbPorogs->setTitle("");

    bgTypeSelection = new QButtonGroup(this);
    bgTypeSelection->addButton(ui.rbTail, 0);
    bgTypeSelection->addButton(ui.rbConcentrat, 1);

    curve = new QwtPlotCurve(tr("Коэффициеты"));
    curve->setPen(QColor(Qt::red), 2, Qt::SolidLine);
    curve->attach(ui.plotKoeffLengths);

    grid = new QwtPlotGrid();
    grid->enableXMin(true);
    grid->setMajorPen(QColor(Qt::black), 0.1, Qt::DotLine);
    grid->setMinorPen(QColor(Qt::gray), 0.1, Qt::DotLine);
    grid->attach(ui.plotKoeffLengths);

    connect(ui.leMaxStone, SIGNAL(valueChanged(double)), SLOT(repaintGraphic(double)));
    connect(ui.leMaxStone, SIGNAL(valueChanged(double)), SLOT(viewChange(double)));
    connect(ui.leMinStone, SIGNAL(valueChanged(double)), SLOT(repaintGraphic(double)));
    connect(ui.leMinStone, SIGNAL(valueChanged(double)), SLOT(viewChange(double)));

    connect(bgTypeSelection, SIGNAL(buttonClicked(int)), SLOT(viewChange(int)));
    connect(ui.leXRayCorrection, SIGNAL(valueChanged(double)), SLOT(viewChange(double)));

}

void SPRSettingsPorogsWidget::widgetsShow()
{
    ui.leMinStone->setValue(model->forMinStone->getData());
    ui.leMaxStone->setValue(model->forMaxStone->getData());
    ui.leXRayCorrection->setValue(model->xRayCorrection->getData());

    TypeSelection type = model->typeSelection->getData();
    if(type == OnConsentrate){
        ui.rbConcentrat->setChecked(true);
    } else {
        ui.rbTail->setChecked(true);
    }
    repaintGraphic(0);
    ui.wPorogs->widgetsShow();
}

ISPRModelData *SPRSettingsPorogsWidget::getModel()
{
    return model;
}

void SPRSettingsPorogsWidget::viewChange(int data)
{
    if(sender() == bgTypeSelection){ // изменили состояние сортировки хвост/концентрат
        TypeSelection val = static_cast<TypeSelection>(data);
        model->typeSelection->setData(val);
        return;
    }
}

void SPRSettingsPorogsWidget::viewChange(double data)
{
    if(sender() == ui.leMaxStone){ // изменили коэффициент для максимального камня
       double k = ui.leMaxStone->value();
       model->forMaxStone->setData(k);
    }
    if(sender() == ui.leMinStone){ // изменили коэффициент для минимального камня
        double k = ui.leMinStone->value();
        model->forMinStone->setData(k);
        return;
    }
    if(sender() == ui.leXRayCorrection){ // изменили коэффициент коррекции X-Ray
        double k = ui.leXRayCorrection->value();
        model->xRayCorrection->setData(k);
        return;
    }
}


void SPRSettingsPorogsWidget::viewChange(QTableWidget *, int, int)
{
}
