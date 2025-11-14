#ifndef TREE_TYPES_H
#define TREE_TYPES_H

#include <math.h>
#define TreeElem char*
#define POIZON 666
#define BUFFER_CONST 5

struct Node {
    TreeElem value;
    Node* left;
    Node* right;
};

struct Tree {
    size_t size;
    Node* root;
   // Node* data;
};

enum TreeError {
    TREE_NO_ERROR       = 0,
    TREE_MEMORY_ERROR   = 1,
    TREE_FILE_ERROR     = 2

};

#endif //TREE_TYPES_H