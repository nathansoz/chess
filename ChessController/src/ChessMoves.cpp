//
// Created by Nathan Sosnovske on 1/24/16.
//

#include "ChessMoves.h"

bool ChessController::ChessMoves::ValidMove(ChessPieceType pieceType, int fromX, int fromY, int toX, int toY)
{
    auto doCall =  _moveFunctions[(int)pieceType];
    return doCall(fromX, fromY, toX, toY);
}

const ChessController::ChessMove ChessController::ChessMoves::_pawnFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessController::ChessMove ChessController::ChessMoves::_knightFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessController::ChessMove ChessController::ChessMoves::_bishopFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessController::ChessMove ChessController::ChessMoves::_rookFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessController::ChessMove ChessController::ChessMoves::_queenFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return false;
};
const ChessController::ChessMove ChessController::ChessMoves::_kingFunction =
        [] (int fromX, int fromY, int toX, int toY)
{
    return true;
};

const std::vector<ChessController::ChessMove> ChessController::ChessMoves::_moveFunctions = {
        _pawnFunction, _knightFunction, _bishopFunction, _rookFunction, _queenFunction, _kingFunction
};


