/**
 * Filename: trie.h
 * Creator: Yaokai Liu
 * Create Date: 2024-12-04
 * Copyright (c) 2024 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_TRIE_H
#define LIU_TRIE_H

#include <stdint.h>
#include "allocator.h"

typedef struct Trie Trie;
extern _SHARED_API const uint32_t sizeof_trie;

_SHARED_API Trie *Trie_new(uint32_t key_size, uint64_t (*fn_key)(const void *), const Allocator *allocator);
_SHARED_API void Trie_destroy(Trie *tree);

_SHARED_API uint64_t Trie_count(const Trie *tree);
_SHARED_API void *Trie_get(const Trie *tree, const void *key);
_SHARED_API void Trie_set(Trie *tree, const void *key, void *value);
_SHARED_API void Trie_del(Trie *tree, const void *key, destruct_t *del_content);

#endif  // LIU_TRIE_H
