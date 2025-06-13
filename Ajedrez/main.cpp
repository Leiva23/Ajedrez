#include "const.h"
#include "board.h"
#include "utils.h"
#include "movement.h"

int main() {

	char chessBoard[BOARD_SIZE][BOARD_SIZE];
	bool gameover = false;
	bool isWhiteTurn = true; // las blancas seran las primera en mover
	initChessBoard(chessBoard);

    do {
        string currentTurn = isWhiteTurn ? "BLANCAS" : "NEGRAS"; 
        cout << "Turno de las " << currentTurn << endl; // muestro de quien es el turno

        viewChessBoard(chessBoard);

        // obtenemos la posicion de la pieza que el jugador desea mover
        Position fromPosition, toPosition;
        fromPosition = getPieceByUser(chessBoard, isWhiteTurn);

        bool validMove = false;

        // pedimos al usuario que indique donde mover la pieza
        do {
            cout << "Indica donde mover la pieza:" << endl;
            cout << "X: ";
            cin >> toPosition.y;
            cout << "Y: ";
            cin >> toPosition.x;

            // restamos el tamaño del tablero para el eje X y le restamos 1 al eje Y para que coincida con las posiciones del tablero (empiezan en 0)
            toPosition.y -= 1;
            toPosition.x = BOARD_SIZE - toPosition.x;


            if (toPosition.x < 0 || toPosition.x >= BOARD_SIZE || toPosition.y < 0 || toPosition.y >= BOARD_SIZE) {
                cout << "Destino fuera del tablero" << endl;
            }
            else if (!isValidMove(chessBoard, fromPosition, toPosition, isWhiteTurn)) {
                cout << "Movimiento no valido para esa pieza" << endl;
            }
            else {
                validMove = true;
            }

        } while (!validMove);

        if (tolower(chessBoard[toPosition.x][toPosition.y]) == 'k') {
            viewChessBoard(chessBoard);
            cout << "El rey ha sido comido! Ganan las " << (isWhiteTurn ? "BLANCAS" : "NEGRAS") << endl;
            gameover = true;
            break;
        }

        chessBoard[toPosition.x][toPosition.y] = chessBoard[fromPosition.x][fromPosition.y];
        chessBoard[fromPosition.x][fromPosition.y] = EMPTY;

        if (chessBoard[toPosition.x][toPosition.y] == WHITE_PAWN && toPosition.x == 0) {
            chessBoard[toPosition.x][toPosition.y] = WHITE_QUEEN;
            cout << "Peon blanco convertido en reina" << endl;
        }
        else if (chessBoard[toPosition.x][toPosition.y] == BLACK_PAWN && toPosition.x == BOARD_SIZE - 1) {
            chessBoard[toPosition.x][toPosition.y] = BLACK_QUEEN;
            cout << "Peon negro convertido en reina" << endl;
        }

        isWhiteTurn = !isWhiteTurn;
        system("cls");

    } while (!gameover);



}