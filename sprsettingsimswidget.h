#ifndef SPRSETTINGSIMSWIDGET_H
#define SPRSETTINGSIMSWIDGET_H

#include "ui_sprsettingsimswidget.h"

class SPRSettingsIMSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSettingsIMSWidget(QWidget *parent = 0);

private:
    Ui::SPRSettingsIMSWidget ui;
};

#endif // SPRSETTINGSIMSWIDGET_H
