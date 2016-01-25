#include <stdlib.h>
#include "ChessBoard.h"

#include <iostream>

ChessController::ChessBoard::ChessBoard() : BlackKingLocation{ 0, 0 }, WhiteKingLocation{ 0, 0 }  { Initialize(); }
ChessController::ChessBoard::~ChessBoard() { }

bool ChessController::ChessBoard::Move(Point pointFrom, Point pointTo)
{
    //Same point, return false
    if(pointFrom == pointTo)
        return false;

    ChessPieceType fromType = GetSquarePieceType(pointFrom);
    ChessPieceColor fromColor = GetSquarePieceColor(pointFrom);

    ChessPieceType toType = GetSquarePieceType(pointTo);
    ChessPieceColor toColor = GetSquarePieceColor(pointTo);

    // Basic Sanity Checks

    // No moving to a square occupied by same color
    if(fromColor == toColor)
        return false;
    //No moving, if nothing exists
    if(fromType == ChessPieceType::NoPiece)
        return false;



    return false;
}

void ChessController::ChessBoard::Print()
{
    for(int i = 7; 0 <= i; i--)
    {
        for(int j = 0; j < 8; j++)
        {
            if(GetPieceAtSquare(Point(j, i)) == 0)
            {
                std::cout << "XX ";
                continue;
            }

            if(GetSquarePieceColor(Point(j, i)) == ChessPieceColor::White)
                std::cout << 'W';
            else if(GetSquarePieceColor(Point(j, i)) == ChessPieceColor::Black)
                std::cout << 'B';

            switch(GetSquarePieceType(Point(j, i)))
            {
                case ChessPieceType::Pawn:
                    std::cout << "P ";
                    break;
                case ChessPieceType::Knight:
                    std::cout << "k ";
                    break;
                case ChessPieceType::Bishop:
                    std::cout << "B ";
                    break;
                case ChessPieceType::Rook:
                    std::cout << "R ";
                    break;
                case ChessPieceType::Queen:
                    std::cout << "Q ";
                    break;
                case ChessPieceType::King:
                    std::cout << "K ";
                    break;
                default:
                    std::cout << "? ";
                    break;
            }
        }

        std::cout << '\n';
    }
}

Point ChessController::ChessBoard::GetKingLocation(ChessPieceColor color)
{
    if(color == ChessPieceColor::White)
        return WhiteKingLocation;
    else
        return BlackKingLocation;
}

//Private impl

void ChessController::ChessBoard::Initialize()
{
    if(_initialized)
        return;

    //Set the first white row
    SetPieceAtSquare(Point(0,0), ChessPieceType::Rook, ChessPieceColor::White);
    SetPieceAtSquare(Point(1,0), ChessPieceType::Knight, ChessPieceColor::White);
    SetPieceAtSquare(Point(2,0), ChessPieceType::Bishop, ChessPieceColor::White);
    SetPieceAtSquare(Point(3,0), ChessPieceType::Queen, ChessPieceColor::White);
    SetPieceAtSquare(Point(4,0), ChessPieceType::King, ChessPieceColor::White);
    SetPieceAtSquare(Point(5,0), ChessPieceType::Bishop, ChessPieceColor::White);
    SetPieceAtSquare(Point(6,0), ChessPieceType::Knight, ChessPieceColor::White);
    SetPieceAtSquare(Point(7,0), ChessPieceType::Rook, ChessPieceColor::White);

    //Set the pawns
    for(int i = 0; i < 8; i++)
    {
        SetPieceAtSquare(Point(i, 1), ChessPieceType::Pawn, ChessPieceColor::White);
        SetPieceAtSquare(Point(i, 6), ChessPieceType::Pawn, ChessPieceColor::Black);
    }
    //Set the first black row
    SetPieceAtSquare(Point(0,7), ChessPieceType::Rook, ChessPieceColor::Black);
    SetPieceAtSquare(Point(1,7), ChessPieceType::Knight, ChessPieceColor::Black);
    SetPieceAtSquare(Point(2,7), ChessPieceType::Bishop, ChessPieceColor::Black);
    SetPieceAtSquare(Point(3,7), ChessPieceType::Queen, ChessPieceColor::Black);
    SetPieceAtSquare(Point(4,7), ChessPieceType::King, ChessPieceColor::Black);
    SetPieceAtSquare(Point(5,7), ChessPieceType::Bishop, ChessPieceColor::Black);
    SetPieceAtSquare(Point(6,7), ChessPieceType::Knight, ChessPieceColor::Black);
    SetPieceAtSquare(Point(7,7), ChessPieceType::Rook, ChessPieceColor::Black);

    BlackKingLocation = Point(4, 7);
    WhiteKingLocation = Point(0, 7);

    _initialized = true;
}

int ChessController::ChessBoard::GetPieceAtSquare(Point point)
{
    //Perhaps we throw an exception here later, though those are costly and we may have to do this a lot
    if(point.x >= BOARD_SIZE || point.y >= BOARD_SIZE)
        return 0;

    return _board.at(point.x).at(point.y);
}

void ChessController::ChessBoard::SetPieceAtSquare(Point point, ChessPieceType type, ChessPieceColor color)
{
    if(point.x >= BOARD_SIZE || point.y >= BOARD_SIZE)
        return;

    int colorFactor = 1;
    if(color == ChessPieceColor::Black)
        colorFactor = -1;

    int pieceValue;
    switch(type)
    {
        case ChessPieceType::NoPiece:
            pieceValue = 0;
            break;
        case ChessPieceType::Pawn:
            pieceValue = 1;
            break;
        case ChessPieceType::Knight:
            pieceValue = 2;
            break;
        case ChessPieceType::Bishop:
            pieceValue = 3;
            break;
        case ChessPieceType::Rook:
            pieceValue = 4;
            break;
        case ChessPieceType::Queen:
            pieceValue = 5;
            break;
        case ChessPieceType::King:
            pieceValue = 6;
            break;
        default:
            pieceValue = 0;
            break;
    }

    _board.at(point.x).at(point.y) = pieceValue * colorFactor;
}

ChessController::ChessPieceColor ChessController::ChessBoard::GetSquarePieceColor(Point point)
{
    if(point.x >= BOARD_SIZE || point.y >= BOARD_SIZE)
        return ChessPieceColor::None;

    int piece = GetPieceAtSquare(point);

    if(piece == 0)
        return ChessPieceColor::None;
    else if(piece > 0)
        return ChessPieceColor::White;
    else
        return ChessPieceColor::Black;
}

ChessController::ChessPieceType ChessController::ChessBoard::GetSquarePieceType(Point point)
{
    if(point.x >= BOARD_SIZE || point.y >= BOARD_SIZE)
        return ChessPieceType::NoPiece;

    int piece = GetPieceAtSquare(point);

    switch(abs(piece))
    {
        case 0:
            return ChessPieceType::NoPiece;
        case 1:
            return ChessPieceType::Pawn;
        case 2:
            return ChessPieceType::Knight;
        case 3:
            return ChessPieceType::Bishop;
        case 4:
            return ChessPieceType::Rook;
        case 5:
            return ChessPieceType::Queen;
        case 6:
            return ChessPieceType::King;
        default:
            return ChessPieceType::NoPiece;
    }

}



