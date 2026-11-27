/**
 * Filename: stack.h
 * Creator: Yaokai Liu
 * Create Date: 2024-10-27
 * Copyright (c) 2024 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_STACK_H
#define LIU_STACK_H

#include "allocator.h"
#include <stdint.h>

typedef struct Stack Stack;
extern _SHARED_API const uint32_t sizeof_stack;

_SHARED_API Stack *Stack_new(const Allocator *allocator);
_SHARED_API uint32_t Stack_size(const Stack *stack);
_SHARED_API void *Stack_get(const Stack *stack, uint32_t offset);
_SHARED_API void Stack_clear(Stack *stack);
_SHARED_API uint32_t Stack_push(Stack *stack, const void *data, uint32_t size);
_SHARED_API uint32_t Stack_pop(Stack *stack, void *dest, uint32_t size);
_SHARED_API uint32_t Stack_top(const Stack *stack, void *dest, uint32_t size);
_SHARED_API bool Stack_empty(const Stack *stack);
#endif  // LIU_STACK_H
