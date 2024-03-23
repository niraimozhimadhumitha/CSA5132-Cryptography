#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptSimpleSubstitutionCipher(char ciphertext[], int length) {
    int frequency[256] = {0};

    for (int i = 0; i < length; i++) {
        frequency[(int)ciphertext[i]]++;
    }
    int maxFreqIndex = 0;
    for (int i = 1; i < 256; i++) {
        if (isalnum(i) && frequency[i] > frequency[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }
    int key = maxFreqIndex - 'e';
    for (int i = 0; i < length; i++) {
        if (isalnum(ciphertext[i])) {
            char decryptedChar = ciphertext[i] - key;
            if (decryptedChar < 'A') {
                decryptedChar += 26; 
            }
            printf("%c", decryptedChar);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    int length = strlen(ciphertext);

    decryptSimpleSubstitutionCipher(ciphertext, length);

    return 0;
}

