#ifndef BOARD_H
#define BOARD_H

struct Coord {
    int x;
    int y;
};

class Board {
    private:
        bool matrix[7][7];
    public:
        Board();
        void print();
        bool getValue(Coord c);
        void setValue(Coord c, bool state);
        bool checkMovePossible(Coord src, Coord dst);
        static bool insideField(Coord c);
};

#endif