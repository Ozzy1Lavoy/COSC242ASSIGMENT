#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "flexarray.h"
#include "mylib.h"
//In here go any functions that can be called
struct containerrec {
	container_t type;
	void *contents;
};
container container_new(){
		container result=emalloc(sizeof(result)+(2*sizeof(result->contents[0])));
		result->type=FLEX_ARRAY;
	return result;
}
container container_new_rbt(){

	container result=emalloc(sizeof(result));
		result->type=RED_BLACK_TREE;
		
	return result;
}

int container_add(container c, char *word) {
	c->contents=erealloc(c->contents,(sizeof(c->contents)+(2 *sizeof(c->contents[0]))));
	int Maxcontents=(sizeof(c->contents)/sizeof(c->contents[0]))-1;
	if (c->type != RED_BLACK_TREE) {
		c->contents=flexarray_append(c->contents, word);
		return 1;
	}/*else {
		c->contents = rbt_insert(c->contents, word);
		return 1;
	}*/
}
int container_check(container c, char *word) {
/*
	if (c->type == RED_BLACK_TREE) {
		c->contents = rbt_getWord(c->contents, word);
	}else {
		flexarray_getWord(c->contents, word);
	}
	*/
}

