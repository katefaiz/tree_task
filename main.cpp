#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>
#include <string.h>


#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"
#include "akinator.h"

// Tree* CreateTree() {
   
//     Node* tasa     = NodeInit(strdup("Тася"), NULL, NULL);
//     Node* nika     = NodeInit(strdup("Ника"), NULL, NULL);
//     Node* ksu    = NodeInit(strdup("Ксюша"), NULL, NULL);
//     Node* lizap  = NodeInit(strdup("Лиза П"), NULL, NULL);
//     Node* lizar     = NodeInit(strdup("Лиза Р"), NULL, NULL);
//     Node* lizac     = NodeInit(strdup("Лиза Ч"), NULL, NULL);
//     Node* nadak    = NodeInit(strdup("Надя К"), NULL, NULL);
//     Node* nadan  = NodeInit(strdup("Надя Н"), NULL, NULL);
//     Node* kate     = NodeInit(strdup("Катя"), NULL, NULL);
//     Node* sasa    = NodeInit(strdup("Саша"), NULL, NULL);
//     Node* pola  = NodeInit(strdup("Поля"), NULL, NULL);
//     Node* mari  = NodeInit(strdup("Маша"), NULL, NULL);

//     Node* node9   = NodeInit(strdup("Амбасадор скуратова"), mari, lizap);
//     Node* node11   = NodeInit(strdup("Рыжая"), nadan, lizac);
//     Node* node10   = NodeInit(strdup("Учится в ВУЗЕ"), node9, node11);
//     Node* node8   = NodeInit(strdup("Ушла в спорт"), nadak, pola);
//     Node* node7   = NodeInit(strdup("Адеват"), sasa, lizar);
//     Node* node6   = NodeInit(strdup("физмат"), kate, node8);
//     Node* node5   = NodeInit(strdup("Адеват"), nika, ksu);
//     Node* node4   = NodeInit(strdup("физмат"), tasa, node5);
//     Node* node3   = NodeInit(strdup("ушла из машеньки"), node6, node10);
//     Node* node2   = NodeInit(strdup("училась в 44 школе"), node4, node7);
//     Node* node1   = NodeInit(strdup("Школьник"), node2, node3);

//     Node* root = node1;

//     return TreeInit(7, root); 
// }

int main() {

    
    // Tree* tree = CreateTree();
    Node* root = NodeInit(strdup("nothing"), NULL, NULL);
    Tree* tree = TreeInit(1, root);
    TreeLoadFromFile(tree, "data_tree.txt");

    //TreeSaveToFile(tree, "data_tree.txt");
    TreeDump(tree);

    Akinator(tree);
    TreeDump(tree);
    
    TreeDestroy(tree);

    return 0;
}