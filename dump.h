#ifndef DUMP_H
#define DUMP_H

#include <stdio.h>

#include "tree_types.h"


TreeError DumpCreateBase (Tree* tree, FILE *filestream);
TreeError DumpCreateNode(Node* node, FILE *filestream);
TreeError TreeDump(Tree *tree);


#endif //DUMP_H