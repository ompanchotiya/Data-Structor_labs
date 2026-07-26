#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

int main() {
    char prefix[MAX];
    int i, op1, op2, result;

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--){

        if (isdigit(prefix[i])){
            push(prefix[i] - '0');
        }
        else{
            op1 = pop();
            op2 = pop();

            switch (prefix[i]){
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = op1 % op2;
                    break;
            }
            push(result);
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}