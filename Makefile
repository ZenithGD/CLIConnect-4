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

S_T = server_test
C_T = client_test

EXEC = connect4

.PHONY: all clean socket_test

all: directories socket_test $(BIN)/$(MAIN)

$(BIN)/$(MAIN): $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o
	$(CC) $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o -o $(BIN)/$(EXEC) $(CXXFLAGS)

$(OBJ)/$(BOARD).o: $(LIB)/$(BOARD).cpp $(LIB)/$(BOARD).hpp
	$(CC) -c $(LIB)/$(BOARD).cpp -o $(OBJ)/$(BOARD).o $(CXXFLAGS)

$(OBJ)/$(SOCK).o: $(LIB)/$(SOCK).cpp $(LIB)/$(SOCK).cpp
	$(CC) -c $(LIB)/$(SOCK).cpp -o $(OBJ)/$(SOCK).o $(CXXFLAGS)

socket_test: $(BIN)/$(C_T) $(BIN)/$(S_T)

$(BIN)/$(C_T): $(OBJ)/$(SOCK).o $(SRC)/$(C_T).cpp
	$(CC) $(OBJ)/$(SOCK).o $(SRC)/$(C_T).cpp -o $(BIN)/$(C_T) $(CXXFLAGS)

$(BIN)/$(S_T): $(OBJ)/$(SOCK).o $(SRC)/$(S_T).cpp
	$(CC) $(OBJ)/$(SOCK).o $(SRC)/$(S_T).cpp -o $(BIN)/$(S_T) $(CXXFLAGS)

directories:
	$(MKD) $(BIN) $(OBJ)
clean:
	$(RM) $(BIN) $(OBJ)