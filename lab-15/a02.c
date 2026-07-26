#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}


char peek(){
    return stack[top];
}

int precedence(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void reverse(char str[]){
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[SIZE], postfix[SIZE], prefix[SIZE];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++){
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    top = -1;

    for (i = 0; infix[i] != '\0'; i++){

        if (isalnum(infix[i])){
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '('){
            push(infix[i]);
        }

        else if (infix[i] == ')'){
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }

        else{
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
                postfix[j++] = pop();

            push(infix[i]);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}