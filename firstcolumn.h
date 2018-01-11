#ifndef FIRSTCOLUMN_H
#define FIRSTCOLUMN_H

#include "ui_firstcolumn.h"
#include <QColorDialog>
#include "isprwidget.h"

class FirstColumn : public QWidget, public ISPRWidget
{
    Q_OBJECT

    QColor color;
    int num;
public:
    explicit FirstColumn(QWidget *parent = 0);

    QColor getMyColor(){return color;}
    int getMyNum(){return num;}
    void setData(int num, QColor(color)){
        setNumber(num);
        setColor(color);
    }

    void setColor(QColor _color){
        color = _color;
//        QString gradFormat = "QPushButton{background-color: qlineargradient(spread:pad, x0: 0, y1: 0, x2: 0, y2: 0.5, x3: 0, y3: 1,"
//                "stop: 0 rgba(%d, %d, %d, 64),"
//                "stop: 1 rgba(%d, %d, %d, 255),"
//                "stop: 2 rgba(%d, %d, %d, 64)); border-radius: 3px; border: 1px solid #8f8f91}";
//        QString gradFormatPress = "QPushButton:pressed{background-color: qlineargradient(spread:pad, x0: 0, y1: 0, x2: 0, y2: 0.5, x3: 0, y3: 1,"
//                "stop: 0 rgba(%d, %d, %d, 128),"
//                "stop: 1 rgba(%d, %d, %d, 255),"
//                "stop: 2 rgba(%d, %d, %d, 128)); border: 2px solid #8f8f91}";
//        QString gradFormatHover = "QPushButton:hover{background-color: qlineargradient(spread:pad, x0: 0, y1: 0, x2: 0, y2: 0.5, x3: 0, y3: 1,"
//                "stop: 0 rgba(%d, %d, %d, 64),"
//                "stop: 1 rgba(%d, %d, %d, 128),"
//                "stop: 2 rgba(%d, %d, %d, 255))}";

//        QString ssh; ssh.sprintf(gradFormat.toStdString().c_str(), color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue());
//        QString sshp; sshp.sprintf(gradFormatPress.toStdString().c_str(), color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue());
//        QString sshph; sshph.sprintf(gradFormatHover.toStdString().c_str(), color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue(),
//                                             color.red(), color.green(), color.blue());

//        ssh += sshp + sshph;
//        ui.bColor->setStyleSheet(ssh);
        ui.bColor->setColor(color);
//        setNumber(ui.lNumber->text().toInt());
        setNumber(ui.cbSelect->text().toInt());

    }
    void setNumber(int num){
        this->num = num;
//        QPalette pal = ui.lNumber->palette();
        QPalette pal = ui.cbSelect->palette();
//        pal.setColor(ui.lNumber->foregroundRole(), this->getMyColor());
        pal.setColor(ui.cbSelect->foregroundRole(), this->getMyColor());
//        ui.lNumber->setPalette(pal);
//        ui.lNumber->setText(QString::number(this->num));
//        ui.lNumber->update();
        ui.cbSelect->setPalette(pal);
        ui.cbSelect->setText(QString::number(this->num));
        ui.cbSelect->update();
    }
public slots:
    void onColorClick(QColor color){
        setColor(color);
    }
    void onDeleteClick(bool val){
        emit iAmDelete(val);
    }
    void onSelectClick(bool val){
        emit iAmSelected(val);
    }
    virtual void widgetsShow();
signals:
    void iAmSelected(bool);
    void iAmDelete(bool);
    void changeColor(QColor);
private:
    Ui::FirstColumn ui;

    // ISPRWidget interface
public:
    virtual ISPRModelData *getModel(){return nullptr;}
};

#endif // FIRSTCOLUMN_H
