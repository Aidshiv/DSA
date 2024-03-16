#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee{
    char SSN[15];
    char Name[50];
    char Dept[50];
    char Designation[50];
    float Sal;
    char PhNo[15];
    struct Employee *prev;
    struct Employee *next;
};
struct Employee *createEmployee()
{
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    if (newEmployee == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter Employee Details:\n");
    printf("SSN: ");
    scanf(" %[^\n]", newEmployee->SSN);
    printf("Name: ");
    scanf(" %[^\n]", newEmployee->Name);
    printf("Department: ");
    scanf(" %[^\n]", newEmployee->Dept);
    printf("Designation: ");
    scanf(" %[^\n]", newEmployee->Designation);
    printf("Salary: ");
    scanf("%f", &newEmployee->Sal);
    printf("Phone Number: ");
    scanf(" %[^\n]", newEmployee->PhNo);
    newEmployee->prev = NULL;
    newEmployee->next = NULL;
    return newEmployee;
}
void displayEmployee(struct Employee *employee)
{
    printf("SSN: %s\n", employee->SSN);
    printf("Name: %s\n", employee->Name);
    printf("Department: %s\n", employee->Dept);
    printf("Designation: %s\n", employee->Designation);
    printf("Salary: %.2f\n", employee->Sal);
    printf("Phone Number: %s\n", employee->PhNo);
}
struct Employee *createDLL(struct Employee *head, int N)
{
    for (int i = 0; i < N; i++)
    {
        struct Employee *newEmployee = createEmployee();
        if (head == NULL)
        {
            head = newEmployee;
        }
        else
        {
            struct Employee *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newEmployee;
            newEmployee->prev = current;
        }
        printf("Employee added to the end of the list.\n");
    }
    return head;
}
void displayDLL(struct Employee *head)
{
    struct Employee *current = head;
    int count = 0;
    if (current == NULL)
    {
        printf("Doubly Linked List is empty.\n");
    }
    else
    {
        printf("Doubly Linked List Contents:\n");
        while (current != NULL)
        {
            displayEmployee(current);
            current = current->next;
            count++;
        }
        printf("Total number of nodes: %d\n", count);
    }
}
struct Employee *insertEnd(struct Employee *head)
{
    struct Employee *newEmployee = createEmployee();
    if (head == NULL)
    {
        head = newEmployee;
    }
    else
    {
        struct Employee *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newEmployee;
        newEmployee->prev = current;
    }
    printf("Employee added to the end of the list.\n");
    return head;
}
struct Employee *deleteFront(struct Employee *head)
{
    if (head == NULL)
    {
        printf("Doubly Linked List is empty. Nothing to delete.\n");
    }
    else
    {
        struct Employee *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        printf("Employee deleted from the front of the list.\n");
    }
    return head;
}
struct Employee *enqueueFront(struct Employee *head)
{
    head = insertEnd(head);
    return head;
}

struct Employee *dequeueEnd(struct Employee *head)
{
    head = deleteFront(head);
    return head;
}
int main()
{
    struct Employee *head = NULL;
    int choice, N;
    while (1)
    {
        printf("\nDoubly Linked List Operations Menu :\n");
        printf("1. Create DLL of N Employees Data by End Insertion\n");
        printf("2. Display DLL and Count Nodes\n");
        printf("3. Insert Employee at End\n");
        printf("4. Delete Employee from Front\n");
        printf("5. Demonstrate DLL as Double - Ended Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("% d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of employees(N) : ");
            scanf("% d", &N);
            head = createDLL(head, N);
            break;
        case 2:
            displayDLL(head);
            break;
        case 3:
            head = insertEnd(head);
            break;
        case 4:
            head = deleteFront(head);
            break;
        case 5:
            printf("Demonstrating DLL as a Double - Ended Queue :\n");
            printf("1. Enqueue at Front\n");
            printf("2. Dequeue at End\n");
            printf("3. Exit\n");
            printf("Enter your choice : ");
            scanf("% d", &choice);
            switch (choice)
            {
            case 1:
                head = enqueueFront(head);
                break;
            case 2:
                head = dequeueEnd(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice.Please select a valid option.\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.Please select a valid option.\n");
        }
    }
    return 0;
}
