#ifndef FACULTYMENU_H
#define FACULTYMENU_H

#include <sqlite3.h>

class facultymenu {
    public:
        sqlite3 *db;
        facultymenu();
        ~facultymenu();
        void connectDatabase();
        void mainmenu();
        void manageusers();
        void addbook();
        void deletebook();
};

#endif