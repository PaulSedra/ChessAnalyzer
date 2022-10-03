#pragma once
#include "ChessPiece.h"
#include <array>
using namespace std;

class King : public ChessPiece {
    /// <summary>
    /// Defines the King Class
    /// Moves horizontally, vertically, and diagonally by 1
    /// </summary>
public:
    King(int isBlack, int xPos, int yPos = -1) {
        type = isBlack;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * type };
        for (int i: array<int, 2> {-1, 1}) {
            if ( i + position[0] >= 0 && i + position[0] < 8 ) {
                vectors.push_back(array<int, 2> {i, 0});      // horizontal
                if ( i + position[1] >= 0 && i + position[1] < 8 ) {
                    vectors.push_back(array<int, 2> {i, i});        // main diagonal
                }
            }
            if ( i + position[1] >= 0 && i + position[1] < 8 ) {
                vectors.push_back(array<int, 2> {0, i});      // vertically
                if ( -i + position[0] >= 0 && -i + position[0] < 8 ) {
                    vectors.push_back(array<int, 2> {-i, i});     // opposite diagonal
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
    string name = "King";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};


