#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <math.h>
#include <string.h>

#include "tree_types.h"
#include "bin_tree.h"
#include "dump.h"
#include "akinator.h"

TreeError Akinator(Tree* tree) {

    if (tree == NULL || tree->root == NULL) {
        Node* root = NodeInit(strdup("nothing"), NULL, NULL);
        tree = TreeInit(1, root);
    }
    char play_again[BUFFER_CONST] = {};

    do {
        printf("Guess the object, and I'll try to guess!\n");
        printf("Answer YES or NO to my questions.\n\n");
        
        AkinatorFindNode(tree, tree->root);

        printf("\nPlay again? (YES/STOP): ");
        scanf("%s", play_again); // fgets? чтобы считывало ограниченное количество символов
        getchar();
        
    } while (strcmp(play_again, "STOP") != 0);

    printf("Thanks for playing\n");
    return TREE_NO_ERROR;
}

TreeError AkinatorCreateObject(Tree* tree, Node* current_node) {
    assert(current_node);
    assert(tree);

    char* new_object = (char*)calloc(BUFFER_CONST, sizeof(char));
    char* difference = (char*)calloc(BUFFER_CONST, sizeof(char));

    if (new_object == NULL || difference == NULL) {
        printf("Calloc error\n");
        return TREE_MEMORY_ERROR;

    }

    printf("Write down what you think of\n");
    scanf("%[^\n]", new_object);
    getchar();

    printf("What is the difference between a %s and a %s?\n", new_object, current_node->value);
    scanf("%[^\n]", difference);
    getchar();

    char* old_object = current_node->value; 

    current_node->value = difference;
    current_node->left  = NodeInit(new_object, NULL, NULL);
    current_node->right = NodeInit(old_object, NULL, NULL);
    tree->size += 2;

    printf("A new object has been added!\n\n");
    return TREE_NO_ERROR;

}

TreeError AkinatorFindNode(Tree* tree, Node* current_node) {
    assert(current_node);
    assert(tree);

    char user_answer[BUFFER_CONST] = {};    

    if (current_node->left == NULL && current_node->right == NULL) {
        printf("I think your object is %s\n", current_node->value);
        printf("Am I right?\n");
        scanf("%s", user_answer);
        getchar();

        if (strcmp(user_answer, "YES") == 0) {
            printf("Hooray!\n");
        } else {
            printf("ooops\n");
            AkinatorCreateObject(tree, current_node);
        }
    } else { // если не конец дерева
        printf("Did your object %s? (YES/NO): ", current_node->value);
        scanf("%s", user_answer);
        getchar();

        if (strcmp(user_answer, "YES") == 0) {
            AkinatorFindNode(tree, current_node->left);
        } else {
            AkinatorFindNode(tree, current_node->right);
        }
    }
    return TREE_NO_ERROR;
}


TreeError TreeSaveToFile(Tree* tree, const char* filename) {
    assert(tree);
    assert(filename);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return TREE_FILE_ERROR;
    }

    TreeError result = TreeSaveNodeToFile(tree->root, file);
    fclose(file);
    
    return result;
}

TreeError днTreeSaveNodeToFile(Node* node, FILE* filestream) {
    assert(filestream);
    if (node == NULL) {
        return TREE_NO_ERROR;
    }

    fprintf(filestream, "(");
    fprintf(filestream, "%s", node->value);
    
    if (node->left != NULL) {
        fprintf(filestream, " ");
        TreeSaveNodeToFile(node->left, filestream);
    }
    
    if (node->right != NULL) {
        fprintf(filestream, " ");
        TreeSaveNodeToFile(node->right, filestream);
    }
    
    fprintf(filestream, ")");
    
    return TREE_NO_ERROR;
}











































































































// size_t CountNodes(Node* node) {
//     if (node == NULL) {
//         return 0;
//     }
//     return 1 + CountNodes(node->left) + CountNodes(node->right);
// }

// TreeError TreeLoadFromString(Tree* tree, const char* str) {
//     assert(tree);
//     assert(str);

//     const char* str_ptr = str; // норм const?
//     tree->root = NodeLoadFromString(&str_ptr);
    
//     if (tree->root == NULL) {
//         printf("Read file error\n");
//         return TREE_FILE_ERROR;
//     }

//     tree->size = CountNodes(tree->root);
    
//     return TREE_NO_ERROR;
// }

// Node* NodeLoadFromString(const char** str_ptr) {
//     assert(str_ptr);
    
//     while (**str_ptr == ' ' || **str_ptr == '\n') {
//         (*str_ptr)++;
//     }
    
//     (*str_ptr)++; //пропускаем (
    
//     while (**str_ptr == ' ' || **str_ptr == '\n') {
//         (*str_ptr)++;
//     }
    
//     // Читаем название узла
//     const char* name_start = *str_ptr;
//     size_t name_len = 0;
    
//     // Читаем пока не встретим пробел, закрывающую скобку или конец
//     while (**str_ptr != ' ' && **str_ptr != ')' && **str_ptr != '\0') {
//         (*str_ptr)++;
//         name_len++;
//     }
    
//     if (name_len == 0) {
//         return NULL; // Пустое название
//     }
    
//     // Копируем название
//     char* name = (char*)malloc(name_len + 1);
//     if (name == NULL) {
//         return NULL;
//     }
//     strncpy(name, name_start, name_len);
//     name[name_len] = '\0';
    
//     Node* node = NodeInit(name, NULL, NULL);
//     if (node == NULL) {
//         free(name);
//         return NULL;
//     }
    
//     // Пропускаем пробелы после названия
//     while (**str_ptr == ' ' || **str_ptr == '\n' || **str_ptr == '\t') {
//         (*str_ptr)++;
//     }
    
//     // Рекурсивно читаем левого и правого потомка
//     if (**str_ptr == '(') {
//         node->left = NodeLoadFromString(str_ptr);
//     }
    
//     // Пропускаем пробелы между потомками
//     while (**str_ptr == ' ' || **str_ptr == '\n' || **str_ptr == '\t') {
//         (*str_ptr)++;
//     }
    
//     if (**str_ptr == '(') {
//         node->right = NodeLoadFromString(str_ptr);
//     }
    
//     // Пропускаем пробелы перед закрывающей скобкой
//     while (**str_ptr == ' ' || **str_ptr == '\n' || **str_ptr == '\t') {
//         (*str_ptr)++;
//     }
    
//     // Проверяем закрывающую скобку
//     if (**str_ptr != ')') {
//         NodeDestroy(node);
//         return NULL;
//     }
//     (*str_ptr)++; // Пропускаем ")"
    
//     return node;
// }



// ЧТЕНИЕ УЗЛА(POS)
//     ЕСЛИ POS существует "("
//         СОЗДАТЬ УЗЕЛ
//         POS++//сдвинуть указатель к названию узла
//         ЧТЕНИЕ НАЗВАНИЯ И ЗАПИСЬ В УЗЕЛ
//         POS+=LEN(НАЗВАНИЕ) // пропустить название
//         current_node->left = ЧТЕНИЕ УЗЛА(POS)
//         current_node->right = ЧТЕНИЕ УЗЛА(POS)
//         POS++//пропускаем )
//         RETURN УЗЕЛ
//         EСЛИ POS == nill
//             POS++
//             RETURN NULL

