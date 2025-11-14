#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>
#include <string.h>


#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"
#include "akinator.h"

Tree* CreateTree() {
   
    Node* luk     = NodeInit(strdup("Лукашов"), NULL, NULL);
    Node* dim     = NodeInit(strdup("Дымарский"), NULL, NULL);
    Node* bull    = NodeInit(strdup("Буллинский"), NULL, NULL);
    Node* poltor  = NodeInit(strdup("Полторашка"), NULL, NULL);

    Node* node3   = NodeInit(strdup("лысый"), dim, bull);
    Node* node2   = NodeInit(strdup("лектор"), luk, node3);
    Node* node1   = NodeInit(strdup("Ведет матан"), node2, poltor);

    Node* root = node1;

    return TreeInit(7, root); 
}

int main() {

    //Node* root = NodeInit(strdup("nothing"), NULL, NULL);
    //Tree* tree = TreeInit(1, root);
    Tree* tree = CreateTree();
    TreeDump(tree);

    Akinator(tree);
    TreeDump(tree);
    TreeSaveToFile(tree, "data_tree.txt");
    
    TreeDestroy(tree);

    return 0;
}