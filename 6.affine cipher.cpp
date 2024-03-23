#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void decryptAffineCipher(int a, int b, char ciphertext[], int length) {
    int inverse = -1;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            inverse = i;
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int index = (inverse * (ciphertext[i] - 'A' - b + 26)) % 26;
            if (index < 0)
                index += 26;
            printf("%c", 'A' + index);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    char ciphertext[] = "BUVWXY";
    int length = sizeof(ciphertext) / sizeof(ciphertext[0]) - 1;

    int frequency[26] = {0};
    for (int i = 0; i < length; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            frequency[ciphertext[i] - 'A']++;
        }
    }

    int maxFreqIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (frequency[i] > frequency[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }

    int a = maxFreqIndex - ('B' - 'A');
    if (a < 0)
        a += 26;

    int b = 0;
    decryptAffineCipher(a, b, ciphertext, length);

    return 0;
}

