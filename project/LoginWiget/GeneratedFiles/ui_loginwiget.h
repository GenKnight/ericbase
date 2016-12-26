/********************************************************************************
** Form generated from reading UI file 'loginwiget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIGET_H
#define UI_LOGINWIGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWigetClass
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *LoginWigetClass)
    {
        if (LoginWigetClass->objectName().isEmpty())
            LoginWigetClass->setObjectName(QString::fromUtf8("LoginWigetClass"));
        LoginWigetClass->resize(600, 400);
        pushButton = new QPushButton(LoginWigetClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 160, 75, 23));

        retranslateUi(LoginWigetClass);

        QMetaObject::connectSlotsByName(LoginWigetClass);
    } // setupUi

    void retranslateUi(QWidget *LoginWigetClass)
    {
        LoginWigetClass->setWindowTitle(QApplication::translate("LoginWigetClass", "LoginWiget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LoginWigetClass", "ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginWigetClass: public Ui_LoginWigetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIGET_H
