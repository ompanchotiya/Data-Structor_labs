#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First1 = NULL;
struct Node *First2 = NULL;

void insert(){
    struct Node *new, *save1;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    new->link = NULL;

    if (First1 == NULL)
    {
        First1 = new;
    }
    else
    {
        save1 = First1;
        while (save1->link != NULL)
        {
            save1 = save1->link;
        }
        save1->link = new;
    }
}
void copyList(){
    struct Node *save1, *save2, *new;

    save1 = First1; 
    
    while(save1 != NULL){ 
        new = (struct Node*)malloc(sizeof(struct  Node));   
        new->Info = save1->Info;
        new->link = NULL;

        if(First2 == NULL){
            First2 = new;
            save2 = First2;
        } 
        else{
            save2->link = new;
            save2 = new;
        }
        save1 = save1->link;
    }
}
void display()
{
    struct Node *save2;

    printf("New Linklist");
    if (First1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    save2 = First2;
    printf("Linked List: ");

    while (save2 != NULL)
    {
        printf("%d ", save2->Info);
        save2 = save2->link;
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
    copyList();
    display();
    return;
}