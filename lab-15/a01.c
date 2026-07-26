#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
char postfix[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int F(char ch){
    switch(ch)
    {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 3;

        case '^': return 6;

        case '(': return 0;

        default:
            if(isalnum(ch))
                return 7;
    }
    return -1;
}
int G(char ch){
    switch(ch){
        case '+':
        case '-': return 2;

        case '*':
        case '/': return 4;

        case '^': return 5;

        case '(': return 9;

        case ')': return 0;

        default:
            if(isalnum(ch))
                return 8;
    }
    return -1;
}
int R(char ch){
    if(isalnum(ch))
        return 1;

    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return -1;

    return 0;
}

int main(){
    char infix[MAX];
    int i=0, j=0, rank=0;
    char next, temp;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('(');

    int len=0;
    while(infix[len]!='\0'){
        len++;
    }

    infix[len]=')';
    infix[len+1]='\0';

    next=infix[i++];

    while(next!='\0'){
        while(F(stack[top]) > G(next)){
            temp=pop();
            postfix[j++]=temp;
            rank += R(temp);

            if(rank<1)
            {
                printf("INVALID Expression\n");
                return 0;
            }
        }

        if(F(stack[top]) != G(next))
            push(next);
        else
            pop();

        next=infix[i++];
    }

    postfix[j]='\0';

    if(top!=-1 || rank!=1)
        printf("INVALID Expression\n");
    else
        printf("Postfix Expression = %s\n", postfix);

    return 0;
}