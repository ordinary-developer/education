#include <QWidget>
#include <QTcpSocket>
#include <QtWidgets>
#include <QtGui>

class MyClient : public QWidget {
Q_OBJECT

private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit*  m_pTxtInfo;
    QLineEdit*  m_pTxtInput;
    quint16     m_nNextBlockSize;
    
public:
    MyClient(const QString & strHost, int nPort, QWidget * parentWgt = nullptr) 
        : QWidget{ parentWgt }, m_nNextBlockSize{ 0 }
    {
        m_pTcpSocket = new QTcpSocket{this};
        
        m_pTcpSocket->connectToHost(strHost, nPort);
        
        QObject::connect(m_pTcpSocket, &QTcpSocket::connected,
            this, &MyClient::slotConnected);
        QObject::connect(m_pTcpSocket, &QTcpSocket::readyRead,
            this, &MyClient::slotReadyRead);
        QObject::connect(m_pTcpSocket, 
            static_cast<void (QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
            this,
            static_cast<void (MyClient::*)(QAbstractSocket::SocketError)>(&MyClient::slotError));
            
        m_pTxtInfo = new QTextEdit{};
        m_pTxtInput = new QLineEdit{};
        
        QObject::connect(m_pTxtInput, &QLineEdit::returnPressed,
            this, &MyClient::slotSendToServer);
            
        QPushButton* pCmd = new QPushButton("&Send");
        QObject::connect(pCmd, QPushButton::clicked,
            this, &MyClient::slotSendToServer);
            
        QVBoxLayout* pLayout = new QVBoxLayout{};
        pLayout->addWidget(new QLabel{"<h1>client</h1>"});
        pLayout->addWidget(m_pTxtInfo);
        pLayout->addWidget(m_pTxtInput);
        pLayout->addWidget(pCmd);
        setLayout(pLayout);
    }
    
private slots:
    void slotReadyRead() {
        QDataStream in{m_pTcpSocket};
        in.setVersion(QDataStream::Qt_5_3);
        
        for (;;) {
            if (not m_nNextBlockSize) {
                if (m_pTcpSocket->bytesAvailable() < (int)sizeof(quint16))
                    break;
                in >> m_nNextBlockSize;
            }
            
            if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
                break;
            
            QTime time{};
            QString str{};
            in >> time >> str;
            
            m_pTxtInfo->append(time.toString() + " " + str);
            m_nNextBlockSize = 0;
        }
    }
    
    void slotError(QAbstractSocket::SocketError err) {
        QString strErr = "Error: " +
            (QAbstractSocket::HostNotFoundError == err
                ? "The host was not found."
                : QAbstractSocket::RemoteHostClosedError == err
                    ? "The remote host is closed."
                    : QAbstractSocket::ConnectionRefusedError == err
                        ? "The connection was refused."
                        : QString{ m_pTcpSocket->errorString() });
        m_pTxtInfo->append(strErr);
    }
    
    void slotSendToServer() {
        QByteArray arrBlock{};
        QDataStream out{ &arrBlock, QIODevice::WriteOnly };
        out.setVersion(QDataStream::Qt_5_3);
        out << quint16(0) << QTime::currentTime() << m_pTxtInput->text();
        
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        
        m_pTcpSocket->write(arrBlock);
        m_pTxtInput->setText("");
    }
    
    void slotConnected() {
        m_pTxtInfo->append("Received the connected() signal");
    }
};

#include <QApplication>
#include <QDebug>
int main(int argc, char** argv) {  
    QApplication app{ argc, argv };
    
    MyClient client("localhost", 2323);
    client.show();
    
    return app.exec();
}

#include "main.moc"
