#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = ' ';
}

void Board::print() const {
    cout << "\nBoard:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ')
                cout << " " << i << j;
            else
                cout << " " << grid[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool Board::placeMarker(int row, int col, char marker) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid position! Try again.\n";
        return false;
    }
    if (grid[row][col] != ' ') {
        cout << "Position already taken! Try again.\n";
        return false;
    }
    grid[row][col] = marker;
    return true;
}

bool Board::hasWon(char marker) const {
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == marker && grid[i][1] == marker && grid[i][2] == marker) ||
            (grid[0][i] == marker && grid[1][i] == marker && grid[2][i] == marker))
            return true;
    }
    return (grid[0][0] == marker && grid[1][1] == marker && grid[2][2] == marker) ||
           (grid[0][2] == marker && grid[1][1] == marker && grid[2][0] == marker);
}

bool Board::isFull() const {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == ' ') return false;
    return true;
}
