// ChessRulesEngine.h
// Created by Nathan Sosnovske on 1/24/16.
//

//
//
//
//

#ifndef CHESS_CHESSRULESENGINE_H
#define CHESS_CHESSRULESENGINE_H

#include "ChessPieces.h"
#include "Point.h"

namespace ChessController
{
    class ChessRulesEngine
    {
    public:
        static bool ValidMove(ChessPieceType, ChessGameState, Point, Point);

    private:
        static bool IsSquareAbleToBeAttacked(Point);
        static bool IsPathClear(Point, Point);
    };
}

#endif //CHESS_CHESSRULESENGINE_H
