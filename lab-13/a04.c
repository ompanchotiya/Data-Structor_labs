#include <stdio.h>
#include <string.h>

#define n 100

char stack[n];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top == -1){
        return 0;
    }
    return stack[top--];
}

int main(){
    char str[100];
    int i = 0;

    printf("Enter string: ");
    scanf("%s", str);


    while(str[i] == 'a'){
        push('a');
        i++;
    }

    while(str[i] == 'b'){
        if(pop() == 0){
            printf("Invalid String\n");
            return 0;
        }
        i++;
    }

    if(str[i] == 0 && top == -1){
        printf("Valid String\n");
    }
    else{
        printf("Invalid String\n");
    }

    return 0;
}