#include "Dialog.h"
#include <QGraphicsEllipseItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QMovie>
#include <QLabel>
#include <QDateTime>

Dialog* Dialog::g_dlg = NULL;

Dialog::Dialog(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	connect(ui.clear_btn, SIGNAL(clicked()), this, SLOT(SlotClear()));
	connect(ui.close_mkt_task_btn, SIGNAL(clicked()), this, SIGNAL(SignalDoAfterMarket()));
	connect(this, SIGNAL(SigShowInfo(QString)), this, SLOT(SlotShowInfo(QString)), Qt::QueuedConnection);

	g_dlg = this;
}

Dialog::~Dialog()
{

}

void Dialog::SlotShowInfo(QString str)
{
	static int idx = 0;
	++idx;
	QDateTime now = QDateTime::currentDateTime();
	QString time_str = now.toString("yyyy-MM-dd hh:mm:ss");
	ui.textEdit->append(tr("%1>  %2  %3").arg(idx).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(str));
}

void Dialog::SlotClear()
{
	ui.textEdit->clear();
}

void Dialog::ShowInfo(QString& str)
{
	emit SigShowInfo(str);
}
