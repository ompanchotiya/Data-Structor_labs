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
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->Info = k;
    newNode->rptr = NULL;
    newNode->lptr = NULL;

    if (First == NULL)
    {
        First = Last = newNode;
    }
    else
    {
        Last->rptr = newNode;
        newNode->lptr = Last;
        Last = newNode;
    }
}
void alternateNode(){
     
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

    insertAtFirst();
    display();

    return 0;
}