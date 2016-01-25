//
// Created by Nathan Sosnovske on 1/24/16.
//

#include <ChessBoard.h>

Point::Point(uint32_t x, uint32_t y) : x{x + BOARD_OFFSET}, y{ y + BOARD_OFFSET } { };

Point & Point::operator=(const Point &rhs)
{
    if(this == &rhs)
        return *this;

    this->x = rhs.x;
    this->y = rhs.y;

    return *this;
}

bool Point::operator==(const Point &other) const
{
    return this->y == other.y && this->x == other.x;
}