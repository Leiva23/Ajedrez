#include "movement.h"

// verificacion de que coja una pieza de su color y no del contrario
bool isEnemyPiece(char piece, bool isWhiteTurn) {
    if (piece == EMPTY) return false;
    return isWhiteTurn ? (piece >= 'a' && piece <= 'z') : (piece >= 'A' && piece <= 'Z');
}

// dvuelve true si la pieza indicada es una pieza aliada
bool isAllyPiece(char piece, bool isWhiteTurn) {
    if (piece == EMPTY) return false;
    return isWhiteTurn ? (piece >= 'A' && piece <= 'Z') : (piece >= 'a' && piece <= 'z');
}

// comprueba si el camino entre dos posiciones esta libre (sin piezas en medio)
bool isPathFree(char chessBoard[BOARD_SIZE][BOARD_SIZE], Position from, Position to) {
    int stepX = 0;
    int stepY = 0;

    if (to.x > from.x) stepX = 1;
    if (to.x < from.x) stepX = -1;
    if (to.y > from.y) stepY = 1;
    if (to.y < from.y) stepY = -1;

    int currentX = from.x + stepX;
    int currentY = from.y + stepY;

    while (currentX != to.x || currentY != to.y) {
        if (chessBoard[currentX][currentY] != EMPTY) return false;
        currentX += stepX;
        currentY += stepY;
    }

    return true;
}

// Verifica si un movimiento es valido para la pieza 
bool isValidMove(char chessBoard[BOARD_SIZE][BOARD_SIZE], Position from, Position to, bool isWhiteTurn) {
    char piece = chessBoard[from.x][from.y];
    char target = chessBoard[to.x][to.y];

    if (from.x == to.x && from.y == to.y) return false;
    if (isAllyPiece(target, isWhiteTurn)) return false;

    int moveX = to.x - from.x;
    int moveY = to.y - from.y;

    switch (piece) {
    case WHITE_PAWN:
        if (moveX == -1 && moveY == 0 && target == EMPTY) return true;
        if (moveX == -1 && (moveY == 1 || moveY == -1) && isEnemyPiece(target, isWhiteTurn)) return true;
        break;

    case BLACK_PAWN:
        if (moveX == 1 && moveY == 0 && target == EMPTY) return true;
        if (moveX == 1 && (moveY == 1 || moveY == -1) && isEnemyPiece(target, isWhiteTurn)) return true;
        break;

    case WHITE_ROOK:
    case BLACK_ROOK:
        if ((moveX == 0 || moveY == 0) && isPathFree(chessBoard, from, to)) return true;
        break;

    case WHITE_BISHOP:
    case BLACK_BISHOP:
        if ((moveX == moveY || moveX == -moveY) && isPathFree(chessBoard, from, to)) return true;
        break;

    case WHITE_QUEEN:
    case BLACK_QUEEN:
        if (((moveX == 0 || moveY == 0) || (moveX == moveY || moveX == -moveY)) && isPathFree(chessBoard, from, to)) return true;
        break;

    case WHITE_KING:
    case BLACK_KING:
        if ((moveX >= -1 && moveX <= 1) && (moveY >= -1 && moveY <= 1)) return true;
        break;

    case WHITE_KNIGHT:
    case BLACK_KNIGHT:
        if ((moveX * moveX + moveY * moveY) == 5) return true;
        break;
    }

    return false;
}
