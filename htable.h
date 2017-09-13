#ifndef HTABLE_H_
#define HTABLE_H_
#include <stddef.h>

//External calls to functions in a .c class go here
//Example:
//extern void *emalloc(size_t);
typedef struct hashTablerec *hashTable;
extern hashTable createNewTable();
extern void compareTable();
extern void exitTable(hashTable *c);

#endif
