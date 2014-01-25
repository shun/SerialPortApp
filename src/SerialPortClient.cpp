#include "SerialPortClient.h"

SerialPortClient::SerialPortClient()
{
	m_port = NULL;
}

SerialPortClient::~SerialPortClient()
{
	if (NULL != m_port)
	{
		m_port->close();
		delete m_port;
		m_port = NULL;
	}
}

void SerialPortClient::slotReadyRead()
{
	if (!m_port->isOpen())
		return;

	QByteArray bytes = m_port->readAll();
	emit sigReadData(bytes);
}

int SerialPortClient::open(const QString &portpath, const PortSettings &settings)
{
	QextSerialPort *port = new QextSerialPort(
		portpath,
		settings,
		QextSerialPort::EventDriven,
		this);

	if (NULL == port)
		return -1;


	if (!port->open(QIODevice::ReadWrite))
	{
		delete port;
		return -1;
	}
	m_port = port;
	connect(m_port, SIGNAL(readyread()), this, SLOT(slotReadyRead()));
}

int SerialPortClient::close()
{
	if (NULL == m_port)
		return -1;
	m_port->close();
	disconnect(m_port, SIGNAL(readyread()), this, SLOT(slotReadyRead()));

	delete m_port;
	m_port = NULL;
	
	return 0;
}

