// sqlit.cpp
#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;
using std::string;

int main (int argc, char* argv[])
{
    sqlite3 *db = 0;
    char* err = 0;
    string* stmnt = "CREATE TABLE IF NOT EXISTS tab(Id INTEGER,Name TEXT,Age INTEGER);\nINSERT INTO tab(Id,Name,Age) VALUES(1,\"Vasa Pupkin\",29);";

    if (sqlite3_open("mydb.db", &db))
        cout << "Ошибка открытия/создания БД: " << sqlite3_errmsg(db) << endl;
    else if (sqlite3_exec(db, stmnt, 0, 0, &err))
    {
        cout << "Ошибка SQL: " << err << endl;
        sqlite3_free(err);
    }



    sqlite3_close(db);

    return 0;
}
