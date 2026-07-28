#include <stdio.h>
#include <string.h>

#define n 100

char stack[n];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int main(){
    char str[100];
    int i, len, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0; i<len; i++){
        while(str[i] != 'c'){
            push(str[i]);
        }
        i++;
        if(str[i] != pop()){
            flag = 0;
            break;
        }
    }
    if(flag = 1){
        printf("Palindrome String\n");
    }
    else{
        printf("Not a Palindrome\n");
    }
    return 0;
}