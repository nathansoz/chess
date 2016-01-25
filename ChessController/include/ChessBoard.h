//
// Created by Nathan Sosnovske on 1/23/16.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <array>
#include <memory>

#include "ChessGameState.h"
#include "ChessPieces.h"
#include "Point.h"

#define BOARD_SIZE 12
#define BOARD_OFFSET 2

namespace ChessController
{
    class ChessBoard
    {
    public:
        bool IsInitialized();
        ChessBoard();
        ~ChessBoard();

        Point GetKingLocation(ChessPieceColor);

        void Print();

        bool Move(Point, Point);
    private:
        std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> _board = { 0 };
        bool _initialized;

        void Initialize();
        int GetPieceAtSquare(Point);
        void SetPieceAtSquare(Point, ChessPieceType, ChessPieceColor);
        ChessPieceColor GetSquarePieceColor(Point);
        ChessPieceType GetSquarePieceType(Point);

        Point BlackKingLocation;
        Point WhiteKingLocation;
    };
}

#endif //CHESS_BOARD_H
