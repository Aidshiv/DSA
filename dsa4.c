#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
// Structure to represent a stack
struct Stack
{
    int top;
    char items[MAX_STACK_SIZE];
};
// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
// Function to push an element onto the stack
void push(struct Stack *stack, char item)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}
// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}
// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
// Function to get the precedence of an operator
int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
// Function to convert an infix expression to a postfix expression
void infixToPostfix(char *infix, char *postfix)
{
    struct Stack stack;
    initialize(&stack);
    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        char current = infix[i];
        if (isalnum(current))
        {
            postfix[j++] = current;
        }
        else if (current == '(')
        {
            push(&stack, current);
        }
        else if (current == ')')
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(')
            {
                pop(&stack); // Pop the opening parenthesis
            }
        }
        else if (isOperator(current))
        {
            while (!isEmpty(&stack) && getPrecedence(current) <=
                                           getPrecedence(stack.items[stack.top]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }
        i++;
    }
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[100];
    char postfix[100];
    printf("Enter an infix expression: ");
    scanf(" %[^\n]", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
