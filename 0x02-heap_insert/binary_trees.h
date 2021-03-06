#ifndef _TREE_BINARY_H_
#define _TREE_BINARY_H_
#include <stdio.h>
#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree
 *
 * @n: Integer
 * @parent: parent node
 * @left: left child node
 * @right: right child node
 */
typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
#endif