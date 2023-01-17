#pragma once
#include "ChessPiece.h"
#include <array>
using namespace std;

class Pawn : public ChessPiece {
/// <summary>
/// Defines the Pawn Class
/// Moves forwards by one | Direction is determined by type
/// </summary>
public:
    Pawn(int type, int xPos, int yPos=-1) {
        code = type;
        position = { xPos, yPos != -1? yPos : 6 - 5 * getTeam()};
        if ( getTeam() && position[1] < 7 || !getTeam() && position[1] > 0) {
            vectors = {
                { 0, -1 + 2 * getTeam() }
            };
            take = {
                { -1, -1 + 2 * getTeam() },  // left take
                { 1, -1 + 2 * getTeam() },   // right take
            };
            if (getTeam() == 0 && position[1] == 6) {
                vectors.push_back(array<int, 2> {0, -2});
            } else if (getTeam() == 1 && position[1] == 1) {
                vectors.push_back(array<int, 2> {0, 2});
            }
        }
    }

    int getCode() {
        return code;    // for representation purposes
    }

    int getTeam() {
        return code > 10;    // Black team if code > 10 else White Team
    };

    string getName() {
        return name;
    };

    array<int, 2> getPosition() {
        return position;
    }

    vector<array<int, 2>> getLegalMoves(int board[8][8]) {
        vector<array<int, 2>> allowed;
        // movement vectors
        for (auto vec : vectors) {
            if (isPathClear(board, getPosition(), vec)) {
                allowed.push_back(vec);
            }
        }
        // take vectors
        for (auto vec : take) {
            array<int, 2> coor = addVectors(getPosition(), vec);
            if (board[coor[1]][coor[0]] == !getTeam()) {     // node occupied by enemy
                allowed.push_back(vec);
            }
        }
        return vectors;
    }

    array<int, 2> moveBy(array<int, 2> vec) {
        return addVectors(position, vec);
    }

private:
    int code;       // 1-6 for piece type || 00 for white & 10 for black
    string name = "Pawn";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
    vector<array<int, 2>> take;     // special diagonal take vectors
};


