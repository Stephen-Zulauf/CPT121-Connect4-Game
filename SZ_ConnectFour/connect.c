#include "connect.h"


void init_board(Board* board_ptr)
{
	int row_index = 0, col_index = 0;

	board_ptr->num_rows = CONNECT4_ROWS;
	board_ptr->num_cols = CONNECT4_COLS;

	for (; row_index < board_ptr->num_rows; ++row_index) // controls rows
	{
		for (col_index = 0; col_index < board_ptr->num_cols; ++col_index) // controls cols
		{
			board_ptr->game_board[row_index][col_index].location.row = row_index; // location of Cell
			board_ptr->game_board[row_index][col_index].location.col = col_index;
			board_ptr->game_board[row_index][col_index].piece.token_color = NONE;
			board_ptr->game_board[row_index][col_index].piece.location.row = -1; // location of Token
			board_ptr->game_board[row_index][col_index].piece.location.col = -1;
		}
	}

}

void drop_piece(Board* board_ptr, int column, Color pColor) {
	int i;

	for (i = board_ptr->num_rows; i >= 0; i--) {
		if (board_ptr->game_board[i][column].piece.token_color == NONE) {
			board_ptr->game_board[i][column].piece.token_color = pColor;
			i = -1;
		}
	}
}

//returns 1 for black 2 for red 0 for none
int check_win(Board* board_ptr) {
	int i, j;
	int win = 0;

	//horizontal check
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 0; j < board_ptr->num_cols-3; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i][j + 1].piece.token_color && board_ptr->game_board[i][j + 1].piece.token_color == board_ptr->game_board[i][j + 2].piece.token_color && board_ptr->game_board[i][j + 2].piece.token_color == board_ptr->game_board[i][j + 3].piece.token_color) {
					switch (board_ptr->game_board[i][j].piece.token_color) {
					case BLACK:
						win = 1;
						break;
					case RED:
						win = 2;
						break;
					default:
						win = 0;
						break;
					}
				}
			}
			
		}
	}

	//vertical check
	for (i = 0; i < board_ptr->num_rows-3; i++) {
		for (j = 0; j < board_ptr->num_cols; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i + 1][j].piece.token_color && board_ptr->game_board[i + 1][j].piece.token_color == board_ptr->game_board[i + 2][j].piece.token_color && board_ptr->game_board[i + 2][j].piece.token_color == board_ptr->game_board[i + 3][j].piece.token_color) {
					switch (board_ptr->game_board[i][j].piece.token_color) {
					case BLACK:
						win = 1;
						break;
					case RED:
						win = 2;
						break;
					default:
						win = 0;
						break;
					}
				}
			}
		}
	}

	//diagonal right
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 0; j < board_ptr->num_cols-3; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i + 1][j + 1].piece.token_color && board_ptr->game_board[i + 1][j + 1].piece.token_color == board_ptr->game_board[i + 2][j + 2].piece.token_color && board_ptr->game_board[i + 2][j + 2].piece.token_color == board_ptr->game_board[i + 3][j + 3].piece.token_color) {
					switch (board_ptr->game_board[i][j].piece.token_color) {
					case BLACK:
						win = 1;
						break;
					case RED:
						win = 2;
						break;
					default:
						win = 0;
						break;
					}
				}
			}
		}
	}

	//diagonal left
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 3; j < board_ptr->num_cols; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i + 1][j - 1].piece.token_color && board_ptr->game_board[i + 1][j - 1].piece.token_color == board_ptr->game_board[i + 2][j - 2].piece.token_color && board_ptr->game_board[i + 2][j - 2].piece.token_color == board_ptr->game_board[i + 3][j - 3].piece.token_color) {
					switch (board_ptr->game_board[i][j].piece.token_color) {
					case BLACK:
						win = 1;
						break;
					case RED:
						win = 2;
						break;
					default:
						win = 0;
						break;
					}
				}
			}
			
		}
	}

	return win;
}

int get_move(Board* board_ptr, Color pColor, int debug_delay) {
	int i, j;
	int choice;
	int changed = 0;

	/*opponent blocking*/

	//horizontal check
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 0; j < board_ptr->num_cols - 3; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != pColor && board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i][j + 1].piece.token_color && board_ptr->game_board[i][j + 1].piece.token_color == board_ptr->game_board[i][j + 2].piece.token_color && board_ptr->game_board[i][j + 3].piece.token_color == NONE) {
					choice = j + 3;
					changed = 1;
					printf("horizontal check 2a");
					delay(debug_delay);
				}
			}
			if (board_ptr->game_board[i][j].piece.token_color == NONE) {
				if (board_ptr->game_board[i][j + 1].piece.token_color != NONE) {
					if (board_ptr->game_board[i][j + 1].piece.token_color == board_ptr->game_board[i][j + 2].piece.token_color && board_ptr->game_board[i][j + 2].piece.token_color == board_ptr->game_board[i][j + 3].piece.token_color) {
						choice = j;
						changed = 1;
						printf("horizontal check 2b");
						delay(debug_delay);
					}
				}
				
			}

		}
	}

	//vertical check
	for (i = 0; i < board_ptr->num_rows - 2; i++) {
		for (j = 0; j < board_ptr->num_cols; j++) {
			if (board_ptr->game_board[i][j].piece.token_color == NONE && board_ptr->game_board[i + 1][j].piece.token_color != NONE ) {
				if (board_ptr->game_board[i+1][j].piece.token_color == board_ptr->game_board[i + 2][j].piece.token_color && board_ptr->game_board[i + 2][j].piece.token_color == board_ptr->game_board[i + 3][j].piece.token_color) {
					choice = j;
					changed = 1;
					printf("vertical check 2");
					delay(debug_delay);
				}
			}
		}
	}

	//diagonal right
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 0; j < board_ptr->num_cols - 3; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != pColor && board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i + 1][j + 1].piece.token_color && board_ptr->game_board[i + 1][j + 1].piece.token_color == board_ptr->game_board[i + 2][j + 2].piece.token_color) {
					choice = j + 3;
					changed = 1;
					printf("diag right check 2");
					delay(debug_delay);
				}
			}
		}
	}

	//diagonal left
	for (i = 0; i < board_ptr->num_rows; i++) {
		for (j = 3; j < board_ptr->num_cols; j++) {
			if (board_ptr->game_board[i][j].piece.token_color != pColor && board_ptr->game_board[i][j].piece.token_color != NONE) {
				if (board_ptr->game_board[i][j].piece.token_color == board_ptr->game_board[i + 1][j - 1].piece.token_color && board_ptr->game_board[i + 1][j - 1].piece.token_color == board_ptr->game_board[i + 2][j - 2].piece.token_color) {
					choice = j - 3;
					changed = 1;
					printf("diag laft check 2");
					delay(debug_delay);
				}
			}

		}
	}


	if (changed == 0) {
		choice = rand() % board_ptr->num_cols;
	}

	return choice;
}

void player_turn(Board* board_ptr, Color pColor) {
	printf("\n");
	printf("Enter a column to drop your piece\n");

	int choice = -1;

	while (choice == -1) {
		scanf("%d", &choice);

		//check if in bounds
		if (choice < board_ptr->num_cols && choice >= 0) {
			//if top row is filled invalid
			if (board_ptr->game_board[0][choice].piece.token_color != NONE) {
				choice = -1;
				printf("invalid column\n");
			}
			//else drop piece
			else {
				printf("piece drop at col %d", choice);
			}
			
		}
		//else invalid
		else {
			choice = -1;
			printf("invalid column\n");
		}
	}
	drop_piece(board_ptr, choice, pColor);

	system("cls");
	print_title();
	printf("\n");
	print_board(board_ptr);
	
}

void computer_turn(Board* board_ptr, Color pColor) {
	printf("\n");
	printf("[Computer Turn]\n");

	delay(1);

	int choice = -1;

	while (choice == -1) {
		choice = get_move(board_ptr, pColor, 1);

		//check if in bounds
		if (choice < board_ptr->num_cols && choice >= 0) {
			//if top row is filled invalid
			if (board_ptr->game_board[0][choice].piece.token_color != NONE) {
				choice = rand() % board_ptr->num_cols;
				printf("invalid column\n");
			}
			//else drop piece
			else {
				printf("piece drop at col %d", choice);
			}

		}
		//else invalid
		else {
			choice = rand() % board_ptr->num_cols;
			printf("invalid column\n");
		}
	}
	drop_piece(board_ptr, choice, pColor);

	system("cls");
	print_title();
	printf("\n");
	print_board(board_ptr);

}


void menu_main() {

	int choice = 0;
	print_title();
	printf("\n");
	printf("1) Start Game\n");
	printf("2) Exit\n");

	while (choice != 2) {
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			loop_game();
			break;
		case 2:
			break;
		}
	}
}

void loop_game() {
	Board game_board;
	init_board(&game_board);

	system("cls");
	print_title();
	printf("\n");

	print_board(&game_board);

	/*choose player color*/
	printf("\n");
	printf("Choose your color:\n");
	printf("1) black\n");
	printf("2) red\n");

	Color pColor = NONE;
	Color cColor = NONE;
	int choice = 0;
	while (choice == 0) {
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			pColor = BLACK;
			cColor = RED;
			break;
		case 2:
			pColor = RED;
			cColor = BLACK;
			break;
		}
	}

	/*choose random to go first*/
	int first = rand() % 2;

	/*start turns*/
	int win = 0;
	
	if (first == 0) {
		printf("[Player goes first]");

		while (win == 0)
		{
			//human turn
			player_turn(&game_board, pColor);

			//check win
			win = check_win(&game_board);

			if (win == 0) {
				//computer turn
				computer_turn(&game_board, cColor);

				//check win
				win = check_win(&game_board);
			}
		}
	}
	else {
		printf("[Computer goes first]");

		while (win == 0)
		{
			//computer turn
			computer_turn(&game_board, cColor);

			//check win
			win = check_win(&game_board);

			if (win == 0) {
				//human turn
				player_turn(&game_board, pColor);

				//check win
				win = check_win(&game_board);
			}
		}
	}

	/*print winner*/
	system("cls");
	print_title();
	printf("\n");
	print_board(&game_board);
	printf("\n");
	switch (win) {
	case 1:
		if (pColor == BLACK) {
			printf("You WIN\n");
		}
		else {
			printf("Computer WINS\n");
		}
		break;
	case 2:
		if (pColor == RED) {
			printf("You WIN\n");
		}
		else {
			printf("Computer WINS\n");
		}
		break;
	default:
		printf("error in win condition");
		break;
	}
	
	/*Exit to main screen*/
	choice = 0;

	printf("\n");
	printf("1) Exit");
	while (choice != 1) {
		scanf("%d", &choice);
	}

	system("cls");
	print_title();
	printf("\n");
	printf("\n");
	printf("1) Start Game\n");
	printf("2) Exit\n");
	
}