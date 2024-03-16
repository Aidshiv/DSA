#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
// Structure to represent a stack
struct Stack
{
    int top;
    int items[MAX_STACK_SIZE];
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
void push(struct Stack *stack, int item)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}
// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}
// Function to evaluate a postfix expression
int evaluatePostfix(char *expression)
{
    struct Stack stack;
    initialize(&stack);
    int len = strlen(expression);
    for (int i = 0; i < len; i++)
    {
        char current = expression[i];
        if (isdigit(current))
        {
            push(&stack, current - '0');
        }
        else
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;
            switch (current)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < operand2; j++)
                {
                    result *= operand1;
                }
                break;
            default:
                printf("Invalid operator in expression.\n");
                exit(1);
            }
            push(&stack, result);
        }
    }
    if (stack.top == 0)
    {
        return stack.items[0];
    }
    else
    {
        printf("Invalid expression.\n");
        exit(1);
    }
}
int main()
{
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf(" %[^\n]", expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}

//***************5b*****************************

#include <stdio.h>
void hanoi(int n, char S, char T, char D)
{
    if (n == 0)
        return;
    hanoi(n - 1, S, D, T);
    printf("Move disc %d from %c to %c\n", n, S, D);
    hanoi(n - 1, T, S, D);
}
int main()
{
    int n;
    printf("Enter number of discs\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}
