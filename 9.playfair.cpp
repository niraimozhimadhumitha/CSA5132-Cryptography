#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5 
void removeSpacesAndDuplicates(char *key) {
    int index = 0;
    for (int i = 0; key[i]; i++) {
        if (key[i] != ' ' && strchr(key, key[i]) == &key[i]) {
            key[index++] = key[i];
        }
    }
    key[index] = '\0';
}

void generateMatrix(char key[], char matrix[SIZE][SIZE]) {
    removeSpacesAndDuplicates(key);

    int keyLen = strlen(key);
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < keyLen) {
                matrix[i][j] = key[index++];
            } else {
                matrix[i][j] = 'A' + (index++ - keyLen);
            }
        }
    }
}

void findCharPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Replace 'J' with 'I'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decryptPlayfair(char matrix[SIZE][SIZE], char message[]) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        char ch1 = message[i];
        char ch2 = message[i + 1];
        int row1, col1, row2, col2;
        findCharPosition(matrix, ch1, &row1, &col1);
        findCharPosition(matrix, ch2, &row2, &col2);
        if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 - 1 + SIZE) % SIZE], matrix[row2][(col2 - 1 + SIZE) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 - 1 + SIZE) % SIZE][col1], matrix[(row2 - 1 + SIZE) % SIZE][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
}

int main() {
    char key[] = "PT109"; 
    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    char matrix[SIZE][SIZE];
    generateMatrix(key, matrix);

    printf("Decrypted message: ");
    decryptPlayfair(matrix, message);
    printf("\n");

    return 0;
}

