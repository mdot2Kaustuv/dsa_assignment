# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printlist(struct Node *node ){
    while (node != NULL) {
        printf("%d \n ", node->data);
        node = node->next;
    }
    }

void addnodeafter(int data , struct Node* prev_node){
   if (prev_node == NULL){
      printf("it cant be inserted if the previous node is null");
    }
    struct Node* newNode = createNode(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if (newNode->next != NULL){
        newNode->next->prev = newNode;
    }
}

struct Node* deletenode(struct Node* head, int data) {
    struct Node* temp = head ;
    while (temp !=NULL && temp->data != data){
        temp = temp->next ;
    }
    if (temp == NULL){
        return head ;
    }
    //if it is head 
    if (temp == head){
        head = head->next ;
        if (head != NULL){
            head->prev = NULL ;
        }
        free (temp);
        return head ;
    }
    else {
       struct Node *deletednode = temp->next ;
        temp->next = deletednode->next ;
        if (deletednode->next != NULL){
            deletednode->next->prev = temp ;
        }
        free(deletednode);
        return head ;
    }
}



int main(){
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);
    struct Node* fourth = createNode(50);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    printf("Original linked list: ");
    printlist(head);
    printf("Linked list after insertion: ");
    addnodeafter(40,third);
    printlist(head);
    printf("Linked list after deletion: ");
    head = deletenode(head,20);
    printlist(head);
    return 0;
}