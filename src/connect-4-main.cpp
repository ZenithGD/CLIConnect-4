/* Autor: Darío Marcos Casalé
 * Fecha de la última revisión: 14-12-2020
 * Resumen: Simulación del juego de mesa '4 en raya'
 */

#include <iostream>
#include <fstream>
#include <Board.hpp>

using namespace std;

int turn(int j, int maxCol) {
	int c;
	do {
		cout << "Turno jugador " << j << ": ";
		cin >> c;
	} while ( c < 0 || c >= maxCol );
	return c; 
} 

int main () {

	system("clear");
    Board board(7, 6, 2);

    cout << board;
    int curP = 0; // id. jugador actual - 1
    bool connect4 = false;
    // bucle sencillo de juego
    while ( !board.isFull() && !connect4) {
        board.add(curP + 1, turn(curP + 1, board.getColumns()), connect4);
        cout << board;
        curP = ( curP + 1 ) % board.playerNumber();
    }
    cout << "Fin!" << endl;
    return 0;
}