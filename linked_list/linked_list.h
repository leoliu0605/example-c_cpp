#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * @brief Main struct for a linked list that provides access to all operations
 *
 * This struct wraps the linked list data structure and provides function pointers
 * to manipulate it. After initialization with initList(), these functions can be
 * used to create, modify, and query the list.
 */
typedef struct LinkedList {
    /** @brief Pointer to the head node of the list */
    struct ListNode* node;

    /**
     * @brief Creates a new list node with the given value
     * @param val Integer value to store in the node
     * @return Pointer to the newly created node
     */
    struct ListNode* (*new)(int val);

    /**
     * @brief Inserts a node after a specified node in the list
     * @param n0 The node after which to insert
     * @param P The node to insert
     */
    void (*insert)(struct ListNode* n0, struct ListNode* P);

    /**
     * @brief Removes the node immediately after a specified node
     * @param n0 The node preceding the one to remove
     */
    void (*remove)(struct ListNode* n0);

    /**
     * @brief Gets a node at the specified index in the list
     * @param head Pointer to the head of the list
     * @param index Zero-based index of the node to retrieve
     * @return Pointer to the node at the specified index, or NULL if not found
     */
    struct ListNode* (*get)(struct ListNode* head, int index);

    /**
     * @brief Finds the first node containing the specified value
     * @param head Pointer to the head of the list
     * @param target The value to search for
     * @return The index of the found node, or -1 if not found
     */
    int (*find)(struct ListNode* head, int target);
};

void initList(struct LinkedList* list);

#ifdef __cplusplus
}
#endif

#endif  // __LINKED_LIST_H
