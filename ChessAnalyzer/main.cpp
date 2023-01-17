#include <iostream>
#include <array>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
using namespace std;

int main() {
	/// <summary>
	/// this console app implements tools for chessboard analysis
	/// </summary>
	/// <returns></returns>

	// board represents empty | occupied nodes
	int board[8][8] = {
		{0,0,0,0,0,0,0,0},	// black = 2
		{0,0,0,0,0,0,0,0},	// black | pawns 
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},	// white | pawns
		{0,0,0,0,0,0,0,0}	// white = 1
	};

	// Creates White Pawns
	//TODO ChessPiece can create appropriate piece by code
	vector<Pawn> whitePawns{ Pawn(11,0), Pawn(1,1), Pawn(1,2), Pawn(1,3), Pawn(1,4), Pawn(1,5), Pawn(1,6), Pawn(1,7) };
	
	// Modify Board
	for (auto whitePawn : whitePawns) {
		array<int, 2> pos = whitePawn.getPosition();
		board[pos[1]][pos[0]] = whitePawn.getCode();
	}
	
	// Displays Board in Console
	for (auto &row : board) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	//// Checks for White Pawn movement availability
	//// TODO implement path is clear
	//int count = 0;
	//for (auto whitePawn : whitePawns) {
	//	for (auto moveVec : whitePawn.getLegalMoves()) {
	//		array<int, 2> pos = whitePawn.moveBy(moveVec);
	//		if ( ! board[pos[1]][pos[0]] ) {
	//			count++;
	//		}

	//	}
	//		
	//}

	//cout << count;

	// Testing King Vectors
	//TODO Create Test Classes
	//Bishop pan(0, 0, 7);
	//cout << pan.getPosition()[0] << " " << pan.getPosition()[1] << endl << endl;
	//for (auto vec : pan.getLegalMoves(board)) {
	//	cout << vec[0] << " " << vec[1] << " " << board[vec[1] + pan.getPosition()[1]][vec[0] + pan.getPosition()[0]] << endl;
	//}
	return 0;
}