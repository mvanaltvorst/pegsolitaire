#include <iostream>
#include "board.h"


Board::Board() {
    bool matrix[7][7];
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            setValue(Coord{x, y}, false);
            if (x==3 && y==3) continue; // middle
            if ((x < 2 || x > 4) && (y < 2 || y > 4)) continue; // 2x2 corners
            setValue(Coord{x, y}, true);
        }
    }
}

void Board::print() {
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            getValue(Coord{x, y}) ? std::cout << '#' : std::cout << '*';
        }
        std::cout << std::endl;
    }
}

bool Board::getValue(Coord c) {
    return matrix[c.y][c.x];
}

void Board::setValue(Coord c, bool state) {
    matrix[c.y][c.x] = state;
}

// bool Board::checkMovePossible(Coord src, Direction d) {
//     if (!insideField(src) || !insideField(dst)) return false;
//     if (getValue(dst)) return false;
// }

bool Board::insideField(Coord c) {
    return (c.x >= 0 && c.x < 7 || c.y >= 0 && c.y < 7 && (!((c.x < 2 || c.x > 4) && (c.y < 2 || c.y > 4))));
}