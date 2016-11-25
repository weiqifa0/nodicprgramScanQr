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
    ui->labelcolour->setVisible(false);
    ui->groupBox_3->setVisible(false);//
    //ui->labelcolour->setPixmap(QPixmap("E:\\project\\github\\nodicprgramScanQr\\NodicProgram\\image\\blue1.png"));
    //this->setFixedSize( this->width(),this->height());//设置窗体固定大小，不能改变窗体大小
}

MainWindow::~MainWindow()
{
    delete ui;
}
#define MAC_IN_LENGTH 16
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    static int changInt=0;
    qDebug()<<arg1;    qDebug()<<ui->lineEdit->text();
    if(ui->lineEdit->text().length() < MAC_IN_LENGTH)
    {
        return;
    }

    QPalette pal;
    pal = ui->textBrowser->palette();
    pal.setColor(QPalette::Base, Qt::white);//背景色设置成白色
    ui->textBrowser->setPalette(pal);
    ui->textBrowser->clear();//清空显示
    ui->groupBox_3->setVisible(false);//先不显示
    //把mac地址保存到文件里面
    QFile file("TS102_QR_16MACFILE.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
    {
        QTextStream stream( &file );
        stream << ui->lineEdit->text().left(16) << "\r\n";
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
        return;
    }
    if(ui->lineEdit->text().length()>=(MAC_IN_LENGTH+1))
    {
        ui->textBrowser->append("输入MAC长度有误!!!!");
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        return;
    }
    //提示颜色
    if(ui->lineEdit->text().mid(C_MAC_STRING,1)=="3")
    {
        ui->labelcolour->setPixmap(QPixmap("image\\blue1.png"));
        ui->labelcolour->setVisible(true);
        ui->groupBox_3->setVisible(true);//
        ui->textBrowser->append("###################[  蓝色  ]########################");
    }
    else if(ui->lineEdit->text().mid(C_MAC_STRING,1)=="1")
    {
        ui->labelcolour->setPixmap(QPixmap("image\\pink1.png"));
        ui->labelcolour->setVisible(true);
        ui->groupBox_3->setVisible(true);//
        ui->textBrowser->append("###################[  粉色  ]########################");
    }
    else if(ui->lineEdit->text().mid(C_MAC_STRING,1)=="2")
    {
        ui->labelcolour->setPixmap(QPixmap("image\\yellow1.png"));
        ui->labelcolour->setVisible(true);
        ui->groupBox_3->setVisible(true);//
        ui->textBrowser->append("###################[  黄色  ]########################");
    }
    else
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->labelcolour->setPalette(pa);
        ui->labelcolour->setText("不识别该颜色");
        ui->label->setText("失败");
        ui->textBrowser->append("###################[  不识别该颜色  ]########################");
        return;
    }

    ui->textBrowser->append(ui->lineEdit->text());
    //##############关键代码，获取MAC地址###############
    QByteArray macValue=ui->lineEdit->text().mid(4,8).toLatin1();
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
    qDebug()<<readCmd.indexOf("ERROR");//输出-1就是没有ERROR在这个字符串里面
    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("失败");
        if(readCmd.contains("no debugger"))
        {
            pal = ui->textBrowser->palette();
            pal.setColor(QPalette::Base, Qt::red);//背景色设置成红色
            ui->textBrowser->setPalette(pal);
            ui->textBrowser->append("电脑没有连接烧录器[nrfjprog.exe -i]查看电脑有没有烧录器");
        }
        else if(readCmd.contains("not erased"))
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
    changInt++;
    ui->label->setText("写入成功\r\n"+QString::number(changInt, 10));

    ui->textBrowser->append("写入成功####################["+ui->lineEdit->text()+"]########第 ["+QString::number(changInt)+"] 次");
    //向flash0x10001098写入值
    if(ui->checkBox->isChecked()==true)
    {
        p.start("nrfjprog.exe --memwr 0x10001098 --val 0x31303230");
        p.waitForStarted();
        p.waitForFinished();
        readCmd = p.readAllStandardOutput();
        readCmd+= p.readAllStandardError();
        ui->textBrowser->append(readCmd);
        if(readCmd.contains("not erased"))
        {
            ui->textBrowser->append("写FLASH命令执行出错!!!!");
        }
        qDebug()<<"nrfjprog.exe --memwr 0x10001098 --val 0x31303230";
    }
    //复位
    p.start("nrfjprog.exe -r");
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    ui->textBrowser->append(readCmd);
    if(readCmd.contains("ERROR"))
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

void MainWindow::on_commandLinkButton_2_clicked()
{
    QProcess p(0);
    QByteArray readCmd;
    //读取MAC地址
    p.start("nrfjprog.exe --memrd 0x10001090");
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    ui->textBrowser->append(readCmd);
    QString sReadMac=QString(readCmd);
    qDebug()<<sReadMac.mid(12,8);

    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("读MAC失败");
        ui->textBrowser->append("命令复位执行出错!!!!");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        return;
    }
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    ui->label->setPalette(pa);
    ui->label->setText("读取成功");
    ui->textBrowser->append("[读取的MAC地址是]DD54"+sReadMac.mid(12,8));
}

void MainWindow::on_commandLinkButton_clicked()
{
    QProcess p(0);
    QByteArray readCmd;
    //读取MAC地址
    p.start("nrfjprog.exe --memrd 0x10001098");
    p.waitForStarted();
    p.waitForFinished();
    readCmd = p.readAllStandardOutput();
    readCmd+= p.readAllStandardError();
    ui->textBrowser->append(readCmd);
    QString sReadMac=QString(readCmd);
    qDebug()<<sReadMac.mid(12,8);

    if(readCmd.indexOf("ERROR")>=0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa);
        ui->label->setText("读FLASH失败");
        ui->textBrowser->append("命令复位执行出错!!!!");
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->clear();
        return;
    }
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    ui->label->setPalette(pa);
    ui->label->setText("读取成功");
    ui->textBrowser->append("[Flash]"+sReadMac.mid(12,8));
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    qDebug()<<checked;
    if(checked)
    {
        ui->textBrowser->append("写入flash参数");
    }
    else
    {
        ui->textBrowser->append("不写入flash参数");
    }
}
