#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;
struct Node *Last = NULL;

void insert(){
    struct Node *new, *save;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    new->link = NULL;

    if (First == NULL && Last == NULL){
        First = new;
        Last = new;
    }
    else
    {
        save = First;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = new;
    }
}
void insertAtFirst(){
    struct Node
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

    for (int i = 0; i < n; i++)
    {
        insert();
    }
    display();
    return;
}