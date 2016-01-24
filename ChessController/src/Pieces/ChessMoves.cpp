//
// Created by Nathan Sosnovske on 1/24/16.
//

#include "Pieces/ChessMoves.h"

bool ChessPieces::ChessMoves::ValidMove(ChessPieces pieceType, int fromX, int fromY, int toX, int toY)
{
    auto doCall =  _moveFunctions[(int)pieceType];
    return doCall(fromX, fromY, toX, toY);
}

const ChessPieces::ChessMove ChessPieces::ChessMoves::_pawnFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessPieces::ChessMove ChessPieces::ChessMoves::_knightFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessPieces::ChessMove ChessPieces::ChessMoves::_bishopFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessPieces::ChessMove ChessPieces::ChessMoves::_rookFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessPieces::ChessMove ChessPieces::ChessMoves::_queenFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessPieces::ChessMove ChessPieces::ChessMoves::_kingFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return true;
};

const std::vector<ChessPieces::ChessMove> ChessPieces::ChessMoves::_moveFunctions = {
        _pawnFunction, _knightFunction, _bishopFunction, _rookFunction, _queenFunction, _kingFunction
};


