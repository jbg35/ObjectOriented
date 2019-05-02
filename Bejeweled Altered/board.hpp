#pragma once

int ts = 54;

struct board
{
  board()
  {
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        grid[i][j].kind = rand()%3;
        grid[i][j].col = j;
        grid[i][j].row = i;
        grid[i][j].x = j * ts;
        grid[i][j].y = i * ts;
      }
    }
  }
  
  using row = piece (&)[10];
  using const_row = piece const (&)[10];
  row operator[](int r) { return grid[r]; }
  const_row operator[](int r) const { return grid[r]; }

  piece grid[10][10];
};