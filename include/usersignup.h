#ifndef USERSIGNUP_H
#define USERSIGNUP_H

#include <sqlite3.h>

class usersignup {
    public:
        sqlite3 *db;
        usersignup();
        ~usersignup();
        void mainmenu();
        void connectdatabase();
        void createuser();
};

#endif