#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Info;
    struct Node* link;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
    int val;
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if (new == NULL) {
        printf("Overflow\n");
        return;
    }
    
    scanf("%d", &val);
    new->Info = val;
    new->link = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = new;
    } else {
        rear->link = new;
        rear = new;
    }
}

void dequeue() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d ", temp->Info);
        temp = temp->link;
    }
    printf("\n");
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