#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int number;
    struct Node* next;
};

void print(struct Node* node){
    printf("%d -> ", node->number);
    if (node->next == NULL){
        printf("\n");
        return;
    }
    print(node->next);
}

void append(struct Node* node, int num){
    if (num >= node->number && node->next == NULL){
        node->next = (struct Node*) malloc(sizeof(struct Node*));
        node->next->number = num;
        node->next->next = NULL;
    }
    else if (num <= node->number){
        struct Node* new = (struct Node*) malloc(sizeof(struct Node*));
        new->next = node->next;
        new->number = node->number;
        node->next = new;
        node->number = num;
    }
    else append(node->next, num);
}

struct Node* init(int num){
    struct Node* new = malloc(sizeof(struct Node*));
    new->number = num;
    new->next = NULL;
    return new;
}

void delete(struct Node* node, int num){
    struct Node* current = node;
    while(current->next->number != num) current = current->next;

    if(current->next->next == NULL) {
        free(current->next);
        current->next = NULL;
    }
    else{
        current = current->next;
        struct Node* temp = current->next;
        memcpy(current, current->next, sizeof(struct Node));
        free(temp);
    }
}

struct Node* max(struct Node* head){
    struct Node* max = head;
    while(max->next != NULL) max = max->next;
    return max;
}

int main(){
    struct Node* head = init(3);
    append(head, 4);append(head, 2);append(head, -1); append(head,12); append(head, -23);
    delete(head, 12);
    print(head);
    printf("max: %d\n", max(head)->number);
    return 0;
}