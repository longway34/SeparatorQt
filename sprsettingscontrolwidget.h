#ifndef SPRSETTINGSCONTROLWIDGET_H
#define SPRSETTINGSCONTROLWIDGET_H

#include "ui_sprsettingscontrolwidget.h"

class SPRSettingsControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSettingsControlWidget(QWidget *parent = 0);

private:
    Ui::SPRSettingsControlWidget ui;
};

#endif // SPRSETTINGSCONTROLWIDGET_H
