#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

Vector2i offset(48, 24);

struct listener
{
  virtual void on_close() { }
  virtual void on_gain_focus() { }
  virtual void on_lose_focus() { }

  virtual void on_mouse_button_press(sf::Event::MouseButtonEvent) { }
  virtual void on_mouse_button_release(sf::Event::MouseButtonEvent) { }

};

struct graphics
{
  graphics()
  {
    textures[0].loadFromFile("images/background.png");
    textures[1].loadFromFile("images/gems.png");

    background.setTexture(textures[0]);
    gems.setTexture(textures[1]);
  }

  sf::Texture textures[2];
  sf::Sprite background;
  sf::Sprite gems;
};

struct events
{
  events(sf::Window& w)
    : window(&w)
  { }

  void
  listen(listener& l) { listeners.push_back(&l); }

  void
  poll()
  {
    sf::Event e;
    while (window->pollEvent(e))
      switch (e.type) {
        case Event::Closed:
          window->close();
        case Event::MouseButtonPressed:
          return notify([e](listener* l) { l->on_mouse_button_press(e.mouseButton); });
        case Event::MouseButtonReleased:
          return notify([e](listener* l) { l->on_mouse_button_release(e.mouseButton); });

        default:
          break;
    }
  }

  template<typename T>
  void notify(T function)
  {
    for (listener* l : listeners)
      function(l);    
  }

  sf::Window* window;

  std::vector<listener*> listeners;
};



struct bejeweled : listener
{
  bejeweled()
    : window(VideoMode(740, 480), "Match-3 Game!"),
      grid()
  { window.setFramerateLimit(120); }

  bool is_open() const { return window.isOpen(); }

  void  on_mouse_button_press(sf::Event::MouseButtonEvent e) override
  {
    if (e.button == Mouse::Left) {
      if (!swapping && !moving) {
        click++;
      }
    }
    
    Vector2i pos = Mouse::getPosition(window) - offset;

    if (click == 1) {
      x0 = pos.x / ts + 1;
      y0 = pos.y / ts + 1;
    }
    if (click == 2) {
      x1 = pos.x / ts + 1;
      y1 = pos.y / ts + 1;
      if (abs(x1 - x0) + abs(y1 - y0) == 1) {
        std::swap(grid[y0][x0], grid[y1][x1]);
        swapping = 1;
        click = 0;
      } else {
        click = 1;
      }
    }
  }

  void
  game_phyiscs()
  {
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        if (grid[i][j].kind == grid[i + 1][j].kind) {
          if (grid[i][j].kind == grid[i - 1][j].kind) {
            for (int n = -1; n <= 1; n++)
              grid[i + n][j].match++;
          }
        }

        if (grid[i][j].kind == grid[i][j + 1].kind) {
          if (grid[i][j].kind == grid[i][j - 1].kind) {
            for (int n = -1; n <= 1; n++)
              grid[i][j + n].match++;
          }
        }
      }
    }
        moving = false;
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        piece& p = grid[i][j];
        int dx, dy;
        for (int n = 0; n < 4; n++) { // 4 - speed
          dx = p.x - p.col * ts;
          dy = p.y - p.row * ts;
          if (dx)
            p.x -= dx / abs(dx);
          if (dy)
            p.y -= dy / abs(dy);
        }
        if (dx || dy)
          moving = true;
      }
    }
      if (!moving) {
      for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
          if (grid[i][j].match) {
            if (grid[i][j].alpha > 10) {
              grid[i][j].alpha -= 10;
              moving = true;
            }
          }
        }
      }
    }
    if (!moving) {
      for (int i = 8; i > 0; i--) {
        for (int j = 1; j <= 8; j++) {
          if (grid[i][j].match) {
            for (int n = i; n > 0; n--) {
              if (!grid[n][j].match) {
                swap(grid[n][j], grid[i][j]);
                break;
              }
            }
          }
        }
      }

      for (int j = 1; j <= 8; j++) {
        for (int i = 8, n = 0; i > 0; i--) {
          if (grid[i][j].match) {
            grid[i][j].kind = rand()%3;
            grid[i][j].y = -ts * n++;
            grid[i][j].match = 0;
            grid[i][j].alpha = 255;
          }
        }
      }
    }

  }

  void
  draw_board()
  {
    window.draw(sprites.background);

    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        piece p = grid[i][j];
        sprites.gems.setTextureRect(IntRect(p.kind * 49, 0, 49, 49));
        sprites.gems.setColor(Color(255, 255, 255, p.alpha));
        sprites.gems.setPosition(p.x, p.y);
        sprites.gems.move(offset.x - ts, offset.y - ts);
        window.draw(sprites.gems);
      }
    }
    window.display();
  }

  sf::RenderWindow window;
  graphics sprites;
  board grid;

  int x0, y0, x1, y1, click = 0;
  bool swapping = false, moving = false; 
};