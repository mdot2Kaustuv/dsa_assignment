#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node *reverse(struct Node *head) {
   struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next ;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } 
    return prev;
    }

struct Node *createNode(int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void printlist(struct Node *node ){
    while (node != NULL) {
        printf("%d \n ", node->data);
        node = node->next;
    }
    }

int main() {
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head = reverse(head);
    printlist(head);
    return 0;
}



