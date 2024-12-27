#include <stdio.h>

char board[3][3]; // 3x3 board for Tic-Tac-Toe
char currentPlayer; // Current player ('X' or 'O')

// Function prototypes
void initializeBoard();
void printBoard();
int checkWin();
int isBoardFull();
void playerMove();
void switchPlayer();

int main() {
    int gameStatus = 0; // 0 - game ongoing, 1 - player X wins, 2 - player O wins, 3 - draw
    currentPlayer = 'X'; // Player X starts the game
    
    initializeBoard();

    while (gameStatus == 0) {
        printBoard();
        playerMove();
        gameStatus = checkWin();
        if (gameStatus == 0 && isBoardFull()) {
            gameStatus = 3; // Draw if the board is full and no winner
        }
        switchPlayer();
    }

    printBoard();
    if (gameStatus == 1) {
        printf("Player X wins!\n");
    } else if (gameStatus == 2) {
        printf("Player O wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

// Function to initialize the board with empty spaces
void initializeBoard() 
    {
    int i ;	
	for ( i = 0; i < 3; i++)
	{
		int j ;
        for ( j = 0; j < 3; j++) {
            board[i][j] = ' '; // Empty space
        }
    }
}

// Function to print the Tic-Tac-Toe board
void printBoard() {
    printf("\nTic-Tac-Toe Board:\n");
    int i;
    for ( i = 0; i < 3; i++) {
    	int j ;
        for ( j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin() {
    // Check rows, columns, and diagonals
    int i;
    for ( i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // No winner yet
}

// Function to check if the board is full (draw condition)
int isBoardFull() {
	int i;
    for (i = 0; i < 3; i++) {
    	int j;
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Empty space found
            }
        }
    }
    return 1; // No empty spaces, board is full
}

// Function to take the player's move
void playerMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter row (0-2) and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break; // Valid move, exit the loop
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

// Function to switch players between X and O
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

