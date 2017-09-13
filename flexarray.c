#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"
#include <string.h>

struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
};

static void insertion_sort(char **a, int n){
    int p, i;
    char *key;
    for (p = 1; p < n; p++){
        key = emalloc(strlen(a[p] + 1) * sizeof a[0][0]);
        key = a[p];
        for (i = p-1; i > -1; i--){
            if (strcmp(a[i], key) > 0){
                a[i+1] = a[i];
                a[i] = key;
            }else{
                break;
            }
        }
    }
}

static void quicksort(char **a, int n){
    int i, j;
    char *temp, *pivot;
    if (n < 2){
	return;
    }
    if (n < 40){
	insertion_sort(a, n);
	return;
    }
    pivot = a[0];
    i = -1;
    j = n;
    for (;;) {
	do {
	    i++;
	} while (strcmp(a[i], pivot) < 0);
	do {
	    j--;
	} while (strcmp(a[j], pivot) > 0);
        
        if (i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }
    quicksort(&a[0], j+1);
    quicksort(&a[j+1], n-j-1);
}


flexarray flexarray_new(){
    flexarray result = emalloc(sizeof *result);
    result -> capacity = 2;
    result -> itemcount = 0;
    result -> items = emalloc(result -> capacity * sizeof result -> items[0]);
    return result;
}

void *flexarray_append(void **wordArray, char *string){
	int capacity=(sizeof(wordArray)/sizeof(wordArray[0][0]));
    int itemcount=0;
    char **items;
    wordArray[capacity-1]=emalloc(sizeof(string)+1);
    strcpy(wordArray[capacity-1],string);
    return wordArray;
}

void flexarray_print(void **wordArray){
	int capacity=(sizeof(wordArray)/sizeof(wordArray[0][0]));
    int i;
    for (i = 0; i < capacity; i++){
		printf("%s\n",wordArray[i]);
    }
}

void flexarray_sort(flexarray f){
    quicksort(f->items, f->itemcount);
}

void flexarray_free(flexarray f){
    free(f);
}

int is_present(flexarray f, char *string){
    int i;
    if (f->itemcount == 0){
        return 0;
    }
    for(i = 0; i < f->itemcount; i++){
        if (strcmp(f->items[i], string) == 0){
            return 1;
        }
    }
    return 0;
}

void visit(flexarray f, void p(char *s)){
    int i;
    for (i = 0; i < f->itemcount; i++){
	p(f->items[i]);
    }
}
