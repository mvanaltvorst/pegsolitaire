#include <iostream>
#include "board.h"


Board::Board() {
    bool matrix[7][7];
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            setValue(Coord{x, y}, false);
            if (x==3 && y==3) continue; // middle
            if(!insideField(Coord{x, y})) continue;
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

bool Board::checkMovePossible(Coord src, Direction d) {
    Coord middle;
    Coord dst;

    switch (d) {
        case Direction::UP:
            middle = src.delta(0, -1);
            dst = src.delta(0, -2);
            break;
        case Direction::DOWN:
            middle = src.delta(0, 1);
            dst = src.delta(0, 2);
            break;
        case Direction::LEFT:
            middle = src.delta(-1, 0);
            dst = src.delta(-2, 0);
            break;
        case Direction::RIGHT:
            middle = src.delta(1, 0);
            dst = src.delta(2, 0);
            break; 
    }

    if (!(insideField(src) && 
          insideField(middle) && 
          insideField(dst) &&
          getValue(src) &&
          getValue(middle))) return false;
    if (getValue(dst)) return false;
    return true;
}

bool Board::insideField(Coord c) {
    if ((c.x < 2 || c.x > 4) && (c.y < 2 || c.y > 4)) return false;
    return (c.x >= 0 && c.x < 7 && c.y >= 0 && c.y < 7);
}

int Board::amountOfPegs() {
    int acc = 0;
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            if (getValue(Coord{x, y})) acc++;
        }
    }
    return acc;
}

void Board::doMove(Move m) {
    //TODO: Make a function of the direction->coords conversion
    Coord middle;
    Coord dst;
    Coord src = m.src;

    switch (m.direction) {
        case Direction::UP:
            middle = src.delta(0, -1);
            dst = src.delta(0, -2);
            break;
        case Direction::DOWN:
            middle = src.delta(0, 1);
            dst = src.delta(0, 2);
            break;
        case Direction::LEFT:
            middle = src.delta(-1, 0);
            dst = src.delta(-2, 0);
            break;
        case Direction::RIGHT:
            middle = src.delta(1, 0);
            dst = src.delta(2, 0);
            break; 
    }

    setValue(dst, true);
    setValue(src, false);
    setValue(middle, false);
}