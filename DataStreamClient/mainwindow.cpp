#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>

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

class Position
{


public:
    QString id;
    double value;
    QString username;
};
QTcpSocket sock;

void MainWindow::on_pushButton_clicked()
{
    sock.connectToHost("127.0.0.1", 9999);

    if (sock.waitForConnected(1000))
        qDebug("Connected!");
    else
    {
        qDebug("Connect error!");
        return;
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString strName= ui->lineEdit->text();
    //    qDebug()<<strMesg;
    //    QDataStream ds1(&sock);
    //    ds1 << strMesg;
    //    sock.write(strMesg.toStdString().c_str(),strlen(strMesg.toStdString().c_str())); //发送

    //    return;

    QVector<Position*> positions;

    Position * p1= new Position;
    p1->id="0001";
    p1->value = 1;
    p1->username=strName;

    positions.append(p1);

    //用于暂存要发送的数据
    QByteArray block;
    //使用数据流写入数据
    QDataStream ds(&block,QIODevice::WriteOnly);
    ds.setVersion(QDataStream::Qt_5_0);

    ds << positions.size();

    for(int i=0; i<positions.size(); ++i)
    {
        ds << positions[i]->id;
        ds << positions[i]->value;
        ds << positions[i]->username;

    }
    qDebug() << "block.size()"<<block.size();
    sock.write(block,block.size());
}

void MainWindow::on_pushButton_3_clicked()
{
    sock.close();
}
