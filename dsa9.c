#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct node
{
    int cf, px, py, pz;
    int flag;
    struct node *link;
};
typedef struct node NODE;
NODE *getnode()
{
    NODE *x;
    x = (NODE *)malloc(sizeof(NODE));
    if (x == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    return x;
}
void display(NODE *head)
{
    NODE *temp;
    if (head->link == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }
    temp = head->link;
    printf("\n");
    while (temp != head)
    {
        printf("%d x^%d y^%d z^%d", temp->cf, temp->px, temp->py, temp->pz);
        if (temp->link != head)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}
NODE *insert_rear(int cf, int x, int y, int z, NODE *head)
{
    NODE *temp, *cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    temp->flag = 0;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}
NODE *read_poly(NODE *head)
{
    int px, py, pz, cf;
    int ch;
    printf("\nEnter coeff: ");
    scanf("%d", &cf);
    printf("\nEnter x, y, z powers(0-indiacate NO term): ");
    scanf("%d%d%d", &px, &py, &pz);
    head = insert_rear(cf, px, py, pz, head);
    printf("\nIf you wish to continue press 1 otherwise 0: ");
    scanf("%d", &ch);
    while (ch != 0)
    {
        printf("\nEnter coeff: ");
        scanf("%d", &cf);
        printf("\nEnter x, y, z powers(0-indiacate NO term): ");
        scanf("%d%d%d", &px, &py, &pz);
        head = insert_rear(cf, px, py, pz, head);
        printf("\nIf you wish to continue press 1 otherwise 0: ");
        scanf("%d", &ch);
    }
    return head;
}
NODE *add_poly(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *p1, *p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    p1 = h1->link;
    while (p1 != h1)
    {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->link;
        while (p2 != h2)
        {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            p2 = p2->link;
        }
        if (p2 != h2)
        {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0)
                h3 = insert_rear(cf, x1, y1, z1, h3);
        }
        else
            h3 = insert_rear(cf1, x1, y1, z1, h3);
        p1 = p1->link;
    }
    p2 = h2->link;
    while (p2 != h2)
    {
        if (p2->flag == 0)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }
    return h3;
}
void evaluate(NODE *he)
{
    NODE *head;
    int x, y, z;
    float result = 0.0;
    head = he;
    printf("\nEnter x, y, z, terms to evaluate:\n");
    scanf("%d%d%d", &x, &y, &z);
    he = he->link;
    while (he != head)
    {
        result = result + (he->cf * pow(x, he->px) * pow(y, he->py) * pow(z, he->pz));
        he = he->link;
    }

// output  
// 1. Evaluate
// 2. Polynomial addition 3. Exit
// Choice: 1
// Enter number of terms
// 2
// Enter coef, xexp, yexp and zexp of the term
// 6
// 2
// 2
// 1
// Enter coef, xexp, yexp and zexp of the term
// -4
// Θ
// 1
// 5
// Terms in polynomial are...
// (-4x^0y^1z^5) +(6x^2y^2z^1) + Enter value of x, y and z
// 1
// 2
// 3
// Evaluation of polynomial is -1872
// 1. Evaluate
// 2. Polynomial addition
// 3. Exit
    
    printf("\nPolynomial result is: %f", result);
}
void main()
{
    NODE *h1, *h2, *h3, *he;
    int ch;
    while (1)
    {
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            he = getnode();
            he->link = he;
            printf("\nEnter polynomial to evaluate:\n");
            he = read_poly(he);
            display(he);
            evaluate(he);
            free(he);
            break;
        case 2:
            h1 = getnode();
            h2 = getnode();
            h3 = getnode();
            h1->link = h1;
            h2->link = h2;
            h3->link = h3;
            printf("\nEnter the first polynomial:");
            h1 = read_poly(h1);
            printf("\nEnter the second polynomial:");
            h2 = read_poly(h2);
            h3 = add_poly(h1, h2, h3);
            printf("\nFirst polynomial is: ");
            display(h1);
            printf("\nSecond polynomial is: ");
            display(h2);
            printf("\nThe sum of 2 polynomials is: ");
            display(h3);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid entry");
            break;
        }
    }
}
