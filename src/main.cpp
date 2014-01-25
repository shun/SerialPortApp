#include <QDeclarativeView>
#include <QApplication>
#include "SerialPortClient.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

	QDeclarativeView *view = new QDeclarativeView();
	view->setSource(QUrl::fromLocalFile("./qml/main.qml"));
	view->show();

    return app.exec();
}
