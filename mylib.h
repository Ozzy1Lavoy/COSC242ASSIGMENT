#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>
extern int returnStringValue(char *wordinput);
extern void *emalloc(size_t s);
extern void efree(void *c);
extern void *erealloc(void *array, size_t s); 
extern int checkNumbers(char *checkedString); 
#endif
