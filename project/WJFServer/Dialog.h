#ifndef TEST1_H
#define TEST1_H

#include <QtGui/QWidget>
#include "ui_Dialog.h"

class Dialog : public QWidget
{
	Q_OBJECT

public:
	Dialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Dialog();

	static Dialog* g_dlg;

public slots:
	void SlotShowInfo(QString str);
	void SlotClear();

	void ShowInfo(QString& str);

signals:
	void SignalDoAfterMarket();
	void SigShowInfo(QString);

private:
	Ui::Dialog ui;
};

#endif // TEST1_H
