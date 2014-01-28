#include <QObject>
#include <qextserialport.h>

class SerialPortClient : public QObject
{
	Q_OBJECT

public :
	SerialPortClient();
	virtual ~SerialPortClient();

	int open(const QString &portpath, const PortSettings &settings);
	int close();
	int setParam(const PortSettings &settings);
	
private slots :
	void slotReadyRead();

signals :
	void sigReadData(QByteArray data);

private :
	QextSerialPort *m_port;
};
