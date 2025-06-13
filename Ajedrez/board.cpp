#include "const.h"
#include "utils.h"


void initChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]) {
    // Llenamos todo el tablero, 8x8 casillas 
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == BOARD_SIZE - 2) {
                chessBoard[j][i] = WHITE_PAWN; // Peones blancos en la segunda fila
            }
            else if (j == 1) {
                chessBoard[j][i] = BLACK_PAWN; // Peones negros en la penultima fila
            }
            else {
                chessBoard[j][i] = EMPTY; //casillas vacias por ahora
            }
        }
    }

    const short rookXPosL = 0;                // Torre izquierda
    const short rookXPosR = BOARD_SIZE - 1;   // Torre derecha
    const short knightXPosL = 1;              // Caballo izquierdo
    const short knightXPosR = BOARD_SIZE - 2; // Caballo derecho
    const short bishopXPosL = 2;              // Alfil izquierdo
    const short bishopXPosR = BOARD_SIZE - 3; // Alfil derecho

    const short whiteKingXPosL = 3;            // Rey blanco 
    const short whiteQueenXPosR = BOARD_SIZE - 4; // Reina blanca
    const short blackKingXPosL = BOARD_SIZE - 4; // Rey negro
    const short blackQueenXPosR = 3;           // Reina negra

    chessBoard[0][rookXPosL] = BLACK_ROOK;     // Torre negra izquierda
    chessBoard[0][rookXPosR] = BLACK_ROOK;     // Torre negra derecha
    chessBoard[0][knightXPosL] = BLACK_KNIGHT; // Caballo negro izquierdo
    chessBoard[0][knightXPosR] = BLACK_KNIGHT; // Caballo negro derecho
    chessBoard[0][bishopXPosL] = BLACK_BISHOP; // Alfil negro izquierdo
    chessBoard[0][bishopXPosR] = BLACK_BISHOP; // Alfil negro derecho
    chessBoard[0][whiteKingXPosL] = BLACK_KING;   // Rey negro
    chessBoard[0][whiteQueenXPosR] = BLACK_QUEEN; // Reina negra

    chessBoard[BOARD_SIZE - 1][rookXPosL] = WHITE_ROOK;     // Torre blanca izquierda
    chessBoard[BOARD_SIZE - 1][rookXPosR] = WHITE_ROOK;     // Torre blanca derecha
    chessBoard[BOARD_SIZE - 1][knightXPosL] = WHITE_KNIGHT; // Caballo blanco izquierdo
    chessBoard[BOARD_SIZE - 1][knightXPosR] = WHITE_KNIGHT; // Caballo blanco derecho
    chessBoard[BOARD_SIZE - 1][bishopXPosL] = WHITE_BISHOP; // Alfil blanco izquierdo
    chessBoard[BOARD_SIZE - 1][bishopXPosR] = WHITE_BISHOP; // Alfil blanco derecho
    chessBoard[BOARD_SIZE - 1][blackKingXPosL] = WHITE_KING;   // Rey blanco
    chessBoard[BOARD_SIZE - 1][blackQueenXPosR] = WHITE_QUEEN; // Reina blanca
}

void viewChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]) {

    std::cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << i + 1 << ' '; 
    }
    std::cout << '\n';

    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << BOARD_SIZE - i << ' ';
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << chessBoard[i][j] << ' '; 
        }
        std::cout << '\n';
    }
}


Position getPieceByUser(char chessBoard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn) {
    Position selected;
    bool valid = false;

    do {
        cout << "-----------------" << endl;
        cout << " Elige una pieza:" << endl;
        cout << "X: ";
        cin >> selected.y;
        cout << "Y: ";
        cin >> selected.x;

        selected.y -= 1;
        selected.x = BOARD_SIZE - selected.x;

        if (selected.x < 0 || selected.x >= BOARD_SIZE || selected.y < 0 || selected.y >= BOARD_SIZE) {
            cout << "Input Invalido: Te has pasado los limites" << endl;
        }
        else if (chessBoard[selected.x][selected.y] == EMPTY) {
            cout << "Input Invalido: Aqui no hay ninguna pieza" << endl;
        }
        else if ((isWhiteTurn && chessBoard[selected.x][selected.y] >= 'a' && chessBoard[selected.x][selected.y] <= 'z') ||
            (!isWhiteTurn && chessBoard[selected.x][selected.y] >= 'A' && chessBoard[selected.x][selected.y] <= 'Z')) {
            cout << "Input Invalido: Intentas coger una ficha del contrincante" << endl;
        }
        else {
            valid = true;
        }
    } while (!valid);

    return selected;
}


