#include <stdio.h>
#define SIZE 100

struct Interval{
    int start;
    int end;
};

struct Interval stack[SIZE];
int top = -1;

void push(struct Interval x){
    stack[++top] = x;
}

struct Interval pop(){
    return stack[top--];
}

struct Interval peek(){
    return stack[top];
}

void main(){
    int n, i;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval a[n];

    printf("Enter intervals in sorted order:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &a[i].start, &a[i].end);
    }

    push(a[0]);

    for(i = 1; i < n; i++){
        struct Interval temp = peek();

        if(a[i].start <= temp.end){
            pop();

            if(a[i].end > temp.end)
                temp.end = a[i].end;

            push(temp);
        }
        else{
            push(a[i]);
        }
    }

    for(i = 0; i <= top; i++){
        printf("{%d,%d} ", stack[i].start, stack[i].end);
    }
}