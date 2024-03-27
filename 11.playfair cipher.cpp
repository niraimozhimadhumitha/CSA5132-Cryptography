#include <stdio.h>
#include <string.h>
int countUniqueLetters(char keyword[]) {
    int freq[26] = {0};
    int len = strlen(keyword);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (keyword[i] >= 'A' && keyword[i] <= 'Z') {
            if (freq[keyword[i] - 'A'] == 0) {
                freq[keyword[i] - 'A'] = 1;
                count++;
            }
        }
    }

    return count;
}

int countRepeatingLetters(char keyword[]) {
    int freq[26] = {0};
    int len = strlen(keyword);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (keyword[i] >= 'A' && keyword[i] <= 'Z') {
            if (freq[keyword[i] - 'A'] == 1) {
                count++;
            }
            freq[keyword[i] - 'A'] = 1;
        }
    }

    return count;
}
int countIJPairs(char keyword[]) {
    int len = strlen(keyword);
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        if ((keyword[i] == 'I' || keyword[i] == 'J') && (keyword[i + 1] == 'I' || keyword[i + 1] == 'J')) {
            count++;
        }
    }

    return count;
}

long long calculateTotalKeys(char keyword[]) {
    int uniqueLetters = countUniqueLetters(keyword);
    int repeatingLetters = countRepeatingLetters(keyword);
    int IJPairs = countIJPairs(keyword);

    long long totalKeys = 1;
    for (int i = 25; i > 25 - uniqueLetters; i--) {
        totalKeys *= i;
    }
    totalKeys /= repeatingLetters;
    totalKeys /= IJPairs + 1;

    return totalKeys;
}

int main() {
    char keyword[100];
    printf("Enter the keyword: ");
    scanf("%s", keyword);

    long long totalKeys = calculateTotalKeys(keyword);
    printf("Total number of effectively unique keys: %lld\n", totalKeys);

    return 0;
}

