#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char *text, int shift) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = 'a' + (ch - 'a' + shift) % 26;
            } else if (isupper(ch)) {
                ch = 'A' + (ch - 'A' + shift) % 26;
            }
        }
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int shift, i;

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);

    shift %= 26;

    caesarCipher(text, shift);

    printf("Encrypted text: %s\n", text);

    return 0;
}

