//
// Created by Nathan Sosnovske on 1/24/16.
//

#ifndef CHESS_CHESSGAMESTATE_H
#define CHESS_CHESSGAMESTATE_H

namespace ChessController
{
    struct ChessGameState
    {
        bool blackPlayersTurn = false;

        //State of the board info (Used for initial pawn move, en passant, and castling)
        bool blackPawnsMoved[8] = { false };
        bool whitePawnsMoved[8] = { false };
        bool blackKingMoved = false;
        bool whiteKingMoved = false;
        bool blackRooksMoved[2] = { false };
        bool whiteRooksMoved[2] = { false };
        bool blackKingChecked = false;
        bool whiteKingChecked = false;
    };
}

#endif //CHESS_CHESSGAMESTATE_H
