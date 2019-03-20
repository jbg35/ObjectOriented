#include <SFML/Graphics.hpp>
#include <time.h>
#include "Piece.hpp"
#include "Board.hpp"
using namespace sf;

int ts = 54; // tile size
Vector2i offset(48, 24);

int
main()
{
  srand(time(0));

  Board board(10,10);

  RenderWindow app(VideoMode(740, 480), "Match-3 Game!");
  app.setFramerateLimit(60);

  Texture t1, t2;
  t1.loadFromFile("images/background.png");
  t2.loadFromFile("images/gems.png");

  Sprite background(t1), gems(t2);

  board.fill(ts);

  int x0, y0, x, y;
  int click = 0;
  Vector2i pos;
  bool isSwap = false, isMoving = false;

  while (app.isOpen()) {
    Event e;
    while (app.pollEvent(e)) {
      if (e.type == Event::Closed)
        app.close();

      if (e.type == Event::MouseButtonPressed)
        if (e.mouseButton.button == Mouse::Left) {
          if (!isSwap && !isMoving)
            click++;
          pos = Mouse::getPosition(app) - offset;
        }
    }

    // mouse click
    if (click == 1) {
      x0 = pos.x / ts + 1;
      y0 = pos.y / ts + 1;
    }
    if (click == 2) {
      x = pos.x / ts + 1;
      y = pos.y / ts + 1;
      if (abs(x - x0) + abs(y - y0) == 1) {
        board.swap(board.getPiece(y0,x0), board.getPiece(y,x));
        isSwap = 1;
        click = 0;
      } else
        click = 1;
    }

    // Match finding
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++) {
        if (board.getPiece(i,j)== board.getPiece(i+1,j))
          if (board.getPiece(i,j) == board.getPiece(i-1,j))
            for (int n = -1; n <= 1; n++) {
              Piece &piece = board.getPiece(i+n, j);
              piece.match++;
            }

        if (board.getPiece(i,j) == board.getPiece(i,j+1))
          if (board.getPiece(i,j) == board.getPiece(i,j-1))
            for (int n = -1; n <= 1; n++){
              Piece &piece = board.getPiece(i+n, j);
              piece.match++;
            }
      }

    // Moving animation
    isMoving = false;
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++) {
        Piece& p = board.getPiece(i,j);
        int dx, dy;
        for (int n = 0; n < 4; n++) // 4 - speed
        {
          dx = p.x - p.col * ts;
          dy = p.y - p.row * ts;
          if (dx)
            p.x -= dx / abs(dx);
          if (dy)
            p.y -= dy / abs(dy);
        }
        if (dx || dy)
          isMoving = 1;
      }

    // Deleting amimation
    if (!isMoving)
      for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
          Piece &piece = board.getPiece(i,j);
          if (piece.match)
            if (piece.alpha > 10) {
              piece.alpha -= 10;
              isMoving = true;
            }
        }

    // Get score
    int score = 0;
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++) {
        Piece &piece = board.getPiece(i,j);
        score += piece.match;
      }

    // Second swap if no match
    if (isSwap && !isMoving) {
      if (!score)
        board.swap(board.getPiece(y0,x0), board.getPiece(y,x));
      isSwap = 0;
    }

    // Update grid
    if (!isMoving) {
      for (int i = 8; i > 0; i--)
        for (int j = 1; j <= 8; j++)
        {
          Piece &piece = board.getPiece(i,j);
          if (piece.match)
            for (int n = i; n > 0; n--){
              Piece &piece2 = board.getPiece(n,j);
              if (!piece2.match) {
                board.swap(board.getPiece(n,j), board.getPiece(i,j));
                break;
              };
        }
      }

      for (int j = 1; j <= 8; j++)
        for (int i = 8, n = 0; i > 0; i--) {
          Piece &piece = board.getPiece(i,j);
          if (piece.match) {
            piece.kind = rand() % 7;
            piece.y = -ts * n++;
            piece.match = 0;
            piece.alpha = 255;
          }
    }
  }

    //////draw///////
    app.draw(background);

    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++) {
        Piece &p = board.getPiece(i,j);
        gems.setTextureRect(IntRect(p.kind * 49, 0, 49, 49));
        gems.setColor(Color(255, 255, 255, p.alpha));
        gems.setPosition(p.x, p.y);
        gems.move(offset.x - ts, offset.y - ts);
        app.draw(gems);
      }

    app.display();
  }
  return 0;
}
