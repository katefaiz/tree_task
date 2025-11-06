#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>

#include "tree_types.h"
#include "bin_tree.h"

TreeError PrintNode(const Node* node) {
    assert(node);

    printf("(");
    if (node->left) 
        PrintNode(node->left);
    printf("%d ", node->value);
    if (node->right) 
        PrintNode(node->right);
    printf(")");
    
    return TREE_NO_ERROR;
}

Node* NodeInit(TreeElem value, Node* left, Node* right) {

    Node* node = (Node*)calloc(1, sizeof(Node));
    if (node == NULL) {
        printf("Calloc error\n");
        return NULL;
    }
    node->left = left;
    node->right = right;
    node->value = value;


    return node;
}

Tree* TreeInit(size_t size, Node* root) {
    assert(root);
    Tree* tree = (Tree*)calloc(1, sizeof(Tree));
    if (tree == NULL) {
        printf("Calloc error\n");
        return NULL;
    }

    tree->root = root;
    tree->size = (root != NULL) ? size : 0;

    return tree;
}

TreeError NodeDestroy(Node* node) {
    if (node == NULL) {
        return TREE_NO_ERROR;
    }

    NodeDestroy(node->left);
    NodeDestroy(node->right);
    free(node);

    return TREE_NO_ERROR;
}

TreeError TreeDestroy(Tree* tree) {
    if (tree == NULL) {
        return TREE_NO_ERROR;
    }
    
    NodeDestroy(tree->root);
    free(tree);
    
    return TREE_NO_ERROR;
}

TreeError TreeInsertNode(Tree* tree, Node* node) {
    assert(tree);
    assert(node);

    if(tree->root == NULL) {
        tree->root = node;
        tree->size = 1;
        return TREE_NO_ERROR;
    }

    Node* current = tree->root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (node->value <= current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node->value <= parent->value) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    tree->size++;
    return TREE_NO_ERROR;
}
