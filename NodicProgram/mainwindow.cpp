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
    if(ui->lineEdit->text().length()<=11)
    {
        return;
    }

    QPalette pal;
    pal = ui->textBrowser->palette();
    pal.setColor(QPalette::Base, Qt::white);//背景色设置成白色
    ui->textBrowser->setPalette(pal);
    ui->textBrowser->clear();//清空显示
    //把mac地址保存到文件里面
    QFile file("Qrlog.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
    {
        QTextStream stream( &file );
        stream << ui->lineEdit->text() << "\r\n";
        file.close();
    }
    else
    {
        ui->textBrowser->append(tr("打开文件失败..."));
    }
    if((!ui->lineEdit->text().startsWith("dd54"))&&(!ui->lineEdit->text().startsWith("DD54")))
    {
        ui->textBrowser->append("输入MAC地址有误，请确认是否前面有DD54...");
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
        {
            QTextStream stream( &file );
            stream << "输入MAC地址有误，请确认是否前面有DD54..." << "\r\n";
            stream << "失败" << "\r\n";
            stream << ui->lineEdit->text() << "\r\n";
            file.close();
        }
        else
        {
            ui->textBrowser->append(tr("打开文件失败..."));
        }

        return;
    }
    if(ui->lineEdit->text().length()!=12)
    {
        ui->textBrowser->append("输入MAC长度有误，请确认是否有12个字符");
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
        {
            QTextStream stream( &file );
            stream << "输入MAC长度有误，请确认是否有12个字符" << "\r\n";
            stream << "失败" << "\r\n";
            stream << ui->lineEdit->text() << "\r\n";
            file.close();
        }
        else
        {
            ui->textBrowser->append(tr("打开文件失败..."));
        }
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
    if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
    {
        QTextStream stream( &file );
        stream << readCmd << "\r\n";
        file.close();
    }
    else
    {
        ui->textBrowser->append(tr("打开文件失败..."));
    }
    qDebug()<<readCmd.indexOf("ERROR");//输出-1就是没有ERROR在这个字符串里面
    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        if(readCmd.indexOf("not erased"))
        {
            pal = ui->textBrowser->palette();
            pal.setColor(QPalette::Base, Qt::red);//背景色设置成红色
            ui->textBrowser->setPalette(pal);
            ui->textBrowser->append("已经写入MAC地址，如果要重新写入，请联系开发人员，[nrfjprog.exe --eraseuicr]后，用nrfgo重新烧录bootloader.");
        }
        else
        {
            pal = ui->textBrowser->palette();
            pal.setColor(QPalette::Base, Qt::red);//背景色设置成红色
            ui->textBrowser->setPalette(pal);
            ui->textBrowser->append("命令执行出错!!!!");
        }
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        return;
    }
    //提示
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    ui->label->setPalette(pa);
    ui->label->setText("写入成功");
    changInt++;
    ui->textBrowser->append("写入成功####################["+ui->lineEdit->text()+"]########第 ["+QString::number(changInt)+"] 次");
    //复位
    p.start("nrfjprog.exe -r");
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
    {
        QTextStream stream( &file );
        stream << readCmd << "\r\n";
        file.close();
    }
    else
    {
        ui->textBrowser->append(tr("打开文件失败..."));
    }
    ui->textBrowser->append(readCmd);
    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("复位失败");
        ui->textBrowser->append("命令复位执行出错!!!!");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        return;
    }
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_editingFinished()
{
}
