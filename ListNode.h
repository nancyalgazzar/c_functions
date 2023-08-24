#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <stdio.h>
#include <stdlib.h>

// Definition of struct ListNode
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create a new ListNode
struct ListNode* createNode(int value);

// Function to add a new ListNode to the end of the list
void append(struct ListNode** head, int value);

// Function to print the elements of the linked list
void printLinkedList(struct ListNode* head);

// Function to free the memory occupied by the linked list
void freeLinkedList(struct ListNode* head);

#endif
