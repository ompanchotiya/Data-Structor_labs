#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;
struct Node *Last = NULL;

void insert(){
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    if (First == NULL){
        First = Last = new;
        new->link = First;
    }
    else
    {
        
        Last->link = new;
        Last = new;
        Last->link = First;
    }
}
void insertAtFirst(){
    struct Node *new;

    new = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter a info of new Node: ");
    scanf("%d",&new->Info);

    if(First == NULL){
        First = Last = new;
        new->link = First;
    }
    else{
        new->link = First;
        Last->link = new;
        First = new;
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
    do
    {
        printf("%d -> ", temp->Info);
        temp = temp->link;
    }
    while (temp != First);
    printf("(Back to First)\n");

    return;
}
void main()
{
    int n;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        insert();
    }
    insertAtFirst();
    display();
    return;
}