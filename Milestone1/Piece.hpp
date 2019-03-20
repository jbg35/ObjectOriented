#pragma once 

struct Piece
{
  int x, y, col, row, kind, match, alpha;
  Piece()
  {
    match = 0;
    alpha = 255;
  }
};

bool operator==(const Piece& piece1, const Piece& piece2) {
	return piece1.kind == piece2.kind;
}