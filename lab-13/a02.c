#include <stdio.h>
#include <stdlib.h>

struct Node{
    int Info;
    struct Node *link;
};

struct Node *Top = NULL;


void push(int x)
{
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    if (new == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    new->Info = x;
    new->link = Top;
    Top = new;
}
void pop(){
    struct Node *temp;

    if (Top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = Top;
    printf("%d\n", Top->Info);

    Top = Top->link;
    free(temp);
}
void display(){
    struct Node *temp;

    if (Top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    temp = Top;
    while (temp != NULL)
    {
        printf("%d\n", temp->Info);
        temp = temp->link;
    }
}
int main(){
    int n, x;

    printf("enter a size of list: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("enter a number you want to encert: ");
        scanf("%d",&x);
        push(x);
    }
    display();

    pop();
    pop();
    display();

    return 0;
}