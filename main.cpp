#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>

#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"

int main() {

    Node* node1 = NodeInit(3, NULL, NULL);
    Node* node2 = NodeInit(7, NULL, NULL);
    Node* node3 = NodeInit(15, NULL, NULL);
    Node* node5 = NodeInit(20, node3, NULL);
    Node* node6 = NodeInit(5, node1, node2);
    Node* node4 = NodeInit(10, node6, node5);

    Tree* tree = TreeInit(6, node4);
    
    Node* node_x = NodeInit(8, NULL, NULL);
    TreeInsertNode(tree, node_x);

    TreeDestroy(tree);

    return 0;
}