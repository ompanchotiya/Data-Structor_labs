#include <stdio.h>
#include<stdlib.h>
struct Node{
    int Info;
    struct Node *link;
};
struct Node *First1 = NULL;
struct Node *First2 = NULL;

void insert1(){
    struct Node *new, *temp;

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
        temp = First1;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}
void insert2(){
    struct Node *new, *temp;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &new->Info);

    new->link = NULL;

    if (First2 == NULL)
    {
        First2 = new;
    }
    else
    {
        temp = First2;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}
void Compare(){
    struct Node *temp1,*temp2;

    temp1 = First1;
    temp2 = First2;

    if(temp1 == NULL && temp2 == NULL){
        printf("list are same");
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->Info == temp2->Info){
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else{
            printf("link are not same");
            return;
        }
    }
    if(temp1 == NULL && temp2 == NULL){
        printf("list are same");
    }
    else{
        printf("link are not same");
    }
}
void main(){
    int n, m;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        insert1();
    }

    printf("ENter number of Nodes: ");
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++)
    {
        insert2();
    }
    Compare();
    return;
}