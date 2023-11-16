#ifndef CONNECT_TYPES_H
#define CONNECT_TYPES_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CONNECT4_ROWS 6
#define CONNECT4_COLS 7

typedef enum color
{
	NONE, RED = 1, BLACK
} Color;

typedef struct position
{
	int row,
		col;
}Position;

typedef struct token
{
	Color token_color;
	Position location;
	// char color; // we'll use something other than char
}Token;

typedef struct cell
{
	Token piece;
	Position location;
}Cell;

typedef struct board
{
	Cell game_board[CONNECT4_ROWS][CONNECT4_COLS];
	int num_rows,
		num_cols;
}Board;

void delay(int number_of_seconds);


#endif // !CONNECT_TYPES_H

