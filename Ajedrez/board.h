#pragma once
#include "const.h"
#include "utils.h"

void initChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]);
void viewChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]);

Position getPieceByUser(char chessBoard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn);