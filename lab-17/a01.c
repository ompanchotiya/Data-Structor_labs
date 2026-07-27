#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
        }
    } while (choice != 4);
    return 0;
}