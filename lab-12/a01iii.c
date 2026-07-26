#include <stdio.h>
#include <stdlib.h>
struct Node{
    int Info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *First = NULL;
struct Node *Last = NULL;

void insertlist(int k){
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    new->Info = k;
    new->rptr = NULL;
    new->lptr = NULL;

    if (First == NULL)
    {
        First = Last = new;
    }
    else
    {
        Last->rptr = new;
        new->lptr = Last;
        Last = new;
    }
}
void insertAtLast(){
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("enter a info of new Node: ");
    scanf("%d",&new->Info);
    new->rptr = NULL;
    new->lptr = Last;

    if (First == NULL)
    {
        First = Last = new;
    }
    else
    {
        Last->rptr = new;
        Last = new;
    }
}
void display(){
    struct Node *temp = First;

    printf("Doubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->Info);
        temp = temp->rptr;
    }

    printf("NULL\n");
}

int main(){
    int n, k;

    printf("enter A size of list: ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        printf("enter a Info: ");
        scanf("%d",&k);

        insertlist(k);
    }

    insertAtLast();
    display();

    return 0;
}