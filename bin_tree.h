#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "tree_types.h"

TreeError PrintNode(const Node* node);
Node* NodeInit(TreeElem value, Node* left, Node* right);
Tree* TreeInit(size_t size, Node* root);
TreeError NodeDestroy(Node* node);
TreeError TreeDestroy(Tree* tree);
TreeError TreeInsertNode(Tree* tree, Node* node);


#endif //BIN_TREE_H