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

void delSpe(int num){
    struct Node *temp,*pred;
    if(First == NULL){
        printf("Link is empty");
        return;
    }
    else{
        temp=First;
        while(temp->Info != num){
            pred = temp;
            temp = temp->link;
        }
        pred->link = temp->link;
        free(temp);
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
void main()
{
    int n, i, num;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    printf("enter a number you want to delete: ");
    scanf("%d",&num);
    for (i = 0; i < n; i++)
    {
        insert();
    }
    delSpe(num);
    display();
    return;
}