#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Position.h"
#include "iostream"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


class ISerializeTool;


void MainWindow::on_pushButton_clicked()
{
    Position p;
    Position p2;
    p.id = "33";
    p.username = "adc";
    p.value = 3398.12;
    p.surname = "ddd";

    p.SetSerializeKeys_Test();

    QString qjson =  p.SerializeToString();
    //QString qjson2 =  p.MulJson();
    p2.DeserializeByString(qjson);
    QString qjson2 =  p2.SerializeToString();

    qDebug() << qjson;
    qDebug() << qjson2;
    QVector<Position*> positions;
    svc = new QTcpServer();

    connect(svc,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);
    if(!svc->listen(QHostAddress::Any, 9999))
    {
        qDebug() << svc->errorString();
    }

}

void MainWindow::server_New_Connect()
{
    qDebug() << "some one connect";
    if(svc == NULL)
        return;

    sock = svc->nextPendingConnection();
    qDebug() << "connectid:"  ;

    QObject::connect(sock, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    QObject::connect(sock, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);


}


void MainWindow::socket_Read_Data()
{
    int size;
    QDataStream ds(sock);
    ds.setVersion(QDataStream::Qt_5_0);

    ds >> size;

    for (int i=0; i < size; ++i)
    {
        Position * p1= new Position;

        ds >> p1->id >> p1->value >> p1->username;

        qDebug() << p1->id << ":"
                 << p1->value  << ":"
                 << p1->username;

        ui->textEdit->setText(p1->Tostring());
    }
}

void MainWindow::socket_Disconnected()
{
    sock->close();
}

