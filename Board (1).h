#pragma once

class Board {
private:
    char grid[3][3];

public:
    Board();
    void print() const;
    bool placeMarker(int row, int col, char marker);
    bool hasWon(char marker) const;
    bool isFull() const;
};
