#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
void createMatrix(char matrix[SIZE][SIZE], const char *key) {
    char keySquare[26] = {0};
    int i, j, k;
    int keyLen = strlen(key);
    char *ptr;
    for (i = 0; i < keyLen; ++i) {
  
key[i] = toupper((unsigned char)key[i]);

        if (key[i] == 'J')
            key[i] = 'I';
        ptr = strchr(keySquare, key[i]);
        if (ptr == NULL) {
            strcat(keySquare, key + i);
        }
    }
    for (i = 0, k = 0; i < 26; ++i) {
        ptr = strchr(keySquare, 'A' + i);
        if (ptr == NULL) {
            keySquare[k++] = 'A' + i;
        }
    }

    k = 0;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            matrix[i][j] = keySquare[k++];
        }
    }
}

void findPositions(const char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(const char *plaintext, char matrix[SIZE][SIZE]) {
    int len = strlen(plaintext);
    int i, row1, col1, row2, col2;
    char ch1, ch2;

    printf("Plaintext: %s\n", plaintext);
    for (i = 0; i < len; i += 2) {
        ch1 = plaintext[i];
        ch2 = plaintext[i + 1];
        if (ch1 == ch2) {
            ch2 = 'X';
            ++i;
        }
        findPositions(matrix, ch1, &row1, &col1);
        findPositions(matrix, ch2, &row2, &col2);
        if (row1 == row2) {
            printf("%c%c ", matrix[row1][(col1 + 1) % SIZE], matrix[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2)
            printf("%c%c ", matrix[(row1 + 1) % SIZE][col1], matrix[(row2 + 1) % SIZE][col2]);
        } else {
            printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char key[100], plaintext[100];
    char matrix[SIZE][SIZE];
    printf("Enter the keyword: ");
    scanf("%s", key);

    createMatrix(matrix, key);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    playfairEncrypt(plaintext, matrix);

    return 0;
}

