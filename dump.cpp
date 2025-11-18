#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>

#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"

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

    char* buffer = (char*)calloc(LONG_BUFFER_CONST, sizeof(char));
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
        return TREE_FILE_ERROR;
    }
    free(buffer);

    FILE *html_file = fopen("dump.html", "a");
    MakeHTML(tree, html_file, id); 
    fclose(html_file);
    
    return TREE_NO_ERROR;
}

TreeError DumpCreateBase (Tree* tree, FILE *filestream) {
    assert(tree);
    assert(filestream);

    fprintf(filestream, "digraph Tree {\n");

    return TREE_NO_ERROR;

}

TreeError DumpCreateNode(Node* node, FILE *filestream) {
    assert(node);
    assert(filestream);

    const char* fillcolor = (node->left == NULL && node->right == NULL) ? "lightcoral" : "lightgreen"; 
    fprintf(filestream, "\tnode%p[shape=Mrecord, style=\"rounded, filled\", fillcolor=\"%s\", "
                        "label=\"{%p | {%s} | {%p | %p}}\"]\n", 
                        node, fillcolor, node, node->value, node->left, node->right);

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


TreeError MakeHTML(const Tree *tree, FILE *html_file, int test_id) {
    assert(tree);
    assert(html_file);
    
    fprintf(html_file, "<pre>\n<hr>\n    <font size=\"10\"> ");
    fprintf(html_file, "TREE_DUMP\n");

    fprintf(html_file, "    Sort Tree : ");
    char* buffer = (char*)calloc(LONG_BUFFER_CONST, sizeof(char));
    PrintTree(tree->root, buffer);
    fprintf(html_file, "%s\n", buffer);
    fprintf(html_file, "\n");
    
    fprintf(html_file, "<img src=png/dump%d.png>\n", test_id);

    free(buffer);
    return TREE_NO_ERROR;
}


