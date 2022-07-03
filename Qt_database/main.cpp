#include <QCoreApplication>
#include "sqlite3.h"
#include <QDebug>
#include <stdio.h>

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

void write_database(sqlite3* ppdb)
{
    int ret;
    char* errmsg;
    // 执行语句
    const char *create_sql = "create table if not exists student (id integer primary key autoincrement,\
                                                          name varchar(32) NOT NULL,\
                                                          sex varchar(8),\
                                                          phone text UNIQUE,\
                                                          regtime TimeStamp NOT NULL default(datetime('now', 'localtime')));";
    cout << "open cddb success!";
    ret = sqlite3_exec(ppdb, create_sql, NULL, NULL, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);
    const char* insert_sql = "insert into student(name, sex, phone) values('张三', '男', '184*******');";
    ret = sqlite3_exec(ppdb, insert_sql, NULL, NULL, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);

}

void get_table(sqlite3* ppdb)
{
    const char* select_sql = "select * from student;";
    char** result_table;
    int row;
    int col;
    char* errmsg;
    int ret = sqlite3_get_table(ppdb, select_sql, &result_table, &row, &col, &errmsg);
    CHECK_RETURN_VALUE(ret, errmsg);
    cout << "row:" << row << "     col:" << col;
//    cout << result_table[1];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; ++j) {
            printf("result[%d][%d] = %s\n", i, j, result_table[i * col + j]);
        }
    }

    sqlite3_free_table(result_table);
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
//    write_database(ppdb);
//    const char *select_sql = "select * from student;";
//    ret = sqlite3_exec(ppdb,  select_sql, select_callback, NULL, &errmsg);
//    CHECK_RETURN_VALUE(ret, errmsg);

    // sqlite3_get_table
    get_table(ppdb);
    sqlite3_close(ppdb);
//    sqlite3_free(errmsg);
    return a.exec();
}
