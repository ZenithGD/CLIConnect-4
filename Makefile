#commands and args
CC = g++
RM = rm -rv
MKD = mkdir -p
CXXFLAGS = -Isrc -Ilib -std=c++14 -Wall

#directories and files
BIN = bin
SRC = src
OBJ = obj
LIB = lib

BOARD = Board
SOCK = Socket
MAIN = connect-4-main

EXEC = connect4

.PHONY: all clean 

all: directories $(BIN)/$(MAIN)

$(BIN)/$(MAIN): $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o
	$(CC) $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o -o $(BIN)/$(EXEC) $(CXXFLAGS)

$(OBJ)/$(BOARD).o: $(LIB)/$(BOARD).cpp $(LIB)/$(BOARD).hpp
	$(CC) -c $(LIB)/$(BOARD).cpp -o $(OBJ)/$(BOARD).o $(CXXFLAGS)

$(OBJ)/$(SOCK).o: $(LIB)/$(SOCK).cpp $(LIB)/$(SOCK).cpp
	$(CC) -c $(LIB)/$(SOCK).cpp -o $(OBJ)/$(SOCK).o $(CXXFLAGS)

directories:
	$(MKD) $(BIN) $(OBJ)
clean:
	$(RM) $(BIN) $(OBJ)