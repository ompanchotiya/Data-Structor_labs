#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Info;
    struct node *lptr;
    struct node *rptr;
};

struct node *First = NULL;

void insertlast()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Info: ");
    scanf("%d", &newnode->Info);

    newnode->rptr = NULL;

    if (First == NULL)
    {
        newnode->lptr = NULL;
        First = newnode;
        return;
    }

    temp = First;

    while (temp->rptr != NULL)
        temp = temp->rptr;

    temp->rptr = newnode;
    newnode->lptr = temp;
}

void display()
{
    struct node *temp;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = First;

    while (temp != NULL)
    {
        printf("%d", temp->Info);
        temp = temp->rptr;
    }

    printf("NULL\n");
}

void deleteAlternate()
{
    struct node *save, *prev;

    prev = First;

    while (prev != NULL && prev->rptr != NULL)
    {
        save = prev->rptr;

        prev->rptr = save->rptr;

        if (save->rptr != NULL)
            save->rptr->lptr = prev;

        free(save);

        prev = prev->rptr;
    }
}

void main()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        insertlast();
    }

    
    display();

    deleteAlternate();

    display();
}