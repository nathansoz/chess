#include <iostream>

#include "ChessBoard.h"
#include "ChessMoves.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    ChessController::ChessBoard board;
    board.Print();
    board.Move(Point(1, 2), Point(2, 3));

    //cout << ChessController::ChessMoves::ValidMove(ChessController::ChessPieces::King, 1, 1, 1, 1);
    return 0;
}