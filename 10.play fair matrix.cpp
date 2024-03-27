#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyMatrix[5][5] = {
    {'M', 'F', 'H', 'I', 'J'},
    {'K', 'U', 'N', 'O', 'P'},
    {'Q', 'Z', 'V', 'W', 'X'},
    {'Y', 'E', 'L', 'A', 'R'},
    {'G', 'D', 'S', 'T', 'B'}
};

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; 
    for (*row = 0; *row < 5; (*row)++) {
        for (*col = 0; *col < 5; (*col)++) {
            if (keyMatrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

void encrypt(char *message) {
    int i, row1, row2, col1, col2;
    char ch1, ch2;
    for (i = 0; i < strlen(message); i += 2) {
        ch1 = toupper(message[i]);
        ch2 = toupper(message[i + 1]);
        if (ch1 == 'J') ch1 = 'I'; 
        if (ch2 == 'J') ch2 = 'I'; 

        findPosition(ch1, &row1, &col1);
        findPosition(ch2, &row2, &col2);

        if (row1 == row2) {
            message[i] = keyMatrix[row1][(col1 + 1) % 5];
            message[i + 1] = keyMatrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            message[i] = keyMatrix[(row1 + 1) % 5][col1];
            message[i + 1] = keyMatrix[(row2 + 1) % 5][col2];
        } else {
            message[i] = keyMatrix[row1][col2];
            message[i + 1] = keyMatrix[row2][col1];
        }
    }
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";

    encrypt(message);
    printf("Encrypted message: %s\n", message);

    return 0;
}

