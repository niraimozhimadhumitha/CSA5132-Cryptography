#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptMonoalphabeticCipher(char plaintext[], char keyword[]) {
    char cipherSequence[27];
    sprintf(cipherSequence, "%sABCDEFGHIJKLMNOPQRSTUVWXYZ", keyword);
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            int index = toupper(plaintext[i]) - 'A';
            plaintext[i] = islower(plaintext[i]) ? tolower(cipherSequence[index]) : cipherSequence[index];
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[100];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    encryptMonoalphabeticCipher(plaintext, keyword);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

