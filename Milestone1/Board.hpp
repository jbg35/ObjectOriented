#include <vector>


class Board {
private:
	std::vector<std::vector<Piece>> playingBoard;
public:
	Board(int,int);
	void fill(int);
	Piece& getPiece(int,int);
	void swap(Piece, Piece);
};

Board::Board(int x, int y) {
	Piece piece;
	for(int i = 0; i < x; i++){
		std::vector<Piece> col(y, piece);
		playingBoard.push_back(col);
	}
}

void Board::fill(int ts) {
	srand(time(0));

	for(int i=1; i<=8; i++) {
		for(int j=1; j<=8;j++) {
			playingBoard[i][j].kind=rand()%3;
			playingBoard[i][j].col=j;
			playingBoard[i][j].row=i;
			playingBoard[i][j].x=j*ts;
			playingBoard[i][j].y=i*ts;

		}
	}
}

Piece& Board::getPiece(int x, int y) {
	return playingBoard[x][y];
}

void Board::swap(Piece piece1, Piece piece2) {
	std::swap(piece1.col, piece2.col);
	std::swap(piece1.row, piece2.row);

	playingBoard[piece1.row][piece1.col] = piece1;
	playingBoard[piece2.row][piece2.col] = piece2;
}