#ifndef SPRSETTINGSRENTGENAUTOSETWIDGET_H
#define SPRSETTINGSRENTGENAUTOSETWIDGET_H

#include "ui_sprsettingsrentgenautosetwidget.h"

class SPRSettingsRentgenAutosetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSettingsRentgenAutosetWidget(QWidget *parent = 0);

private:
    Ui::SPRSettingsRentgenAutosetWidget ui;
};

#endif // SPRSETTINGSRENTGENAUTOSETWIDGET_H
