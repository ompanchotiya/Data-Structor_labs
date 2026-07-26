#include<stdio.h>
#define n 5

int stack[n];
int top = -1;
void push(int x){
    if(top >= n-1){
        printf("stack overflow");
        return;
    }
    else{
        top++;
        stack[top] = x;
        return;
    }
}
int pop(){
    if(top < 0){
        printf("stack underflow");
        return 0;
    }
    else{
        return stack[top--];
    }
}
int peep(int k){
    if(k < 0 || k > top){
        printf("invalid");
        return 0;
    }
    else{
        return stack[top-k+1];
    }
}
void change(int x,int k){
    if(k < 0 || k > top){
        printf("invalid");
        return;
    }
    else{
        stack[top-k+1] = x;
        return;
    }
}
void display(){
    int i;

    if(top == -1){
        printf("stack is empty");
        return;
    }
    else{
        for(i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
void main(){
    int k, x, choice;

    printf("Enter a number (1-4)/n 1 for push/n 2 for pop/n 3 for peep/n 4 for change: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        printf("enter a number you want to encert: ");
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            push(x);
        }
        display();
        break;

        case 2:
        pop();
        display();
        break;

        case 3:
        int ans;
        printf("enter a position you want to know: ");
        scanf("%d",&k);
        ans = peep(k);
        printf("%d",ans);
        break;

        case 4:
        printf("enter a position you want to know: ");
        scanf("%d",&k);
        change(x,k);
        display();
        break;
    }
}