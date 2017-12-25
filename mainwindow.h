#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDomDocument>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QDomDocument document;
    QDomDocument *doc;

public:
    explicit MainWindow(QWidget *parent = 0);

    MainWindow(QDomDocument *_doc, QWidget *parent = 0);
private:
    Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
