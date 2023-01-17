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
    Knight(int type, int xPos, int yPos = -1) {
        code = type;
        position = { xPos, yPos != -1 ? yPos : 7 - 7 * getTeam()};

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
        // All movements are legal by leap or take with exception of friendly pieces
        vector<array<int, 2>> allowed;
        for (auto vec : vectors) {
            array<int, 2> pos = getPosition();      // position
            array<int, 2> coor = addVectors(pos, vec);      // movement
            if (board[coor[1]][coor[0]] == board[pos[1]][pos[0]]) { continue; }     // node occupied by friendly
            allowed.push_back(vec);
        }
        return allowed;
    }

    array<int, 2> moveBy(array<int, 2> vec) {
        return addVectors(position, vec);
    }

private:
    int code;       // 0 is white | 1 is black
    string name = "Knight";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 0 when black and 7 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};

