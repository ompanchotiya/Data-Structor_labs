#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;

void insert(){
    struct Node *new, *save;

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
        save = First;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = new;
    }
}
void reverseList(){
    struct Node *save, *pred = NULL, *next = NULL;

    save = First;
    while(save != NULL){
        next = save->link;
        save->link = pred;
        pred = save;
        save = next; 
    }
    First = pred;
}
void display()
{
    struct Node *save;

    printf("New Linklist");
    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    save = First;
    printf("Linked List: ");

    while (save != NULL)
    {
        printf("%d ", save->Info);
        save = save->link;
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
    reverseList();
    display();
    return;
}