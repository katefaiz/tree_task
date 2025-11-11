#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "tree_types.h"

int PrintTree(const Node* node, char* buffer);
Node* NodeInit(TreeElem value, Node* left, Node* right);
Tree* TreeInit(size_t size, TreeElem value);
TreeError NodeDestroy(Node* node);
TreeError TreeDestroy(Tree* tree);
TreeError TreeInsertNode(Tree* tree, Node* node);

#endif //BIN_TREE_H