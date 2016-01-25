//
// Created by Nathan Sosnovske on 1/24/16.
//

#ifndef CHESS_CHESSPIECES_H
#define CHESS_CHESSPIECES_H

namespace ChessController
{
    enum ChessPieceType
    {
        Pawn,
        Knight,
        Bishop,
        Rook,
        Queen,
        King,
        NoPiece
    };

    enum ChessPieceColor
    {
        Black,
        White,
        None
    };
}

#endif //CHESS_CHESSPIECES_H
