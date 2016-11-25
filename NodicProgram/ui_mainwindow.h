/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelcolour;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(944, 494);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(14);
        textBrowser->setFont(font);
        textBrowser->setMouseTracking(false);

        verticalLayout_3->addWidget(textBrowser);


        gridLayout->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        lineEdit->setFont(font1);

        verticalLayout->addWidget(lineEdit);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 233, 283));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 271, 341));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setTextFormat(Qt::PlainText);
        label->setIndent(1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        verticalLayout->addWidget(commandLinkButton);

        commandLinkButton_2 = new QCommandLinkButton(groupBox);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));

        verticalLayout->addWidget(commandLinkButton_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelcolour = new QLabel(groupBox_3);
        labelcolour->setObjectName(QStringLiteral("labelcolour"));
        labelcolour->setEnabled(true);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setWeight(50);
        labelcolour->setFont(font3);

        horizontalLayout->addWidget(labelcolour, 0, Qt::AlignHCenter);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\227\245\345\277\227", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt;\">1\343\200\201\345\256\211\350\243\205\344\272\206nRF5x-Command-Line-Tools_8_4_0_Installer.exe</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt;\">2\343\200\201\350\201\224\347\263\273QQ\357\274\232329410527 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimS"
                        "un'; font-size:9pt;\">3\343\200\201\347\211\210\346\234\254\357\274\232V1.2.0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt;\">4\343\200\201\345\221\275\344\273\244\357\274\232</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#008000;\">nrfjprog.exe</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#c0c0c0;\"> </span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#008000;\">--memwr</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#c0c0c0;\"> </span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#008000;\">0x10001090</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; f"
                        "ont-size:9pt; color:#c0c0c0;\"> </span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; color:#008000;\">--val</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\211\253\347\240\201\346\236\252\350\276\223\345\205\245", 0));
        checkBox->setText(QApplication::translate("MainWindow", "\345\220\2210x10001098\345\206\231\345\205\245\346\225\260\346\215\256", 0));
        label->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272", 0));
        commandLinkButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\2260x10001098\345\234\260\345\235\200\345\200\274", 0));
        commandLinkButton_2->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226TS102MAC\345\234\260\345\235\200", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\263\250\346\204\217USB\350\277\236\346\216\245\350\256\276\345\244\207\347\232\204\351\242\234\350\211\262\345\222\214\344\270\213\351\235\242\346\230\276\347\244\272\347\232\204\351\242\234\350\211\262\346\230\257\345\220\246\347\233\270\345\220\214", 0));
        labelcolour->setText(QApplication::translate("MainWindow", "\347\211\231\345\210\267\345\260\276\345\267\264\351\242\234\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
