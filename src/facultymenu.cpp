#include <iostream>
#include <string>

#include <facultymenu.h>

void facultymenu::addbook() {

}

void facultymenu::deletebook() {

}

void facultymenu::manageusers() {

}

void facultymenu::mainmenu() {
    int choice;
    std::cout<<"Welcome!"<<std::endl;
    start:
    std::cout<<"1.Borrow a book\n2.Return a book\n3.View current status\n4.Exit"<<std::endl;
    std::cin>>choice;
    if(choice==1){
        facultymenu::addbook();
    }
    else if(choice==2){
        facultymenu::deletebook();
    }
    else if(choice==3){
        facultymenu::manageusers();
    }
    else if(choice==4) {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cout<<"Wrong Input! Try Again\n";
        goto start;
    }
}

facultymenu::facultymenu() {

}

facultymenu::~facultymenu() {
    
}
