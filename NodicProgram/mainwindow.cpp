#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QDateTime>
#include <QProcess>
#include <mythread.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize( this->width(),this->height());//设置窗体固定大小，不能改变窗体大小
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    static int changInt=0;

    qDebug()<<ui->lineEdit->text();
    if(ui->lineEdit->text().length()<=3)
    {
        return;
    }
    changInt++;
    ui->textBrowser->append("输入文字有变化"+QString::number(changInt));
    if(!ui->lineEdit->text().startsWith("DD54"))
    {
        ui->textBrowser->append("输入MAC地址有误，请确认是否前面有DD54...");
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        return;
    }
    if(ui->lineEdit->text().length()!=12)
    {
        ui->textBrowser->append("输入MAC长度有误，请确认是否有12个字符");
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        return;
    }
    ui->textBrowser->append(ui->lineEdit->text());
    QByteArray macValue=ui->lineEdit->text().mid(4).toLatin1();
    qDebug()<<macValue;
    bool ok;
    int macValueInt=macValue.toInt(&ok,16);
    qDebug("%x",macValueInt);
    //调用cmd相关命令
    QByteArray readCmd;
    QProcess p(0);
    //擦除分区
    p.start("nrfjprog.exe --eraseuicr");
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    ui->textBrowser->append(readCmd);
    //写入数据
    QString cmdWriteValue="nrfjprog.exe --memwr 0x10001090 --val ";
    cmdWriteValue.append(QString::number(macValueInt));
    qDebug()<<cmdWriteValue;
    p.start(cmdWriteValue);
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    ui->textBrowser->append(readCmd);
    qDebug()<<readCmd.indexOf("ERROR");//输出-1就是没有ERROR在这个字符串里面
    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        ui->textBrowser->append("命令执行出错!!!!");
        return;
    }
    //提示
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    ui->label->setPalette(pa);
    ui->label->setText("写入成功");
    ui->textBrowser->append("写入成功############################第 ["+QString::number(changInt)+"] 次");
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_editingFinished()
{
}
