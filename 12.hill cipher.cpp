#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key[2][2] = {{9, 4}, {5, 7}};

void inverseKey(int inverse[2][2]) {
    int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    int invDet = 0;

    for (int i = 1; i < 26; ++i) {
        if ((det * i) % 26 == 1) {
            invDet = i;
            break;
        }
    }

    inverse[0][0] = (key[1][1] * invDet) % 26;
    inverse[0][1] = (-key[0][1] * invDet) % 26;
    inverse[1][0] = (-key[1][0] * invDet) % 26;
    inverse[1][1] = (key[0][0] * invDet) % 26;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (inverse[i][j] < 0) {
                inverse[i][j] += 26;
            }
        }
    }
}

void encryptDigraph(int digraph[2]) {
    int result[2] = {0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i] += key[i][j] * digraph[j];
        }
        result[i] %= 26;
    }
    printf("%c%c", result[0] + 'a', result[1] + 'a');
}

void decryptDigraph(int digraph[2]) {
    int inverse[2][2];
    inverseKey(inverse);

    int result[2] = {0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i] += inverse[i][j] * digraph[j];
        }
        result[i] %= 26;
    }
    printf("%c%c", result[0] + 'a', result[1] + 'a');
}

int main() {
    char message[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int len = strlen(message);
    int digraph[2];

    printf("Encrypted message: ");
    for (int i = 0; i < len; i += 2) {
        digraph[0] = message[i] - 'a';
        digraph[1] = message[i + 1] - 'a';
        encryptDigraph(digraph);
    }

    printf("\nDecrypted message: ");
    for (int i = 0; i < len; i += 2) {
        digraph[0] = message[i] - 'a';
        digraph[1] = message[i + 1] - 'a';
        decryptDigraph(digraph);
    }
    printf("\n");

    return 0;
}

