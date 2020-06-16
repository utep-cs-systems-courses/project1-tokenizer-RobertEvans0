#include "stdio.h"

typedef struct BNode_s {
  struct BNode_s *children[2];
  char *str;
} BstNode;

BstNode *bstRoot;

void bstInsert(BstNode **rootp, char *str);
void bstPrint(BstNode *root);
void bstClear(BstNode **rootp);

