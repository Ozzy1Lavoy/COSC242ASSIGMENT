#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "flexarray.h"
//In here go any functions that can be called
struct containerrec {
	container_t type;
	void *contents;
};
container container_new(){
	container result=emalloc(sizeof(result));
		result->type=FLEX_ARRAY;
	return result;
}
container container_new_rbt(){
	container result=emalloc(sizeof(result));
		result->type=RED_BLACK_TREE;
	return result;
}
void container_add(container c, char *word) {
/*
	c->contents=erealloc(c->contents,(sizeof(c->contents)+sizeof(*word)));
	if (c->type == RED_BLACK_TREE) {
		c->contents = rbt_insert(c->contents, word);
	}else {
		flexarray_append(c->contents, word);
	}
	*/
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

