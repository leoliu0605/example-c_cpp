#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if INCLUDE_linked_list
#include "linked_list/linked_list.h"
#endif
#if INCLUDE_queue
#include "queue/queue.h"
#endif
#if INCLUDE_ring_buffer
#include "ring_buffer/ring_buffer.h"
#endif

int main() {
}

#ifdef __cplusplus
}
#endif
