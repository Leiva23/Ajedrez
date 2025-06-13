#pragma once
#include "const.h"
#include "utils.h"

bool isValidMove(char chessBoard[BOARD_SIZE][BOARD_SIZE], Position fromPosition, Position toPosition, bool isWhiteTurn);
bool isEnemyPiece(char piece, bool isWhiteTurn);
bool isAllyPiece(char piece, bool isWhiteTurn);
bool isPathFree(char chessBoard[BOARD_SIZE][BOARD_SIZE], Position fromPosition, Position toPosition);
