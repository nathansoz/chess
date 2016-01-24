#include <iostream>

#include "Pieces/ChessMoves.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    cout << ChessPieces::ChessMoves::ValidMove(ChessPieces::ChessPieces::King, 1, 1, 1, 1);
    return 0;
}