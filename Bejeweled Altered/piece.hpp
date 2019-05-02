#pragma once 

struct piece
{
  int x, y, col, row, kind, match, alpha;

  piece()
    : x(), y(), col(), row(), kind(), match(), alpha(255)
      { }

  friend void
  swap(piece& a, piece& b)
  {
    std::swap(a.col, b.col);
    std::swap(a.row, b.row);
  }

};