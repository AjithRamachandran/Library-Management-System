#include <iostream>

#include <usermenu.h>

void usermenu::mainmenu() {
    int choice;
    std::cout<<"Welcome!"<<std::endl;
    start:
    std::cout<<"1.Borrow a book\n2.Return a book\n3.View current status\n4.Exit"<<std::endl;
    std::cin>>choice;
    if(choice==1){
        usermenu::borrowbook();
    }
    else if(choice==2){
        usermenu::returnbook();
    }
    else if(choice==3){
        usermenu::viewstatus();
    }
    else if(choice==4) {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cout<<"Wrong Input! Try Again\n";
        goto start;
    }
}

void usermenu::borrowbook() {
    
}

void usermenu::returnbook() {

}

void usermenu::viewstatus() {

}

usermenu::usermenu() {

}

usermenu::~usermenu() {
    
}