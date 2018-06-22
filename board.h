#ifndef BOARD_H
#define BOARD_H

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Coord {
    public:
        int x, y;
        Coord delta(int dx, int dy) { return Coord{x+dx, y+dy}; };
};

struct Move {
    Coord src;
    Direction direction;
};

class Board {
    private:
        bool matrix[7][7];
    public:
        Board();
        void print();
        bool getValue(Coord c);
        void setValue(Coord c, bool state);
        bool checkMovePossible(Coord src, Direction d);
        static bool insideField(Coord c);
        void doMove(Move m);
        int amountOfPegs();
};

#endif