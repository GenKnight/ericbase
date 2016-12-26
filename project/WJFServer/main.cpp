#include "Dialog.h"
#include <QTextCodec>
#include "MyApplication.h"

int main(int argc, char *argv[])
{
	MyApplication app(argc, argv, false);
	QString app_path = app.applicationDirPath();
	app_path += QString("/plugins");
	app.addLibraryPath(app_path);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	app.Init();

	Dialog w;
	QObject::connect(&app, SIGNAL(SignalInfo(QString)), &w, SLOT(SlotShowInfo(QString)), Qt::QueuedConnection);
	QObject::connect(&w, SIGNAL(SignalDoAfterMarket()), &app, SLOT(SlotDoAfterMarket()));
	w.show();
	return app.exec();
}
