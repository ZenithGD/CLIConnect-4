CC = g++
CXXFLAGS = -I. -std=c++14 -Wall
BOARD = Board
MAIN = connect-4-main

EXEC = connect4

all: $(MAIN)

$(MAIN): $(MAIN).cpp $(BOARD).o
	$(CC) $(MAIN).cpp $(BOARD).o -o $(EXEC) $(CXXFLAGS)

$(BOARD).o: $(BOARD).cpp $(BOARD).hpp
	$(CC) -c $(BOARD).cpp $(CXXFLAGS)
