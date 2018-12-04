#ifndef USERMENU_H
#define USERMENU_H

class usermenu {
    public:
        sqlite3 *db;
        static std::string username;
        usermenu();
        ~usermenu();
        void connectDatabase();
        void mainmenu();
        void borrowbook();
        void returnbook();
        void viewstatus();
        bool can_user_borrow(std::string);
};

#endif