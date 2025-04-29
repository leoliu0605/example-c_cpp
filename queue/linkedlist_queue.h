#ifndef __LINKEDLIST_QUEUE_H
#define __LINKEDLIST_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListQueue {
    struct ListNode *front, *rear;
    int size;
};

typedef struct Queue {
    struct LinkedListQueue* (*create)();
    void (*destroy)(struct LinkedListQueue* queue);
    int (*size)(struct LinkedListQueue* queue);
    bool (*isEmpty)(struct LinkedListQueue* queue);
    void (*push)(struct LinkedListQueue* queue, int value);
    int (*peek)(struct LinkedListQueue* queue);
    void (*pop)(struct LinkedListQueue* queue);
};

void initQueue(struct Queue* queue);

#ifdef __cplusplus
}
#endif

#endif  // __LINKEDLIST_QUEUE_H
