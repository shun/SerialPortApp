#include <QApplication>
#include "SerialPortClient.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
	SerialPortClient client;

    return app.exec();
}
