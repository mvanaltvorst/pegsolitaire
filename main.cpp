#include "board.h"
#include <iostream>

bool solveBoard(Board * b, Move history[32], int depth);

int main() {
    Board b;
    Move history[31];
    if (solveBoard(&b, history, 0)) std::cout << "Found solution" << std::endl;

    b = Board();
    b.print();
    for (int i = 0; i < 31; i++) {
        b.doMove(history[i]);
        std::cout << std::endl;
        b.print();
    }
    return 0;
}

bool solveBoard(Board * b, Move history[31], int depth) {
    if (b->amountOfPegs() == 1) {
        if (b->getValue(Coord{3, 3})) return true;
        return false;
    }
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            Board old_board = *b;
            Coord c = Coord{x, y};
            Move m;

            if (b->checkMovePossible(c, Direction::UP)) {
                m = Move{c, Direction::UP};
                b->doMove(m);
                history[depth] = m;
                if (solveBoard(b, history, depth + 1)) return true;
                *b = old_board;
            }
            if (b->checkMovePossible(c, Direction::DOWN)) {
                m = Move{c, Direction::DOWN};
                b->doMove(m);
                history[depth] = m;
                if (solveBoard(b, history, depth + 1)) return true;
                *b = old_board;
            }
            if (b->checkMovePossible(c, Direction::LEFT)) {
                m = Move{c, Direction::LEFT};
                b->doMove(m);
                history[depth] = m;
                if (solveBoard(b, history, depth + 1)) return true;
                *b = old_board;
            }
            if (b->checkMovePossible(c, Direction::RIGHT)) {
                m = Move{c, Direction::RIGHT};
                b->doMove(m);
                history[depth] = m;
                if (solveBoard(b, history, depth + 1)) return true;
                *b = old_board;
            }
        }
    }

    return false;
}