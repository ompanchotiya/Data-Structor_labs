#include <stdio.h>
#define MAX 5

int pq[MAX];
int size = 0;

void insert() {
    if (size == MAX) {
        printf("Overflow\n");
        return;
    }
    int val;
    scanf("%d", &val);
    int i = size - 1;
    while (i >= 0 && pq[i] > val) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = val;
    size++;
}

void delete() {
    if (size == 0) {
        printf("Underflow\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
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