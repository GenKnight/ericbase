#ifndef LOGINWIGET_H
#define LOGINWIGET_H

#include <QtGui/QWidget>
#include "ui_loginwiget.h"

class LoginWiget : public QWidget
{
	Q_OBJECT

public:
	LoginWiget(QWidget *parent = 0, Qt::WFlags flags = 0);
	~LoginWiget();

private:
	Ui::LoginWigetClass ui;
};

#endif // LOGINWIGET_H
