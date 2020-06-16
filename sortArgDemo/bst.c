#include "malloc.h"
#include "bst.h"

BstNode *root = 0;

int bstStrcmp(char *a, char *b) /* return pos if string a > string b, 0 if equal, neg otherwise */
{
  while (*a && *b) {		/* until end of string */
    int diff = *a++ - *b++;
    if (diff) return diff;	/* differed within string */
  }
  if (!*a && !*b) return 0;	/* strings are same length & content */
  return (*a) ? 1 : -1;		/* a > b if a is longer */
}

int bstStrlen(char *s)
{
  char *sc = s;
  while (*sc++)
  return sc - s;
}



void
bstInsert(BstNode **rootp, char *str) 
{
  if (*rootp == 0) {		/* insert here */
    BstNode *newNode = malloc(sizeof(BstNode));
    for (int i = 0; i < 2; i++) newNode->children[i] = 0;
    /* copy first zero-terminated  string from inbuf */
    int len = bstStrlen(str), sindex = 0;
    char *scopy = malloc((len + 1) * sizeof(char)), c;
    do {	
      c = *(scopy+sindex) = *(str+sindex);
      sindex++;
    } while (c);
    newNode->str = scopy;
    *rootp = newNode;
  } else {
    int diff = bstStrcmp(str, (*rootp)->str);
    bstInsert(&((*rootp)->children[diff > 0 ? 1 : 0]), str);
  }
}

void
bstPrint(BstNode *root)		/* in order */
{
  if (root == 0) return;
  bstPrint(root->children[0]);
  puts(root->str); 
  bstPrint(root->children[1]);
}

void
bstClear(BstNode **rootp)
{
  if (*rootp == 0) return;
  for (int i = 0; i < 2; i++)
    bstClear(&(*rootp)->children[i]);
  free((*rootp)->str);
  free(*rootp);
  *rootp = 0;
}
