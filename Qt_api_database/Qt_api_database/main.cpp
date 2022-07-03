#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // database指定数据库
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    // 设置数据库信息（数据库名，用户名称，密码，主机）
    // sqlite3 没有用户名和密码，mysql可以有
    database.setDatabaseName("user.db");

    // 打开数据库
    if (!database.open()) {
        // 打开失败
        exit(1);
    }


    // 操作数据库
    QString create_sql = "create table user(id integer primary key autoincrement,"
                         "username varchar(128) unique,"
                         "password varchar(128))";
    QSqlQuery query;
    if (query.exec(create_sql)) {
        // 执行错误
    }

    return a.exec();
}
