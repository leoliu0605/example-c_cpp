#include "linked_list.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

// TODO: 改成可重用抽象化的架構

struct LinkedList {
    int value;
    struct LinkedList *next;
};

struct LinkedList *linked_list = NULL;

void linkedListDump(void) {
    struct LinkedList *head = linked_list;
    int idx                 = 0;
    while (head) {
        printf("%2d) 0x%2X\r\n", ++idx, head->value);
        head = head->next;
    }
}

void linkedListAppend(int value) {
    struct LinkedList *list = malloc(sizeof(*list));
    list->value             = value;
    list->next              = NULL;

    if (linked_list == NULL) {
        linked_list = list;
    } else {
        struct LinkedList *p = linked_list;
        while (p->next) p = p->next;
        p->next = list;
    }
}

void linkedListRemove(int value) {
    struct LinkedList *head = linked_list;
    struct LinkedList *prev = NULL;
    while (head) {
        if (head->value == value) {
            if (prev == NULL) {
                linked_list = head->next;
            } else {
                prev->next = head->next;
            }
            head->next = NULL;
            free(head);
            head = NULL;
            break;
        } else {
            prev = head;
            head = head->next;
        }
    }
}

int main() {
    printf("Hello Linked List\r\n");
    printf("\r\n");

    linkedListAppend(0x55);
    linkedListAppend(0xAA);
    linkedListAppend(0x5A);
    linkedListDump();

    linkedListRemove(0x55);
    linkedListDump();

    return 0;
}

#ifdef __cplusplus
}
#endif
