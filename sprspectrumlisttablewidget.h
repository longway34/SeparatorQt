#ifndef SPRSPECTRUMLISTTABLEWIDGET_H
#define SPRSPECTRUMLISTTABLEWIDGET_H

#include "ui_sprspectrumlisttablewidget.h"
//#include "models/

class SPRSpectrumListTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SPRSpectrumListTableWidget(QWidget *parent = 0);

private:
    Ui::SPRSpectrumListTableWidget ui;
};

#endif // SPRSPECTRUMLISTTABLEWIDGET_H
