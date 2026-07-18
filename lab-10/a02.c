#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;

void insert()
{
    struct Node *new, *temp;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    new->link = NULL;

    if (First == NULL)
    {
        First = new;
    }
    else
    {
        temp = First;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}
void swap(int k)
{
    struct Node *save, *temp1, *temp2;
    int count = 0, n = 0, temp = 0;

    save = First;
    while (save != NULL)
    {
        n++;
        save = save->link;
    }


    save = First;
    while (save != NULL)
    {
        if (count == k-1)
        {
            temp1 = save;
        }
        count++;
        save = save->link;
    }
    printf("%d",temp1->Info);

    save = First;
    count = 0;
    while (save != NULL)
    {
        if (count == n - k)
        {
            temp2 = save;
        }
        count++;
        save = save->link;
    }
    printf("%d",temp2->Info);
    temp = temp1->Info;
    temp1->Info = temp2->Info;
    temp2->Info = temp;
}
void display()
{
    struct Node *temp;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = First;
    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->Info);
        temp = temp->link;
    }

    return;
}
void main()
{
    int n, k;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    printf("Enter a k:");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    swap(k);
    display();
    return;
}