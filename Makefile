#commands and args
CC = g++
RM = rm -rv
MKD = mkdir -p
CXXFLAGS = -Isrc -std=c++14 -Wall

#directories and files
BIN = bin
SRC = src
OBJ = obj
BOARD = Board
MAIN = connect-4-main

EXEC = connect4

.PHONY: all clean 

all: directories $(BIN)/$(MAIN)

$(BIN)/$(MAIN): $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o
	$(CC) $(SRC)/$(MAIN).cpp $(OBJ)/$(BOARD).o -o $(BIN)/$(EXEC) $(CXXFLAGS)

$(OBJ)/$(BOARD).o: $(SRC)/$(BOARD).cpp $(SRC)/$(BOARD).hpp
	$(CC) -c $(SRC)/$(BOARD).cpp -o $(OBJ)/$(BOARD).o $(CXXFLAGS)

directories:
	$(MKD) $(BIN) $(OBJ)
clean:
	$(RM) $(BIN) $(OBJ)