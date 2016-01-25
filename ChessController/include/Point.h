//
// Created by Nathan Sosnovske on 1/24/16.
//

#ifndef CHESS_POINT_H
#define CHESS_POINT_H

#include <stdint.h>

struct Point
{
    uint32_t x;
    uint32_t y;

public:
    Point(uint32_t , uint32_t);

    Point & operator=(const Point &rhs);
    bool operator==(const Point &other) const;
};

#endif //CHESS_POINT_H
