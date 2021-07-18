#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtWidgets>
#include <QtGui>
class MyServer : public QWidget {
Q_OBJECT
private:
    QTcpServer* m_pTcpServer;
    QTextEdit*  m_pTxt;
    quint16     m_nNextBlockSize;
    
public:
    MyServer(int nPort, QWidget * parentWgt = nullptr)
        : QWidget{ parentWgt }, m_nNextBlockSize{0}
    {
        m_pTcpServer = new QTcpServer{this};
        if (not m_pTcpServer->listen(QHostAddress::Any, nPort)) {
            QMessageBox::critical(
                0,
                "Server Error",
                "Unable to start the server: " + m_pTcpServer->errorString());
            m_pTcpServer->close();
            return;
        }
        
        QObject::connect(m_pTcpServer, &QTcpServer::newConnection,
            this, &MyServer::slotNewConnection);
            
        m_pTxt = new QTextEdit{};
        m_pTxt->setReadOnly(true);
        
        QVBoxLayout * pLayout = new QVBoxLayout{};
        pLayout->addWidget(new QLabel{"<h1>server</h1>"});
        pLayout->addWidget(m_pTxt);
        setLayout(pLayout);
    }

public slots:
    virtual void slotNewConnection() {
        QTcpSocket * pClientSocket = m_pTcpServer->nextPendingConnection();
        
        QObject::connect(pClientSocket, &QTcpSocket::disconnected,
            pClientSocket, &QTcpSocket::deleteLater);
        QObject::connect(pClientSocket, &QTcpSocket::readyRead,
            this, &MyServer::slotReadClient);
            
        sendToClient(pClientSocket, "Server Response: Connected!");
    }
    
    void slotReadClient() {
        QTcpSocket* pClientSocket = (QTcpSocket*)sender();
        QDataStream in{pClientSocket};
        in.setVersion(QDataStream::Qt_5_3);
        
        for (;;) {
            if (not m_nNextBlockSize) {
                if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {
                    break;
                }
                in >> m_nNextBlockSize;
            }
            
            if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
                break;
            }
            
            QTime time{};
            QString str{};
            in >> time >> str;
            
            QString const & strMsg = time.toString() + " " + "Client has sent - " + str;
            m_pTxt->append(strMsg);
            
            m_nNextBlockSize = 0;
            
            sendToClient(pClientSocket, "Server Response: Received \"" + str + "\"");
        }
    }
    
private:
    void sendToClient(QTcpSocket* pSocket, QString const& str) {
        QByteArray arrBlock{};
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_3);
        out << quint16(0) << QTime::currentTime() << str;
        
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        
        pSocket->write(arrBlock);
    }
};


#include <QApplication>
#include <QDebug>
int main(int argc, char** argv) {  
    QApplication app{ argc, argv };

    MyServer server{2323};
    server.show();

    return app.exec();
}

#include "main.moc"
