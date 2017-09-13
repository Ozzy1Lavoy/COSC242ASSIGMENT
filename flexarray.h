#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern void *flexarray_append(void **wordArray, char *string);
extern void flexarray_free(flexarray f);
extern flexarray flexarray_new();
extern void flexarray_print(void **wordArray);
extern void flexarray_sort(flexarray f);
extern int is_present(flexarray f, char *string);
extern void visit();

#endif
