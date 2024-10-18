#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

void insert(struct CircularLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
    }
}

void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

int main() {
    struct CircularLinkedList list = {NULL};
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    display(&list);
    return 0;
}