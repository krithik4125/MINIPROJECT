#pragma once
#include <string>
using namespace std;

class Player {
private:
    string name;
    char   marker;

public:
    Player(const string& playerName, char playerMarker);
    char          getMarker() const;
    const string& getName()   const;
    void          getMove(int& row, int& col) const;
};
