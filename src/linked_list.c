/* linked_list.c */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Create a new node with the given data */
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Insert a new node with the given data at the beginning of the list */
void insert_at_head(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Insert a new node with the given data at the end of the list */
void insert_at_tail(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* current_node = *head_ref;
    if (current_node == NULL) {
        *head_ref = new_node;
        return;
    }
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

/* Insert a new node with the given data after the given node */
void insert_after(Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Cannot insert after NULL node\n");
        return;
    }
    Node* new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Delete the first node with the given key from the list */
void delete_node(Node** head_ref, int key) {
    Node* current_node = *head_ref;
    Node* prev_node = NULL;
    if (current_node != NULL && current_node->data == key) {
        *head_ref = current_node->next;
        free(current_node);
        return;
    }
    while (current_node != NULL && current_node->data != key) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Error: Key not found\n");
        return;
    }
    prev_node->next = current_node->next;
    free(current_node);
}

/* Delete the entire list */
void delete_list(Node** head_ref) {
    Node* current_node = *head_ref;
    Node* next_node;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    *head_ref = NULL;
}

/* Print the entire list */
void print_list(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
