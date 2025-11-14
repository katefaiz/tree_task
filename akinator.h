#ifndef AKINATOR_H
#define AKINATOR_H

#include "tree_types.h"

TreeError Akinator(Tree* tree);
TreeError AkinatorCreateObject(Tree* tree, Node* current_node);
TreeError AkinatorFindNode(Tree* tree, Node* current_node);
TreeError TreeSaveToFile(Tree* tree, const char* filename);
TreeError TreeSaveNodeToFile(Node* node, FILE* filestream);


#endif //AKINATOR_H