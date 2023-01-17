#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece {
/// <summary>
/// Defines the Rook Class
/// Moves horizontally and vertically infinitely
/// </summary>
public:
    Rook(int type, int xPos, int yPos = -1) {
        code = type;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * getTeam()};
        // vectors moving to edge of board both horizontally and vertically
        for (int i = 0; i<8; i++) {
            if ( i - position[0] ) {
                vectors.push_back(array<int, 2> {i-position[0], 0});        // horizontal
            }
            if ( i - position[1] ) {
                vectors.push_back(array<int, 2> {0, i-position[1]});        // vertical
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
        for (auto vec : vectors) {
            if (isPathClear(board, getPosition(), vec)) {
                allowed.push_back(vec);
            }
        }
        return allowed;
    }

    array<int, 2> moveBy(array<int, 2> vec) {
        return addVectors(position, vec);
    }

private:
    int code;       // 1-6 for piece type || 00 for white & 10 for black
    string name = "Rook";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 0 when black and 7 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};
