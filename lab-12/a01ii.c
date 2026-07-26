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
void deleteAtSpc(int pos){
    struct Node *save;
    int i;

    if(First == NULL){
        printf("List is enpty");
        return;
    }
    if(pos == 1){
        First = First->rptr;

        if(First != NULL){
            First->lptr = NULL;
        }
        else{
            Last = NULL;
        }
        free(save);
        return;
    }
    for (i=1; i<pos && save!=NULL; i++)
    {
        save = save->rptr;
    }

    if (save == NULL)
    {
        printf("Invalid Position\n");
        return;
    }
    if (save == Last)
    {
        Last = save->lptr;
        Last->rptr = NULL;
    }
    else
    {
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
    }

    free(save);
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
    int n, k, pos=0;

    printf("enter A size of list: ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        printf("enter a Info: ");
        scanf("%d",&k);

        insertlist(k);
    }
    
    printf("Enter a position You want to delete: ");
    scanf("%d",&pos);

    deleteAtSpc(pos);
    display();

    return 0;
}