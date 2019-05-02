#include <iostream>
#include <random>

#include "piece.hpp"
#include "board.hpp"
#include "bejeweled.hpp"

int
main()
{
  bejeweled game;

  events event(game.window);
  event.listen(game);

  while (game.is_open()) {
    event.poll();

    game.game_phyiscs();
    game.draw_board();
  }
  
  return 0;
}
