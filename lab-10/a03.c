#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Info;
    struct Node *link;
};
struct Node *First = NULL;

void insert()
{
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
void swapGCD(){
    struct Node *save, *next, *new;
    int gcd = 1, min=0;
    min = save->Info > next->Info? save->Info:next->Info;

    for(save=First; save!=NULL; save->link){
        for(int i=1; i<=min; i++){
            if(save->Info % i ==0  && save->Info % i ==0){
                gcd = i;
            }
        }
        new = (struct Node *)malloc(sizeof(struct Node));
        new->Info = gcd;
        
    }
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
void main()
{
    int n, k;

    printf("ENter number of Nodes: ");
    scanf("%d", &n);

    printf("Enter a k:");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    swapGCD();
    display();
    return;
}