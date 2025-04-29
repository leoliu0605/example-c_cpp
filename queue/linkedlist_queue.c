#include "linkedlist_queue.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../linked_list/linked_list.h"

static struct LinkedListQueue* newLinkedListQueue() {
    struct LinkedListQueue* queue = (struct LinkedListQueue*)malloc(sizeof(struct LinkedListQueue));
    queue->front                  = NULL;
    queue->rear                   = NULL;
    queue->size                   = 0;
    return queue;
}

static void deleteLinkedListQueue(struct LinkedListQueue* queue) {
    if (queue == NULL) {
        return;
    }
    struct ListNode* current = queue->front;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

static int linkedListQueueSize(struct LinkedListQueue* queue) {
    return queue->size;
}

static bool linkedListQueueIsEmpty(struct LinkedListQueue* queue) {
    return linkedListQueueSize(queue) == 0;
}

static void linkedListQueuePush(struct LinkedListQueue* queue, int value) {
    struct LinkedList list = {0};
    initList(&list);
    struct ListNode* node = list.new(value);
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear  = node;
    } else {
        queue->rear->next = node;
        queue->rear       = node;
    }
    queue->size++;
}

static int linkedListQueuePeek(struct LinkedListQueue* queue) {
    assert(linkedListQueueSize(queue) && queue->front);
    return queue->front->val;
}

static int linkedListQueuePop(struct LinkedListQueue* queue) {
    int value            = linkedListQueuePeek(queue);
    struct ListNode* tmp = queue->front;
    queue->front         = queue->front->next;
    free(tmp);
    queue->size--;
    return value;
}

void initQueue(struct Queue* queue) {
    queue->create  = newLinkedListQueue;
    queue->destroy = deleteLinkedListQueue;
    queue->size    = linkedListQueueSize;
    queue->isEmpty = linkedListQueueIsEmpty;
    queue->push    = linkedListQueuePush;
    queue->peek    = linkedListQueuePeek;
    queue->pop     = linkedListQueuePop;
}

#ifdef __cplusplus
}
#endif
