#include <iostream>
using namespace std;

class ChessPiece {
	public:
		string name;
};

class Pawn: public ChessPiece {
	public:
		string name = "Pawn";
};

int main() {
	Pawn pan;

	cout << pan.name;
	return 0;
}