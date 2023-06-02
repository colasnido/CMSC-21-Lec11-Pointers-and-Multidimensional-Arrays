#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void scan_word(int *occurrences) {
    char c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            *(occurrences + (toupper(c) - 'A')) += 1;  // Increment the occurrence count of the letter
        }
    }
}

bool is_anagram(int *occurrences1, int *occurrences2) {
    for (int i = 0; i < 26; i++) {
        if (*(occurrences1 + i) != *(occurrences2 + i)) {
            return false;  // If any occurrence counts differ in the comparison, the words are not anagrams
        }
    }
    return true;  // All occurrence counts in comparison are the same, indicating anagrams
}

int main(void) {
    int occurrences1[26] = {0};  // Array to store the letter occurrences for word1
    int occurrences2[26] = {0};  // Array to store the letter occurrences for word2

    printf("Enter first word: ");
    scan_word(occurrences1);  // Scan the first word and update the occurrences array

    printf("Enter second word: ");
    scan_word(occurrences2);  // Scan the second word and update the occurrences array

    bool result = is_anagram(occurrences1, occurrences2);  // Check if the words are anagrams True/False

    if (result) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}
