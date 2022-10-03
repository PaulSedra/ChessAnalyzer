#pragma once
#include "ChessPiece.h"
#include <array>
using namespace std;

class Bishop : public ChessPiece{
    /// <summary>
    /// Defines the Bishop Class
    /// Moves diagonally infinitely
    /// </summary>
public:
    Bishop(int isBlack, int xPos, int yPos = -1) {
        type = isBlack;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * type };
        // vectors moving to edge of board diagonally
        for (int i = 0; i < 8; i++) {
            if ( i - position[0] ) {
                if ( i - position[0] + position[1] >= 0 && i - position[0] + position[1] < 8 ) {
                    vectors.push_back(array<int, 2> {i - position[0], i - position[0]});        // main diagonal
                }
                if (
                    -i + 2*position[0] >= 0 &&
                    -i + 2*position[0] < 8 &&
                    i - position[0] + position[1] >= 0 &&
                    i -  position[0] + position[1] < 8
                ) {
                    vectors.push_back(array<int, 2> {-(i - position[0]), i - position[0]});     // opposite diagonal
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
    string name = "Bishop";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};


