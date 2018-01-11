#include "mainwindow.h"

#include <QApplication>

#include <QDomDocument>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{

    bool y = QDir::setCurrent("F:\\Projects\\Separator\\");
    QDomDocument doc;

    QFile in("СРФ3.xml");
    if(in.open(QIODevice::ReadOnly)){
        if(doc.setContent(&in)){

            in.close();

        }

    }

    QApplication a(argc, argv);

    MainWindow w(&doc);
    w.show();

    return a.exec();
}
