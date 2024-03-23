#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticCipher(char *text, char *key) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalpha(ch)) {
            if (islower(ch)) {
                text[i] = tolower(key[ch - 'a']);
            } else if (isupper(ch)) {
                text[i] = toupper(key[ch - 'A']);
            }
        }
    }
}

int main() {
    char text[100], key[26];
    int i;

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (ciphertext alphabet): ");
    fgets(key, sizeof(key), stdin);
    for (i = 0; i < 26; ++i) {
        if (isalpha(key[i])) {
            key[i] = toupper(key[i]);
        } else {
            printf("Error: Key should be 26 alphabetical characters.\n");
            return 1;
        }
    }

    monoalphabeticCipher(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}

