#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

const int MAX_WIDTH = 6;

    // objeto tabla
    class Board {

        private:

            // huecos para el juego ()
            std::vector<std::vector<int>> slots;
            int rows, cols; // tamaño de la tabla
            int playerCount; // asumimos que es 2 por simplicidad
            int pieces; // número de fichas en el tablero

			// funciones auxiliares

			// comprobar si a partir de la pieza añadida se ha hecho 4 en raya por el jugador <j>
            friend bool check(const Board* b, int c, int r, int j);

			// Comprueba si hay un 4 en raya en las 4 direcciones posibles
			friend bool checkAux(const Board* b, int c, int r, int j, int incC, int incR);

			// comprueba si el par (c, r) apunta a una posición del tablero válida
			friend bool in(const Board* b, int c, int r);

        public:

            // inicializar el tablero
            Board(int cols, int rows, int playerCount);

            ~Board();

            // el jugador <j> añade una ficha en la columna c
            // si se añadió la pieza devuelve true, si no false
            bool add(int j, int c, bool& connected);
            
            // comprueba si es posible añadir alguna ficha
            bool isFull();

			// devuelve el número de jugadores
            int playerNumber();

			// muestra el tablero de juego
            friend std::ostream& operator<<(std::ostream& out, const Board& b);
    };

#endif