#ifndef SPRSETTINGSRENTGENCONTROLWIDGET_H
#define SPRSETTINGSRENTGENCONTROLWIDGET_H

#include "ui_sprsettingsrentgencontrolwidget.h"

class SPRSettingsRentgenControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSettingsRentgenControlWidget(QWidget *parent = 0);

private:
    Ui::SPRSettingsRentgenControlWidget ui;
};

#endif // SPRSETTINGSRENTGENCONTROLWIDGET_H
