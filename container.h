#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <stddef.h>
//External calls to functions in a .c class go here
//Example:
//extern void *emalloc(size_t);
typedef enum container_c {FLEX_ARRAY, RED_BLACK_TREE} container_t;
typedef struct containerrec *container;
extern container container_new();
extern container container_new_rbt();
extern int container_add(container c, char *word);
extern int container_check(container c, char *word);

#endif
