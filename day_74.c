// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 100

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Step 1: Sort names
    qsort(names, n, sizeof(names[0]), cmp);

    int maxVotes = 1, count = 1;
    char winner[LEN];
    strcpy(winner, names[0]);

    // Step 2: Count frequencies
    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            // Check if this group is better
            if (count > maxVotes) {
                maxVotes = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    // Last group check
    if (count > maxVotes) {
        maxVotes = count;
        strcpy(winner, names[n - 1]);
    }

    // Output
    printf("%s %d\n", winner, maxVotes);

    return 0;
}