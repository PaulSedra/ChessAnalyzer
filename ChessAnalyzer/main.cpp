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
		{0,0,0,0,0,0,0,0},	// black
		{0,0,0,0,0,0,0,0},	// black | pawns 
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},	// white | pawns
		{0,0,0,0,0,0,0,0}	// white
	};

	// Creates White Pawns
	vector<Pawn> whitePawns{ Pawn(0,0), Pawn(0,1), Pawn(0,2), Pawn(0,3), Pawn(0,4), Pawn(0,5), Pawn(0,6), Pawn(0,7) };
	
	// Modify Board
	for (auto whitePawn : whitePawns) {
		array<int, 2> pos = whitePawn.getPosition();
		board[pos[1]][pos[0]] = 1;
	}

	// Displays Board in Console
	for (auto &row : board) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	// Checks for White Pawn movement availability
	int count = 0;
	for (auto whitePawn : whitePawns) {
		for (auto moveVec : whitePawn.getLegalMoves()) {
			array<int, 2> pos = whitePawn.moveBy(moveVec);
			if ( ! board[pos[1]][pos[0]] ) {
				count++;
			}

		}
			
	}

	cout << count;

	// Testing King Vectors
	//TODO Create Test Classes
	//King pan(1, 1, 0);
	//cout << pan.getPosition()[0] << " " << pan.getPosition()[1] << endl << endl;
	//for (auto vec : pan.getLegalMoves()) {
	//	cout << vec[0] << " " << vec[1] << endl;
	//}
	return 0;
}