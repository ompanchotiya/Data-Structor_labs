#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    int val;
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Overflow\n");
        return;
    }
    scanf("%d", &val);
    
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1 && front != 0) rear = 0;
    else rear++;
    
    queue[rear] = val;
}

void delete() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

void display() {
    if (front == -1) {
        printf("\n");
        return;
    }
    if (front <= rear) {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++) printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++) printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: break;
        }
    } while (choice != 4);
    return 0;
}