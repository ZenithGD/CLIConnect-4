#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <Board.hpp>

using namespace std;

// Pre: cols > 0 && rows > 0 && playerCount >= 2
// Post: Inicializa los campos de la instancia creada y aloja un espacio en memoria
//		 para almacenar el tablero de juego
Board::Board(int cols, int rows, int playerCount = 2) 
{
    this->cols = cols;
    this->rows = rows;
    this->playerCount = playerCount;
    pieces = 0;
    slots = vector<vector<int>>(rows, vector<int>(cols, 0)); // rellenar con -1 y reservar espacio
}

Board::~Board() 
{
    // nada
}

// Pre: j > 0 && 0 <= c < cols
bool Board::add(int j, int c, bool& connected) 
{
    int i = 0;
    bool ok = false;
    // buscar última casilla vacía
    while ( !ok && i < rows && slots[i][c] == 0 ) {
        if ( i == rows - 1 ) {
            slots[i][c] = j; 
            pieces++;
            ok = true;
        }
        else { // i < rows - 1
            if ( slots[i + 1][c] == 0 ) {
                i++;
            }
            else {
                slots[i][c] = j;
                pieces++;
                ok = true;
            }
        }
    }
    connected = check(this, c, i, j);
    return ok;
}

bool check(const Board* b, int c, int r, int j) 
{
    // si hay 4 en raya en alguna dirección devuelve true
    return checkAux(b, c, r, j, -1, -1) || checkAux(b, c, r, j, -1, 0) ||
           checkAux(b, c, r, j, -1, 1) || checkAux(b, c, r, j, 0, 1);

}

bool Board::isFull() 
{
    return pieces == cols * rows;
}

int Board::playerNumber() 
{
    return playerCount;
}

int Board::getColumns() 
{
	return cols;
}

int Board::getRows() 
{
	return rows;
}

std::ostream& operator<<(std::ostream& out, const Board& b) 
{
    // iterador por columnas
    for ( vector<vector<int>>::const_iterator iR = b.slots.cbegin(); 
          iR != b.slots.end();
          iR++ 
        ) 
    {
        // iterador de filas
        for ( vector<int>::const_iterator iC = iR->cbegin();
              iC != iR->cend();
              iC++
            )
        {
            
            out << "|";
            if ( *iC > 0 ) { 
                out << setw(MAX_WIDTH) << *iC; 
            }
            else { 
                out << setw(MAX_WIDTH) << "."; 
            }
        }
        out << "|" << endl;
    }

    return out;
}

bool checkAux(const Board* b, int c, int r, int j, int incC, int incR) 
{
    int iC = c, iR = r;
    // apuntamos a la primera ficha del posible 4 en raya
    while ( in(b, iC + incC, iR + incR) && b->slots[iR + incR][iC + incC] == j ) {
        iC += incC; iR += incR;
    }
    // contador de fichas
    int n = 0;
    while ( in(b, iC, iR) && b->slots[iR][iC] == j ) {
        n++;
        iC -= incC; iR -= incR;
    }
    return n == 4;
}

bool in(const Board* b, int c, int r) 
{
    return c >= 0 && (c < b->cols) && r >= 0 && (r < b->rows);
}
