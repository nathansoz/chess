//
// Created by Nathan Sosnovske on 1/23/16.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <array>
#include <memory>



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
    private:
        std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> _board;
        bool _initialized;


        void Populate();
    };
}

#endif //CHESS_BOARD_H
