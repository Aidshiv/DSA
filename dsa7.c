#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char USN[10],
        name[20],
        branch[10];
    int sem;
    long int ph;
    struct node *link;
} nd;
nd *create(nd *);
void status(nd *);
nd *ins_front(nd *);
nd *ins_rear(nd *);
nd *del_front(nd *);
nd *del_rear(nd *);
void display(nd *);
int main()
{
    nd *first = NULL;
    int ch;
    for (;;)
    {
        printf("1. Create N students\n2. Status of SLL\n");
        printf("3. Insert front\n4. Insert rear\n5. Delete front\n");
        printf("6. Delete rear\n7. Display\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = create(first);
            break;
        case 2:
            status(first);
            break;
        case 3:
            first = ins_front(first);
            break;
        case 4:
            first = ins_rear(first);
            break;
        case 5:
            first = del_front(first);
            break;
        case 6:
            first = del_rear(first);
            break;
        case 7:
            display(first);
            break;
        case 8:
            exit(0);
        }
    }
}
nd *del_front(nd *f)
{
    nd *t;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return NULL;
    }
    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%d\t%ld\n", (f->USN), (f->name), (f->branch), (f->sem), (f->ph));
    t = f->link;
    free(f);
    return t;
}
nd *del_rear(nd *f)
{
    nd *t, *p;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return NULL;
    }
    for (p = NULL, t = f; t->link != NULL; p = t, t = t->link)
        ;
    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%d\t%ld\n", (t->USN), (t->name), (t->branch), (t->sem), (t->ph));
    free(t);
    if (p != NULL)
    {
        p->link = NULL;
        return f;
    }
    else
        return NULL;
}
nd *ins_rear(nd *f)
{
    nd *p = f;
    nd *t = (nd *)malloc(sizeof(nd));
    t->link = NULL;
    printf("Enter USN, Name, Branch, Sem and Phone of the student:\n");
    scanf("%s%s%s%d%ld", (t->USN), (t->name), (t->branch), &(t->sem), &(t->ph));
    if (f == NULL)
        return t;
    for (; p->link != NULL; p = p->link)
        ;
    p->link = t;
    return f;
}
void status(nd *f)
{
    int cnt = 0;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return;
    }
    for (; f != NULL; f = f->link, cnt++)
        ;
    printf("Number of nodes in SLL is %d\n", cnt);
}
nd *create(nd *f)
{
    int n, i;
    printf("Enter value for n\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        f = ins_front(f);
    return f;
}
nd *ins_front(nd *f)
{
    nd *t = (nd *)malloc(sizeof(nd));
    printf("Enter USN, Name, Branch, Sem and Phone of the student:\n");
    scanf("%s%s%s%d%ld", (t->USN), (t->name), (t->branch), &(t->sem), &(t->ph));
    t->link = f;
    return t;
}
void display(nd *f)
{
    if (f == NULL)
    {
        printf("Contents of SLL are empty\n");
        return;
    }
    printf("Contents of the list\n");
    while (f != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%ld\n", (f->USN), (f->name), (f->branch), (f->sem), (f->ph));
        f =
            f->link;
    }
}
