#include <stdio.h>
#include <stdlib.h>
struct Node{
    int Info;
    struct Node *Plink;
    struct Node *Nlink;
};

struct Node *First = NULL;
struct Node *Last = NULL;

void insert(int value){
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    new->Info = value;
    new->Nlink = NULL;
    new->Plink = NULL;

    if (First == NULL){
        First = Last = new;
    }
    else{
        new->Plink = Last;
        Last->Nlink = new;
        Last = new;
    }
}
void insertAtFirst(){
    struct Node *new;

    new = (struct Node*)malloc(sizeof(struct Node));

    printf("enter a value of new Node:");
    scanf("%d",&new->Info);
}
void display(){
    struct Node *temp;

    if (First == NULL){
        printf("List is Empty\n");
        return;
    }

    temp = First;

    while (temp != NULL){
        printf("%d <-> ", temp->Info);
        temp = temp->Nlink;
    }
    printf("NULL\n");
}
int main(){
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        printf("Enter value: ");
        scanf("%d", &value);

        insert(value);
    }

    display();
    return 0;
}