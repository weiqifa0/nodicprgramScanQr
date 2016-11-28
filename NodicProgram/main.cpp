#include "mainwindow.h"
#include <QApplication>
#include "mythread.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString runPath = QCoreApplication::applicationDirPath();
    w.setWindowTitle("TS102_V1.1.3_QR扫码生产工具["+runPath+"]");
    w.show();
    return a.exec();
}
