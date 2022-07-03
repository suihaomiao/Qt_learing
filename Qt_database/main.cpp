#include <QCoreApplication>
#include "sqlite3.h"
#include <QDebug>

#define cout  qDebug()

#define CHECK_RETURN_VALUE(ret, errmsg) \
    if (ret != SQLITE_OK) {  \
       cout << "ret:" << ret << "failed" << "errmsg:" << errmsg;\
    }\

int select_callback(void *arg,int col, char **values,char **name)
{
    for(int i = 0; i < col; ++i) {
        cout << "clo : " << col << " data is " << values[i];
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 打开数据库
    sqlite3 *ppdb = nullptr;
    int ret = sqlite3_open("./mytext.db", &ppdb);
    if (ret != SQLITE_OK) {
        // 打开不成功，报错
        cout << "open ccdb failed";
        return a.exec();
    }
    // 执行语句
    const char *creat_sql = "create table if not exists student (id integer primary key autoincrement,\
                                                          name varchar(32) NOT NULL,\
                                                          sex varchar(8),\
                                                          phone text UNIQUE,\
                                                          regtime TimeStamp NOT NULL default(datetime('now', 'localtime')));";
    char *errmsg = NULL;
    cout << "open cddb success!";
    ret = sqlite3_exec(ppdb, creat_sql, NULL, NULL, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);
    const char* insert_sql = "insert into student(name, sex, phone) values('张三', '男', '184*******');";
    ret = sqlite3_exec(ppdb, insert_sql, NULL, NULL, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);

    const char *select_sql = "select * from student;";
    ret = sqlite3_exec(ppdb,  select_sql, select_callback, NULL, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);
    sqlite3_close(ppdb);
    sqlite3_free(errmsg);
    return a.exec();
}
