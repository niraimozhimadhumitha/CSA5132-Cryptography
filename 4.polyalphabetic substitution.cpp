#include <stdio.h>
#include <string.h>
#include <ctype.h>

void polyalphabeticCipher(char plaintext[], char key[]) {
    int i, j;
    int keyLength = strlen(key);

    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            int shift = tolower(key[i % keyLength]) - 'a';

            if (isupper(plaintext[i])) {
                plaintext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
            } else {
                plaintext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
            }
        }
    }
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    polyalphabeticCipher(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

