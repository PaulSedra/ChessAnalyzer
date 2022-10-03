#pragma once
#include "ChessPiece.h"
#include <array>
using namespace std;

class Knight : public ChessPiece {
    /// <summary>
    /// Defines the Knight Class
    /// Moves in L shape << 8 directions
    /// </summary>
public:
    Knight(int isBlack, int xPos, int yPos = -1) {
        type = isBlack;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * type };

        // vectors for moving in 8 directions << L Shape when in range of board indices <7,7>
        for ( int i : array<int, 2 > {2, -2} ) {
            for (int j : array<int, 2> {1, -1}) {
                if ( 0 <= position[0] + i && position[0] + i < 8 && 0 <= position[1] + j && position[1] + j < 8 ) {
                    vectors.push_back(array<int, 2> {i, j});
                }
                if ( 0 <= position[0] + j && position[0] + j < 8 && 0 <= position[1] + i && position[1] + i < 8 ) {
                    vectors.push_back(array<int, 2> {j, i});
                }
            }
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
    string name = "Knight";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 0 when black and 7 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};

