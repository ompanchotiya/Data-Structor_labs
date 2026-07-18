#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;

void insert(){
    struct Node *new, *temp;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    new->link = NULL;

    if (First == NULL)
    {
        First = new;
        return;
    }
    else
    {
        temp = First;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        return;
    }
}

void delFirst(){
    struct Node *temp;
    if(First == NULL){
        printf("Link is empty");
        return;
    }
    else{
        temp = First;
        First = First->link;
        free(temp);
    }
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
    int n, i;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        insert();
    }
    delFirst();
    display();
    return;
}