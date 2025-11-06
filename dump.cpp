#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>

#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"


TreeError DumpCreateBase (Tree* tree, FILE *filestream) {
    assert(tree);
    assert(filestream);

    fprintf(filestream, "digraph Tree {\n");

    return TREE_NO_ERROR;

}

TreeError DumpCreateNode(Node* node, FILE *filestream) {
    assert(node);
    assert(filestream);

    fprintf(filestream, "\tnode%p[shape=Mrecord, style=\"rounded, filled\", fillcolor=\"lightgreen\", "
                       "label=\"{%p | {%d} | {%p | %p}}\"]\n", 
            node, node, node->value, 
            node->left, node->right);

    if (node->left) {
        fprintf(filestream, "\tnode%p -> node%p\n", node, node->left);
        DumpCreateNode(node->left, filestream);
    }

    if (node->right) {
        fprintf(filestream, "\tnode%p -> node%p\n", node, node->right);
        DumpCreateNode(node->right, filestream);
    }

    return TREE_NO_ERROR;
}

TreeError TreeDump(Tree *tree) {
    assert(tree);

    FILE *filestream = fopen("tree.dot", "w");
    if (filestream == NULL) 
        return TREE_FILE_ERROR;

    DumpCreateBase(tree, filestream);
    fprintf(filestream, "\n");
    DumpCreateNode(tree->root, filestream);
    fprintf(filestream, "\n");
    fprintf(filestream, "}");

    char* buffer = (char*)calloc(1024, sizeof(char));
    if (buffer == NULL) {
        printf("Calloc error\n");
        return TREE_MEMORY_ERROR;
    }

    fclose(filestream);

    int id = rand();
    sprintf(buffer, "dot -Tpng tree.dot -o png/dump%d.png", id);
    int status = system(buffer);
    if (status != 0) {
        free(buffer);
        return TREE_MEMORY_ERROR;
    }
    
    free(buffer);

    return TREE_NO_ERROR;
}