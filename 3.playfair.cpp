#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MATRIX_SIZE 5
char matrix[MATRIX_SIZE][MATRIX_SIZE];
void generateMatrix(char *key);
void encrypt(char *plaintext, char *key);
void prepareInput(char *input);
void getPosition(char letter, int *row, int *col);
void fixPair(char *pair);
void decrypt(char *ciphertext, char *key);
int main() {
    char key[100], plaintext[100], ciphertext[100];
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    generateMatrix(key);
    printf("Matrix Generated:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    encrypt(plaintext, key);
    printf("Encrypted Text: %s\n", plaintext);
    decrypt(plaintext, key);
    printf("Decrypted Text: %s\n", plaintext);
    return 0;
}
void generateMatrix(char *key) {
    char *ptr = key;
    int i, j;
    char alphabet[] = "abcdefghiklmnopqrstuvwxyz";
    int keylen = strlen(key);
    int alphalen = strlen(alphabet);
    for (int i = 0; i < keylen; i++) {
        if (*(ptr + i) == 'j') {
            for (int j = i; j < keylen; j++) {
                *(ptr + j) = *(ptr + j + 1);
            }
            break;
        }
    }

    int ptrlen = strlen(ptr);

    for (i = 0; i < ptrlen; i++) {
        matrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = *(ptr + i);
    }

    for (j = 0; i < MATRIX_SIZE * MATRIX_SIZE; j++) {
        int found = 0;
        for (int k = 0; k < ptrlen; k++) {
            if (alphabet[j] == *(ptr + k)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            matrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = alphabet[j];
            i++;
        }
    }
}

void encrypt(char *plaintext, char *key) {
    prepareInput(plaintext);
    char *ptr = plaintext;
    while (*ptr != '\0') {
        if (*ptr == *(ptr + 1)) {
            *(ptr + 1) = 'x';
        }
        ptr += 2;
    }
    ptr = plaintext;
    while (*ptr != '\0') {
        if (*(ptr + 1) == '\0') {
            *(ptr + 1) = 'x';
            *(ptr + 2) = '\0';
            break;
        }
        int row1, row2, col1, col2;
        getPosition(*ptr, &row1, &col1);
        getPosition(*(ptr + 1), &row2, &col2);
        if (row1 == row2) {
            *(ptr) = matrix[row1][(col1 + 1) % MATRIX_SIZE];
            *(ptr + 1) = matrix[row2][(col2 + 1) % MATRIX_SIZE];
        } else if (col1 == col2) {
            *(ptr) = matrix[(row1 + 1) % MATRIX_SIZE][col1];
            *(ptr + 1) = matrix[(row2 + 1) % MATRIX_SIZE][col2];
        } else {
            *(ptr) = matrix[row1][col2];
            *(ptr + 1) = matrix[row2][col1];
        }
        ptr += 2;
    }
}

void prepareInput(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalpha(input[i])) {
            for (int j = i; input[j] != '\0'; j++) {
                input[j] = input[j + 1];
            }
        }
        input[i] = tolower(input[i]);
    }
}

void getPosition(char letter, int *row, int *col) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void fixPair(char *pair) {
    if (pair[1] == 'x') {
        pair[1] = '\0';
    }
}

void decrypt(char *ciphertext, char *key) {
    char *ptr = ciphertext;
    while (*ptr != '\0') {
        int row1, row2, col1, col2;
        getPosition(*ptr, &row1, &col1);
        getPosition(*(ptr + 1), &row2, &col2);
        if (row1 == row2) {
            *(ptr) = matrix[row1][(col1 - 1 + MATRIX_SIZE) % MATRIX_SIZE];
            *(ptr + 1) = matrix[row2][(col2 - 1 + MATRIX_SIZE) % MATRIX_SIZE];
        } else if (col1 == col2) {
            *(ptr) = matrix[(row1 - 1 + MATRIX_SIZE) % MATRIX_SIZE][col1];
            *(ptr + 1) = matrix[(row2 - 1 + MATRIX_SIZE) % MATRIX_SIZE][col2];
        } else {
            *(ptr) = matrix[row1][col2];
            *(ptr + 1) = matrix[row2][col1];
        }
        ptr += 2;
    }
    fixPair(ciphertext);
}
