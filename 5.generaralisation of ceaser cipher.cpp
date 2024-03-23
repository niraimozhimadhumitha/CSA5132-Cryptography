#include <stdio.h>
#include <ctype.h>
#include <string.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int modularInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

void affineCaesarCipher(char plaintext[], int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            int shift = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = (a * (plaintext[i] - shift) + b) % 26 + shift;
        }
    }
}

int main() {
    char plaintext[100];
    int a, b;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter value of a (must be coprime with 26): ");
    scanf("%d", &a);

    if (gcd(a, 26) != 1) {
        printf("Invalid value of a. It should be coprime with 26.\n");
        return 1;
    }

    printf("Enter value of b: ");
    scanf("%d", &b);

    affineCaesarCipher(plaintext, a, b);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

