#ifndef HTABLE_H_
#define HTABLE_H_
#include <stddef.h>

//External calls to functions in a .c class go here
//Example:
//extern void *emalloc(size_t);
typedef struct hashTablerec *hashTable;
extern hashTable createNewTable();
extern int compareTable(hashTable c, char *word);
extern void exitTable(hashTable c);
extern int addInto(hashTable c,char *word);

#endif
