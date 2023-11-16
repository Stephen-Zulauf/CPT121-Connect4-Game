#include "animation.h"


void print_title() {
	printf("   _____                            _   ______ \n");
	printf("  / ____|                          | | |  ____|\n");
	printf(" | |     ___  _ __  _ __   ___  ___| |_| |__ ___  _   _ _ __\n");
	printf(" | |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __|  __/ _ \\| | | | '__|\n");
	printf(" | |___| (_) | | | | | | |  __/ (__| |_| | | (_) | |_| | |\n");
	printf("  \\_____\\___/|_| |_|_| |_|\\___|\\___|\\__|_|  \\___/ \\__,_|_|\n");
}

//print current board
void print_board(Board* board) {
	int i, j;

	printf("  0  1  2  3  4  5  6 ");
	for (i = 0; i < board->num_rows; i++) {
		printf("\n");
		printf("%d", i);
		for (j = 0; j < board->num_cols; j++) {
			if (board->game_board[i][j].piece.token_color == RED) {
				printf(" r ");
			}
			else if (board->game_board[i][j].piece.token_color == BLACK) {
				printf(" b ");
			}
			else {
				printf(" - ");
			}

		}
	}
}