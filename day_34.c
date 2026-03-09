#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[])
{
    int i = 0;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i])) // operand
        {
            push(exp[i] - '0');
        }
        else if (exp[i] == ' ')
        {
            // skip spaces
        }
        else // operator
        {
            int op2 = pop();
            int op1 = pop();

            switch (exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}