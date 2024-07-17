#include <QCoreApplication>
#include <QUdpSocket>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUdpSocket socket;
    QHostAddress adr{"127.0.0.1"};
    socket.bind(adr, 54000);

    auto db = QSqlDatabase::addDatabase("QPSQL", "Animals");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Animals");
    db.setUserName("postgres");
    db.setPassword("secret");
    db.setPort(5432);

    if(!db.open()){
        qDebug() << "No database connection";
        assert(0);
    }

    return a.exec();
}
