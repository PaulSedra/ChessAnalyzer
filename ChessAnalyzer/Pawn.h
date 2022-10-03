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
    Pawn(int isBlack, int xPos, int yPos=-1) {
        type = isBlack;
        position = { xPos, yPos != -1? yPos : 6 - 5 * type };
        if ( type && position[1] < 7 || !type && position[1] > 0 ) {
            vectors = {
                { 0, 2 * type - 1 }
            };
        }
    }

    int getType() {
        return type;
    };

    string getName() {
        return name;
    };

    array<int, 2> getPosition() {
        return position;
    }

    vector<array<int, 2>> getLegalMoves() {
        return vectors;
    }

    array<int, 2> moveBy(array<int, 2> vec) {
        return addVectors(position, vec);
    }

private:
    int type;       // 0 is white | 1 is black
    string name = "Pawn";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};


