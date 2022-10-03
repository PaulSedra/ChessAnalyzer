#pragma once
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class ChessPiece {
/// <summary>
/// Defines the BaseClass for all Chess Pieces
/// </summary>
public:
    ChessPiece() = default;
    ChessPiece(int isBlack) {
        type = isBlack;
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

protected:
    array<int, 2> addVectors(array<int, 2> pos, array<int, 2> vec) {
        return {pos[0] + vec[0], pos[1] + vec[1]};
    }

private:
    int type;       // 0 is white | 1 is black
    string name = "Chess Piece";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};
;