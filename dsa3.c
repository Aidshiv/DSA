#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Define a stack data structure
struct Stack
{
    int data[MAX];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    }
    else
    {
        stack->data[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1; // Return a sentinel value to indicate underflow
    }
    else
    {
        return stack->data[stack->top--];
    }
}

// Function to check if a string is a palindrome using a stack
bool isPalindrome(const char *str)
{
    struct Stack stack;
    initialize(&stack);
    int i = 0;
    while (str[i] != '\0')
    {
        push(&stack, str[i]);
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != pop(&stack))
        {
            return false;
        }
        i++;
    }
    return true;
}

// Function to display the stack's status
void displayStack(const struct Stack *stack)
{
    printf("Stack Contents:\n");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d\n", stack->data[i]);
    }
}

int main()
{
    struct Stack stack;
    initialize(&stack);
    int choice, element;
    char str[MAX];
    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter an element to push onto the stack: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1)
                {
                    printf("Popped %d from the stack.\n", element);
                }
                break;
            case 3:
                printf("Enter a string to check if it's a palindrome: ");
                scanf(" %[^\n]", str);
                if (isPalindrome(str))
                {
                    printf("The string is a palindrome.\n");
                }
                else
                {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 4:
                displayStack(&stack);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
