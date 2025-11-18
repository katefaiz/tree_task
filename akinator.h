#ifndef AKINATOR_H
#define AKINATOR_H

#include "tree_types.h"

TreeError Akinator(Tree* tree);
TreeError AkinatorCreateObject(Tree* tree, Node* current_node);
TreeError AkinatorFindNode(Tree* tree, Node* current_node);

TreeError TreeSaveToFile(Tree* tree, const char* filename);
TreeError TreeSaveNodeToFile(Node* node, FILE* filestream);

void SkipSpace(const char** str_ptr);
size_t CountNodes(Node* node);

TreeError TreeLoadFromFile(Tree* tree, const char* filename);
TreeError CreateTreeFromStr(Tree* tree, const char* str);
Node* CreateNodeFromStr(const char** str_ptr);

#endif //AKINATOR_H