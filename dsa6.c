#include <stdio.h>
#include <stdlib.h>
#define Max 3
void insert(char[], int *, int *);
void del(char[], int *, int *);
void display(char[], int, int);
int main()
{
    char q[Max];
    int r = -1, f = 0, cnt = 0;
    int ch;
    while (1)
    {
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(q, &r, &cnt);
            break;
        case 2:
            del(q, &f, &cnt);
            break;
        case 3:
            display(q, f, cnt);
            break;
        default:
            exit(0);
        }
    }
}
void insert(char q[], int *r, int *cnt)
{
    char ele;
    if ((*cnt) == Max)
    {
        printf("C Q overflow\n");
        return;
    }
    (*r) = ((*r) + 1) % Max;
    printf("enter the ele\n");
    scanf(" %c", &ele);
    q[*r] = ele;
    (*cnt)++;
}
void del(char q[], int *f, int *cnt)
{
    if ((*cnt) == 0)
    {
        printf("C Queue is empty\n");
        return;
    }
    printf("Element deleted from circular queue is %c\n", q[(*f)]);
    (*f) = ((*f) + 1) % Max;
    (*cnt)--;
}

// output 
// 1: Insert 
// 2: Delete
// 3: Display 
// 4: Exit Enter choice
// 1
// enter the ele
// 9
// 1: Insert
// 2: Delete
// 3: Display
// 4: Exit
// Enter choice
// 1
// enter the ele
// 8
// 1: Insert
// 2: Delete
// 3: Display
// 4: Exit
// Enter choice
// 3
// Circular Queue content
// 09
    
void display(char q[], int f, int cnt)
{
    int i, j;
    if (cnt == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue contents are\n");
    for (i = f, j = 0; j < cnt; j++)
    {
        printf("%d : %c\n", i, q[i]);
        i = (i + 1) % Max;
    }
}
