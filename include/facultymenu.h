#ifndef FACULTYMENU_H
#define FACULTYMENU_H

#include <sqlite3.h>

class facultymenu {
    public:
        sqlite3 *data_db;
        sqlite3 *user_db;
        facultymenu();
        ~facultymenu();
        void connectDatabase();
        void mainmenu();
        void removeusers();
        void addbook();
        void deletebook();
};

#endif