#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QTcpServer>
#include<QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void server_New_Connect();
    void socket_Read_Data();
    void socket_Disconnected();

private:
    Ui::MainWindow *ui;

    QTcpServer *svc;
    QTcpSocket *sock;

};

#endif // MAINWINDOW_H
