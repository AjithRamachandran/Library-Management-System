#ifndef FACULTYLOGIN_H
#define FACULTYLOGIN_H

#include <string>
#include <sqlite3.h>

class facultylogin {
    public:
        sqlite3 *db;
        static std::string password;
        facultylogin();
        ~facultylogin();
        void connectDatabase();
        void login();
};

#endif