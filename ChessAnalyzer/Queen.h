#pragma once
#include "ChessPiece.h"
#include <array>
using namespace std;

class Queen : public ChessPiece {
    /// <summary>
    /// Defines the Queen Class
    /// Moves horizontally, vertically, and diagonally infinitely
    /// </summary>
public:
    Queen(int isBlack, int xPos, int yPos = -1) {
        type = isBlack;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * type };
        for (int i = 0; i < 8; i++) {
            if (i - position[0]) {
                vectors.push_back(array<int, 2> {i - position[0], 0});      // horizontal
                if ( i - position[0] + position[1] >= 0 && i - position[0] + position[1] < 8 ) {
                    vectors.push_back(array<int, 2> {i - position[0], i - position[0]});        // main diagonal
                }
                if (
                    -i + 2 * position[0] >= 0 &&
                    -i + 2 * position[0] < 8 &&
                    i - position[0] + position[1] >= 0 &&
                    i - position[0] + position[1] < 8
                ) {
                    vectors.push_back(array<int, 2> {-(i - position[0]), i - position[0]});     // opposite diagonal
                }
            }
            if ( i - position[1] ) {
                vectors.push_back(array<int, 2> {0, i - position[1]});      // vertically
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
    string name = "Queen";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};


