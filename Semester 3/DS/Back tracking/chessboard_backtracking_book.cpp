#include <iostream>
using namespace std;

class ChessBoard {
	public:
		ChessBoard(); // 8 x 8 chessboard;
		ChessBoard(int); // n x n chessboard;
		void findSolutions();
	private:
		const bool available;
		const int squares, norm;
		bool *column, *leftDiagonal, *rightDiagonal;
		int *positionInRow, howMany;
		void putQueen(int);
		void printBoard(ostream&);
		void initializeBoard();
		void printAll();
};
ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1){
	initializeBoard();
}
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
	initializeBoard();
}
void ChessBoard::initializeBoard() {
	register int i;
	column = new bool[squares];
	positionInRow = new int[squares];
	leftDiagonal = new bool[squares*2 - 1];
	rightDiagonal = new bool[squares*2 - 1];
	for (i = 0; i < squares; i++)
		positionInRow[i] = -1;
	for (i = 0; i < squares; i++)
		column[i] = available;
	for (i = 0; i < squares*2 - 1; i++)
		leftDiagonal[i] = rightDiagonal[i] = available;
	howMany = 0;
}

void ChessBoard::printAll(){
	cout << "\npositionInRow\n";
	for (int i = 0; i < squares; i++){
		cout << positionInRow[i] << " ";
		}
	cout << "\ncolumn\n";
	for (int i = 0; i < squares; i++){
		cout << column[i] << " ";
		}
		cout << "\nleftDiagonal\n";
	for (int i = 0; i < squares*2 - 1; i++){
		cout << leftDiagonal[i] << " "; 
		}
		cout << "\nrightDiagonal\n";
	for (int i = 0; i < squares*2 - 1; i++){
		cout << rightDiagonal[i] << " "; 
		}
		cout << "\n";
}

void ChessBoard::putQueen(int row) {
//	printAll();
	for (int col = 0; col < squares; col++)
		if (column[col] == available &&
		leftDiagonal [row+col] == available &&
		rightDiagonal[row-col+norm] == available) {
			
			positionInRow[row] = col;
			column[col] = !available;
			leftDiagonal[row+col] = !available;
			rightDiagonal[row-col+norm] = !available;
			
			if (row < squares-1)
				putQueen(row+1);
			else {
				cout << "\nDone. printBoard\n";
				printAll();
				howMany++;
			}
			
			column[col] = available;
			leftDiagonal[row+col] = available;
			rightDiagonal[row-col+norm] = available;
		}
}
void ChessBoard::findSolutions() {
	putQueen(0);
	cout << howMany << " solutions found.\n";
}
int main(){
	ChessBoard cb(4);
	cb.findSolutions();
}
