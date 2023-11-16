#ifndef CONNECT_H
#define CONNECT_H

#include "animation.h"
#include "types.h"

void init_board(Board* board_ptr);

void drop_piece(Board* board_ptr, int column, Color pColor);

int check_win(Board* board_ptr);

int get_move(Board* board_ptr, Color pColor, int debug_delay);

void player_turn(Board* board_ptr, Color color);

void computer_turn(Board* board_ptr, Color pColor);

void menu_main();

void loop_game();

#endif // !CONNECT_H
