#include <iostream>
#include <fstream>
#include <Board.hpp>

using namespace std;

int turn(int j) {
    cout << "Turno jugador " << j << ": ";
    int c;
    cin >> c;
    return c; 
} 

int main () {

    Board board(7, 6, 2);

    cout << board;
    int curP = 0; // id. jugador actual - 1
    bool connect4 = false;
    // bucle sencillo de juego
    while ( !board.isFull() && !connect4) {
        board.add(curP + 1, turn(curP + 1), connect4);
        cout << board;
        curP = ( curP + 1 ) % board.playerNumber();
    }
    cout << "Fin!" << endl;
    return 0;
}