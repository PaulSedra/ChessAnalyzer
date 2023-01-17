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
    ChessPiece(int type) {
        code = type;
    }
    
    int getCode() {
        return code;    // for representation purposes
    }

    int getTeam() {
        //? public || protected || private
        return code > 10;    // Black team if code > 10 else White Team
    };

    int getPiece() {
        /*
            The number in the unit's place represents piece type
            1 - Pawn
            2 - Rook
            3 - Knight
            4 - Bishop
            5 - Queen
            6 - King
        */
        return code % 10;
    }

    string getName() {
        return name;
    };

    array<int, 2> getPosition() {
        return position;
    }

    vector<array<int, 2>> getLegalMoves(int board[8][8]) {
        return vectors;
    }

protected:
    array<int, 2> addVectors(array<int, 2> pos, array<int, 2> vec) {
        return {pos[0] + vec[0], pos[1] + vec[1]};
    }

    bool isPathClear(int board[8][8], array<int, 2> pos, array<int, 2> vec) {
        // need board, position, end position
        bool take = false;      // piece can take another piece of opposite type    *OVERIDE in Pawn Class*
        int scalar = abs(max(vec[0], vec[1]));       // absolute value of max entry of vector
        array<int, 2> unitVec = { vec[0] / scalar, vec[1] / scalar };
        for (int i = 1; i <= scalar; i++) {
            array<int, 2> step = addVectors(pos, {unitVec[0]*i, unitVec[1]*i});       // add the unit vector i times
            if (!board[step[1]][step[0]]) { continue; }     // node is empty => step clear
            if (take) { return false; }     // node is not empty and take has been used
            if (board[pos[1]][pos[0]] == board[step[1]][step[0]]) { return false; }        // same type chess piece in the way
            take = true;    // must take piece to proceed
        }
        return true;
    }

private:
    //TODO create getters and setters >> note for position setter need to check if movement vector in legal movements and recalculate possible vectors
    //? Can inherit getters and setters?
    int code;       // 1-6 for piece type || 00 for white & 10 for black
    string name = "Chess Piece";       // Piece name
    array<int, 2> position;       // < x is set in constructor, y is 1 when black and 6 when white >
    vector<array<int, 2>> vectors;      // array of legal vector movements in the form <x, y>
};