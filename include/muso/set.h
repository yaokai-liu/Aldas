/**
 * Filename: set.h
 * Creator: Yaokai Liu
 * Create Date: 2024-12-04
 * Copyright (c) 2024 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_SET_H
#define LIU_SET_H

#include "allocator.h"
#include "key_t.h"
#include <stdint.h>

typedef struct Set Set;
extern _SHARED_API const uint32_t sizeof_set;

_SHARED_API Set *Set_new(uint32_t ele_size, uint32_t set_id, key_t *fn_key,
             destruct_t *fn_release, const Allocator *allocator);

_SHARED_API uint32_t Set_add(const Set *set, const void * v_ele);

// Notice: after remove elements, must tidy the set before access its data
_SHARED_API uint32_t Set_remove(const Set *set, const void * v_ele);

// dest = dest | set
// @return: count of adds
_SHARED_API uint32_t Set_update(const Set *dest, const Set *set);
// set = set - red
// @return: count of removes
_SHARED_API uint32_t Set_reduce(Set *set, const Set *red);
// set = set & lim
// @return: count of removes
_SHARED_API uint32_t Set_limit(Set *set, const Set *lim);

_SHARED_API void * Set_data(const Set *set);
_SHARED_API uint32_t Set_count(const Set *set);
_SHARED_API bool Set_has(const Set *set, const void * ele);

_SHARED_API void Set_tidy(Set *set);
_SHARED_API void Set_reset(const Set *set);
_SHARED_API void Set_destroy(Set *set);

#endif  // LIU_SET_H
