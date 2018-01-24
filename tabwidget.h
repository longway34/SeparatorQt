#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "ui_tabwidget.h"

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);

private:
    Ui::TabWidget ui;
};

#endif // TABWIDGET_H
