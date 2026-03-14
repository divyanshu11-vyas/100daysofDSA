// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10
#include <stdio.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = 0, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue elements to stack
    for (int i = 0; i < N; i++) {
        push(dequeue());
    }

    // Move stack elements back to queue
    for (int i = 0; i < N; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}