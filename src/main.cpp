#include <iostream>
// #include <stdlib.h>

#include <userlogin.h>
#include <facultylogin.h>
#include <usersignup.h>

int main() {
    int choice;
    system("clear");
    start:
    std::cout<<"1.User Login\n2.Faculty Login\n3.SignUp\n4.Exit"<<std::endl;
    std::cin>>choice;
    userlogin user;
    facultylogin faculty;
    usersignup create;
    if(choice==1) {
        user.login();
    }
    else if(choice==2) {
        faculty.login();
    }
    else if(choice==3) {
        create.createuser();
    }
    else if(choice==4) {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cout<<"Wrong Input!\nTry Again\n";
        goto start;
    }
    return 0;
}