#include "linked_list.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new list node with the given value
 *
 * @param val Integer value to store in the node
 * @return struct ListNode* Pointer to the newly created node
 */
static struct ListNode* newListNode(int val) {
    struct ListNode* node;
    node       = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val  = val;
    node->next = NULL;
    return node;
}

/**
 * @brief Inserts a node after a specified node in the list
 *
 * @param n0 The node after which to insert
 * @param P The node to insert
 */
static void insertNode(struct ListNode* n0, struct ListNode* P) {
    struct ListNode* n1 = n0->next;
    n0->next            = P;
    P->next             = n1;
}

/**
 * @brief Removes the node immediately after a specified node
 *
 * @param n0 The node preceding the one to remove
 */
static void removeNode(struct ListNode* n0) {
    if (n0->next == NULL) {
        return;
    }
    struct ListNode* P  = n0->next;
    struct ListNode* n1 = P->next;
    n0->next            = n1;
    free(P);
}

/**
 * @brief Gets a node at the specified index in the list
 *
 * @param head Pointer to the head of the list
 * @param index Zero-based index of the node to retrieve
 * @return struct ListNode* Pointer to the node at the specified index, or NULL if not found
 */
static struct ListNode* getNode(struct ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == NULL) {
            return NULL;
        }
        head = head->next;
    }
    return head;
}

/**
 * @brief Finds the first node containing the specified value
 *
 * @param head Pointer to the head of the list
 * @param target The value to search for
 * @return int The index of the found node, or -1 if not found
 */
static int findNode(struct ListNode* head, int target) {
    int index = 0;
    while (head != NULL) {
        if (head->val == target) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

/**
 * @brief Initializes a LinkedList structure by setting up its function pointers
 *
 * @param list Pointer to the LinkedList structure to initialize
 */
void initList(struct LinkedList* list) {
    if (list == NULL) {
        return;
    }
    list->node   = NULL;
    list->new    = newListNode;
    list->insert = insertNode;
    list->remove = removeNode;
    list->get    = getNode;
    list->find   = findNode;
}

#ifdef __cplusplus
}
#endif
