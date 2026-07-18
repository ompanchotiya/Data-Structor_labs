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

void incertAtFirst(){
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info of new node: ");
    scanf("%d", &new->Info);

    if(First == NULL){
        printf("Node is Empty");

        return;
    }
    else{
        new->link = First;
        First = new;
        
        return;
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
void main(){
    int n, i;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        insert();
    }
    incertAtFirst();
    display();
    return;
}