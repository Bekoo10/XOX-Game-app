#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

char players[2][20] = {"Player 1", "Player 2"};

int currentPlayer = 0;

int checkGameEnd() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'X' && board[i][2] == 'X' && board[i][1] == 'O') {
            return 1;  // Row check
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == 'X' && board[2][i] == 'X' && board[1][i] == 'O') {
            return 1;  // Column check
        }
    }

    if (board[0][0] == 'X' && board[1][1] == 'O' && board[2][2] == 'X') {
        return 1;  // Diagonal from left to right
    }

    if (board[0][2] == 'X' && board[1][1] == 'O' && board[2][0] == 'X') {
        return 1;  // Diagonal from right to left
    }

    // Check for a tie
    int tieCheck = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                tieCheck = 0;  // Empty cell found, the game continues
                break;
            }
        }
        if (!tieCheck) {
            break;
        }
    }
    if (tieCheck) {
        return 2;  // All cells are filled, the game is a tie
    }

    // No winner yet, the game continues
    return 0;
}

void printBoard() {
    printf("\n\tColumn 0\tColumn 1\tColumn 2\n");
    for (int i = 0; i < 3; i++) {
        printf("Row %d:   ", i);

        for (int j = 0; j < 3; j++) {
            printf("%c\t\t", board[i][j]);
        }
        printf("\n\n");
    }
}

int move() {

    char letterChoice;
    int row;
    int column;
    bool letterValid = false;
    bool moveValid = false;

    while (letterValid == false) {
        printBoard();
        printf("\n%s's turn, please select the letter you want to place (X or O): ", players[currentPlayer]);
        scanf("%s", &letterChoice);

        if (letterChoice == 'X' || letterChoice == 'O') {
            letterValid = true;
        } else if (letterChoice == 'x' || letterChoice == 'o') {
            printf("\nYou used a lowercase letter, please use uppercase.\n");
        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }

    while (moveValid == false) {
        printf("\nPlease enter the row number: ");
        scanf("%d", &row);
        printf("\nPlease enter the column number: ");
        scanf("%d", &column);

        if (row >= 0 && row < 3 && column >= 0 && column < 3 && board[row][column] == ' ') {
            board[row][column] = letterChoice;
            moveValid = true;

            currentPlayer = (currentPlayer + 1) % 2;

        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }
}

int main() {

    while (!checkGameEnd()) {
        system("cls");
        printf("\tWelcome to the Tic-Tac-Toe Game!\n");
        printf("----------------------------------------------\n");
        move();
    }

    system("cls");
    printf("\tWelcome to the Tic-Tac-Toe Game!\n");
    printf("----------------------------------------------\n");
    printBoard();

    if (checkGameEnd() == 2) {
        printf("The game ended in a tie.\n");
    } else {
        printf("Game over! %s won!\n", players[(currentPlayer + 1) % 2]);
    }

    return 0;
}
