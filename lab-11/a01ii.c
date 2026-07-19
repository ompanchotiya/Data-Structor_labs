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
void deleteAtSpc(int k){
    struct Node *save, *pred;
    int i, count = 1;

    if(First == NULL){
        printf("list was empty");
        return;
    }

    save = First;
    while(save != First){
        save = save->link;
        count++;
    }

    if(k == 1){
        save = First;

        if (First == Last){
            First = Last = NULL;
        }
        else{
            First = First->link;
            Last->link = First;
        }
        free(save);
        return;
    }
    pred = First;
    save = First;

    for(i = 1; i < k; i++){
        pred = save;
        save = save->link;
    }
    pred->link = save->link;

    if(save == Last){
        Last = pred;
        Last->link = First;
    }
    free(save);
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
    int n, k;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        insert();
    }
    printf("Enter a Position you want to delete:");
    scanf("%d",&k);
    deleteAtSpc(k);
    display();
    return;
}