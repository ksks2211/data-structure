/* linked_list.h */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
void insert_at_head(Node** head_ref, int data);
void insert_at_tail(Node** head_ref, int data);
void insert_after(Node* prev_node, int data);
void delete_node(Node** head_ref, int key);
void delete_list(Node** head_ref);
void print_list(Node* head);

#endif
