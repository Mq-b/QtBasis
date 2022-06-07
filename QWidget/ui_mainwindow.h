/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_action;
    QAction *save_action;
    QWidget *centralwidget;
    QPushButton *moveBtn;
    QPushButton *positionBtn;
    QPushButton *geometryBtn;
    QPushButton *pushButton;
    QPushButton *modalDlg;
    QPushButton *msgbox;
    QPushButton *filedlg;
    QGroupBox *groupBox;
    QPushButton *colordlg;
    QLabel *color;
    QLabel *colorlabel;
    QPushButton *inputdlg;
    QPushButton *test;
    QPushButton *progressdlg;
    QGroupBox *groupBox_2;
    QLabel *fontlabel;
    QPushButton *fontdlg;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 688);
        MainWindow->setCursor(QCursor(Qt::CrossCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("/*font: 10pt \"\346\265\252\346\274\253\350\207\263\346\255\273\344\270\215\346\270\235\";*/"));
        open_action = new QAction(MainWindow);
        open_action->setObjectName(QString::fromUtf8("open_action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("3.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_action->setIcon(icon);
        save_action = new QAction(MainWindow);
        save_action->setObjectName(QString::fromUtf8("save_action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        save_action->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        moveBtn = new QPushButton(centralwidget);
        moveBtn->setObjectName(QString::fromUtf8("moveBtn"));
        moveBtn->setGeometry(QRect(60, 50, 101, 31));
        positionBtn = new QPushButton(centralwidget);
        positionBtn->setObjectName(QString::fromUtf8("positionBtn"));
        positionBtn->setGeometry(QRect(60, 100, 111, 31));
        geometryBtn = new QPushButton(centralwidget);
        geometryBtn->setObjectName(QString::fromUtf8("geometryBtn"));
        geometryBtn->setGeometry(QRect(50, 160, 211, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 220, 121, 41));
        modalDlg = new QPushButton(centralwidget);
        modalDlg->setObjectName(QString::fromUtf8("modalDlg"));
        modalDlg->setGeometry(QRect(50, 290, 131, 51));
        msgbox = new QPushButton(centralwidget);
        msgbox->setObjectName(QString::fromUtf8("msgbox"));
        msgbox->setGeometry(QRect(50, 360, 101, 51));
        filedlg = new QPushButton(centralwidget);
        filedlg->setObjectName(QString::fromUtf8("filedlg"));
        filedlg->setGeometry(QRect(70, 430, 51, 101));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        filedlg->setIcon(icon2);
        filedlg->setIconSize(QSize(100, 100));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(330, 0, 391, 211));
        groupBox->setStyleSheet(QString::fromUtf8("/*background-color:rgb(255, 172, 172)*/"));
        colordlg = new QPushButton(groupBox);
        colordlg->setObjectName(QString::fromUtf8("colordlg"));
        colordlg->setGeometry(QRect(10, 50, 101, 41));
        colordlg->setStyleSheet(QString::fromUtf8(""));
        color = new QLabel(groupBox);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(200, 50, 141, 41));
        color->setStyleSheet(QString::fromUtf8("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0)/*\350\276\271\346\241\206\350\256\276\347\275\256*/"));
        colorlabel = new QLabel(groupBox);
        colorlabel->setObjectName(QString::fromUtf8("colorlabel"));
        colorlabel->setGeometry(QRect(0, 130, 391, 51));
        colorlabel->setStyleSheet(QString::fromUtf8("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0)/*\350\276\271\346\241\206\350\256\276\347\275\256*/"));
        colorlabel->setAlignment(Qt::AlignCenter);
        inputdlg = new QPushButton(centralwidget);
        inputdlg->setObjectName(QString::fromUtf8("inputdlg"));
        inputdlg->setGeometry(QRect(330, 250, 131, 41));
        test = new QPushButton(centralwidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(671, 240, 71, 61));
        test->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(3.png);\n"
"border-top: 1px transparent;\n"
"border-bottom: 1px transparent;\n"
"border-right: 7px transparent;\n"
"border-left: 7px transparent;\n"
"height:20px\n"
"} "));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        test->setIcon(icon3);
        test->setIconSize(QSize(70, 70));
        progressdlg = new QPushButton(centralwidget);
        progressdlg->setObjectName(QString::fromUtf8("progressdlg"));
        progressdlg->setGeometry(QRect(331, 318, 131, 41));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 380, 521, 161));
        fontlabel = new QLabel(groupBox_2);
        fontlabel->setObjectName(QString::fromUtf8("fontlabel"));
        fontlabel->setGeometry(QRect(10, 40, 361, 111));
        fontlabel->setMouseTracking(false);
        fontlabel->setStyleSheet(QString::fromUtf8("border:1px solid pink;/*\350\256\276\347\275\256\345\244\226\350\276\271\346\241\206*/\n"
"/*background-color:rgb(252, 239, 255);*//*\350\256\276\347\275\256\347\252\227\345\217\243\350\203\214\346\231\257\350\211\262*/\n"
"\n"
""));
        fontlabel->setScaledContents(false);
        fontdlg = new QPushButton(groupBox_2);
        fontdlg->setObjectName(QString::fromUtf8("fontdlg"));
        fontdlg->setGeometry(QRect(410, 40, 101, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(open_action);
        menu->addAction(save_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        open_action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        open_action->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        save_action->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        moveBtn->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\252\227\345\217\243", nullptr));
        positionBtn->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226\344\275\215\347\275\256\344\277\241\346\201\257", nullptr));
        geometryBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\347\232\204\344\275\215\347\275\256\345\222\214\345\260\272\345\257\270\344\277\241\346\201\257", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\240\207\351\242\230\345\222\214\345\233\276\346\240\207", nullptr));
        modalDlg->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        msgbox->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\346\241\206", nullptr));
#if QT_CONFIG(whatsthis)
        filedlg->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\277\231\346\230\257\344\270\200\344\270\252\351\200\211\346\213\251\347\233\256\345\275\225\347\232\204\346\214\211\351\222\256</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        filedlg->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262\351\200\211\346\213\251", nullptr));
        colordlg->setText(QCoreApplication::translate("MainWindow", "QColorDialog", nullptr));
        color->setText(QString());
        colorlabel->setText(QString());
        inputdlg->setText(QCoreApplication::translate("MainWindow", "QInputDialog", nullptr));
        test->setText(QString());
        progressdlg->setText(QCoreApplication::translate("MainWindow", "QProgressDialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\200\211\346\213\251", nullptr));
        fontlabel->setText(QCoreApplication::translate("MainWindow", "\346\210\221\346\230\257\350\246\201\346\210\220\344\270\272\346\265\267\350\264\274\347\216\213\347\232\204\347\224\267\344\272\272!!!", nullptr));
        fontdlg->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\200\211\346\213\251", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
