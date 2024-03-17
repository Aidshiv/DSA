#include <stdio.h>
#include <stdlib.h>
#define MAX_MEMORY_LOCATIONS 100
#define MAX_KEYS 100
struct EmployeeRecord
{
    int key;
};
struct MemoryLocation
{
    int key;
    struct EmployeeRecord employee;
};
void initializeHashTable(struct MemoryLocation hashTable[], int m)
{
    for (int i = 0; i < m; i++)
    {
        hashTable[i].key = -1;
    }
}
void insertEmployee(struct MemoryLocation hashTable[], int m, struct EmployeeRecord employee)
{
    int key = employee.key;
    int index = key % m;
    while (hashTable[index].key != -1)
    {
        index = (index + 1) % m;
    }
    hashTable[index].key = key;
    hashTable[index].employee = employee;
}
void displayHashTable(struct MemoryLocation hashTable[], int m)
{
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i].key != -1)
        {
            printf("Location %d: Key: %d\n", i, hashTable[i].key);
        }
    }
}

// output 

// Enter the number of memory locations (m) in the hash table: 3
// Enter the number of employee records (n): 2
// Enter the 2 employee records (each record includes a 4-digit key):
// 2345
// 3456
// Hash Table Contents:
// Location 1: Key: 3456
// Location 2: Key: 2345

int main()
{
    int m;
    int n;
    struct EmployeeRecord employeeRecords[MAX_KEYS];
    struct MemoryLocation hashTable[MAX_MEMORY_LOCATIONS];
    printf("Enter the number of memory locations (m) in the hash table: ");
    scanf("%d", &m);
    printf("Enter the number of employee records (n): ");
    scanf("%d", &n);
    if (m <= 0 || n <= 0)
    {
        printf("Invalid input. Please enter valid values for m and n.\n");
        return 1;
    }
    initializeHashTable(hashTable, m);
    printf("Enter the %d employee records (each record includes a 4-digit key):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &employeeRecords[i].key);
        insertEmployee(hashTable, m, employeeRecords[i]);
    }
    displayHashTable(hashTable, m);
    return 0;
}
