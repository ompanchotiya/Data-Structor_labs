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
void duplicate(){
    struct Node *dup, *save;
    save = First;
    
    
    while(save->link != NULL){
        if(save->Info == save->link->Info){
            dup = save->link;
            save->link = dup->link;
            free(dup);

        }
    }
    return;
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
    int n, m;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    duplicate();
    display();
    return;
}