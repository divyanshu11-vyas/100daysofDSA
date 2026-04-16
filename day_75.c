// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    int hash[20001];
    for (int i = 0; i < 20001; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = 10000; // To handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is zero
        if (sum == 0) {
            max_length = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + offset] != -2) {
            int prev_index = hash[sum + offset];
            if (i - prev_index > max_length)
                max_length = i - prev_index;
        } else {
            // Store first occurrence
            hash[sum + offset] = i;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
