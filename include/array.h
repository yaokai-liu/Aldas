/**
 * Filename: array.h
 * Creator: Yaokai Liu
 * Create Date: 2024-7-3
 * Copyright (c) 2024 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_ARRAY_H
#define LIU_ARRAY_H

#include "allocator.h"
#include <stddef.h>
#include <stdint.h>

typedef struct Array Array;
extern _SHARED_API const size_t sizeof_array;

_SHARED_API Array * Array_new(uint32_t ele_size, uint32_t id, const Allocator *allocator);

_SHARED_API uint32_t  Array_init(Array *array, uint32_t ele_size, const Allocator *allocator);

_SHARED_API uint32_t  Array_length(const Array *array);

// Note: append may change elements' real address,
// so it is not promised that two `Array_real_addr` of one same `index` will return a
// same address.
_SHARED_API void * Array_real_addr(const Array *array, uint32_t index);
// Promised that elements' virtual address would not be changed in one array.
_SHARED_API void * Array_virt_addr(const Array *array, uint32_t index);

#define Array_first_real(_Array) Array_real_addr(_Array, 0)
#define Array_first_virt(_Array) Array_virt_addr(_Array, 0)

_SHARED_API void * Array_last_real(const Array *array);

_SHARED_API void * Array_last_virt(const Array *array);

_SHARED_API void * Array_real2virt(const Array *array, const void *real_addr);

_SHARED_API void * Array_virt2real(const Array *array, const void *vert_addr);

_SHARED_API uint32_t  Array_append(Array *array, const void *elements, uint32_t count);

_SHARED_API uint32_t  Array_insert(Array *array, uint32_t index, const void *elements, uint32_t count);

_SHARED_API uint32_t  Array_delete(Array *array, uint32_t index, uint32_t count, bool shrink);

_SHARED_API uint32_t  Array_concat(Array *restrict dest, const Array *restrict src);

_SHARED_API uint32_t  Array_insert_array(Array *restrict dest, uint32_t index, const Array *restrict src);

_SHARED_API Array *  Array_clear_new(const Array *restrict template_array, const void *elements, uint32_t count);
// Promised that every element would be detected with `fn_judgment`.
// So that for traversing elements.
_SHARED_API bool  Array_any(const Array *array, bool (*fn_judgment)(void *));
// Promised that every element would be detected with `fn_judgment`.
// So that for traversing elements.
_SHARED_API bool  Array_all(const Array *array, bool (*fn_judgment)(void *));

_SHARED_API uint32_t  Array_filter(Array *origin_array, bool (*fn_judgment)(const void *));
// Filter an array by fn_judgment. The origin_array will not be clean and destroy.
_SHARED_API Array * Array_filtered(const Array *origin_array, bool (*fn_judgment)(const void *));

_SHARED_API uint32_t  Array_resize(Array *array, uint32_t resize, destruct_t *fn_free, bool shrink);

// Clear array and free all element with `fn_free`.
_SHARED_API uint32_t  Array_clear(Array *array, destruct_t *fn_free);
// Reset array and free all element with `fn_free`.
_SHARED_API uint32_t  Array_reset(Array *array, destruct_t *fn_free);
// Maybe cause memory leak if not reset array before destroy it.
_SHARED_API void  Array_destroy(Array *array);

#define releasePrimeArray(_array) \
  do {                            \
    Array_reset(_array, nullptr); \
    Array_destroy(_array);        \
  } while (false)

#endif  // LIU_ARRAY_H
