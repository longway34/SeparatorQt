#ifndef SPRSETTINGSRENTGENMAINWIDGET_H
#define SPRSETTINGSRENTGENMAINWIDGET_H

#include "ui_sprsettingsrentgenmainwidget.h"

class SPRSettingsRentgenMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSettingsRentgenMainWidget(QWidget *parent = 0);

private:
    Ui::SPRSettingsRentgenMainWidget ui;
};

#endif // SPRSETTINGSRENTGENMAINWIDGET_H
