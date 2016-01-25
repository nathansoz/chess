//
// Created by Nathan Sosnovske on 1/24/16.
//

#ifndef CHESS_CHESSMOVES_H
#define CHESS_CHESSMOVES_H

#include <functional>
#include <vector>

#include "ChessPieces.h"



namespace ChessController
{
    typedef std::function<bool(int, int, int, int)> ChessMove ;

    class ChessMoves
    {


    public:
        static bool ValidMove(ChessPieceType pieceType, int fromX, int fromY, int toX, int toY);
    private:

        static const ChessMove _pawnFunction;
        static const ChessMove _knightFunction;
        static const ChessMove _bishopFunction;
        static const ChessMove _rookFunction;
        static const ChessMove _queenFunction;
        static const ChessMove _kingFunction;

        static const std::vector<ChessMove> _moveFunctions;
    };
}

#endif //CHESS_CHESSMOVES_H
