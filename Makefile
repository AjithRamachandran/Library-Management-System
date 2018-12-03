CC          = g++
LD          = g++
CFLAG       = -Wall
PROG_NAME   = lms

SRC_DIR     = src
BUILD_DIR   = build
BIN_DIR     = bin
SRC_LIST	= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_LIST 	= $(addprefix $(BIN_DIR)/, $(notdir $(SRC_LIST:.cpp=.o)))
INCLUDE 	= -I include/ -lsqlite3

.PHONY: all clean $(BIN_DIR)/%.o $(PROG_NAME)

all: usermenu.o userlogin.o facultymenu.o facultylogin.o usersignup.o main.o $(PROG_NAME)

facultymenu.o: src/facultymenu.cpp
	g++ -c -g src/facultymenu.cpp -o $(BIN_DIR)/facultymenu.o $(INCLUDE)

facultylogin.o: src/facultylogin.cpp
	g++ -c -g src/facultylogin.cpp -o $(BIN_DIR)/facultylogin.o $(INCLUDE)

usermenu.o: src/usermenu.cpp
	g++ -c -g src/usermenu.cpp -o $(BIN_DIR)/usermenu.o $(INCLUDE)

userlogin.o: src/userlogin.cpp
	g++ -c -g src/userlogin.cpp -o $(BIN_DIR)/userlogin.o $(INCLUDE)

usersignup.o: src/usersignup.cpp
	g++ -c -g src/usersignup.cpp -o $(BIN_DIR)/usersignup.o $(INCLUDE)

main.o: src/main.cpp
	g++ -c -g src/main.cpp -o $(BIN_DIR)/main.o $(INCLUDE)

$(PROG_NAME):
	$(LD) -o $(BUILD_DIR)/$@ $(OBJ_LIST) $(INCLUDE)

clean:
	rm -f $(BUILD_DIR)/$(PROG_NAME) $(BIN_DIR)/*.o

run:
	./build/lms