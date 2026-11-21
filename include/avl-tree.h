/**
 * Filename: avl-tree.h
 * Creator: Yaokai Liu
 * Create Date: 2024-12-04
 * Copyright (c) 2024 Yaokai Liu. All rights reserved.
 **/

#ifndef LIU_AVL_TREE_H
#define LIU_AVL_TREE_H

#include "allocator.h"
#include <stdint.h>

typedef struct AVLTree AVLTree;
extern _SHARED_API const size_t sizeof_avltree;

typedef int32_t compare_t(void *, void *);

_SHARED_API AVLTree *AVLTree_new(const Allocator *allocator, compare_t *fn_compare);
_SHARED_API void AVLTree_reset(AVLTree *tree, destruct_t *del_value);
_SHARED_API void AVLTree_destroy(AVLTree *tree, destruct_t *del_value);

_SHARED_API uint64_t AVLTree_height(const AVLTree *tree);
_SHARED_API void *AVLTree_get(const AVLTree *tree, uint64_t key);
_SHARED_API int32_t AVLTree_set(AVLTree *tree, uint64_t key, void *value);

#endif  // LIU_AVL_TREE_H
