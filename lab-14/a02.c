#include<stdio.h>
#define n 100

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
void display(){
    int i;

    if(top == -1){
        printf("stack is empty");
        return;
    }
    else{
        for(i = 0; i <= top; i++){
            printf("%c", stack[i]);
        }
    }
}
void main(){
    char s[100];
    int i = 0;

    printf("enter a String: ");
    scanf("%s", s);

    if(s[0] == '*'){
        printf("string not valid");
        return;
    }
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '*'){
            pop();
        }
        else{
            push(s[i]);
        }
    }

    for(i = 0; i <= top; i++){
        printf("%c", stack[i]);
    }
}