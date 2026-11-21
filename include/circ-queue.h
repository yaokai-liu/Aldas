/**
* Filename: circ-queue.h
 * Creator: Yaokai Liu
 * Create Date: 2026-10-10
 * Copyright (c) 2026 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_CIRC_QUEUE_H
#define LIU_CIRC_QUEUE_H

#include "allocator.h"
#include <stddef.h>
#include <stdint.h>

typedef struct CircQueue /*extend Array*/ CircQueue;
extern _SHARED_API const size_t sizeof_circ_queue;

_SHARED_API CircQueue *CircQueue_new(uint32_t ele_size, uint32_t id, const Allocator * allocator);
_SHARED_API uint32_t CircQueue_init(CircQueue *queue, uint32_t ele_size, const Allocator *allocator);

_SHARED_API uint32_t CircQueue_count(const CircQueue *queue);

_SHARED_API uint32_t CircQueue_push_array(CircQueue *queue, const void *elements, uint32_t count);
_SHARED_API uint32_t CircQueue_pop_array(CircQueue *queue, void *dest, uint32_t count);
_SHARED_API uint32_t CircQueue_push(CircQueue *queue, const void *element);
_SHARED_API uint32_t CircQueue_pop(CircQueue *queue, void *dest);

#endif //LIU_CIRC_QUEUE_H
