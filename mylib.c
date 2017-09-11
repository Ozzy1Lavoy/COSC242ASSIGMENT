#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
/*In here go any functions that can be called*/

/*
returnStringValue takes a character index(String) and returns the
total integer value of each character
Define: *wordinput- the word being tottaled
*/
int returnStringValue(char *wordinput){
	int total=0;
	int wordCounter=0;
	while(wordinput[wordCounter]!='\0'){
		total=total+(wordinput[wordCounter]+0);
		wordCounter++;
	}
	return total;

}
void *emalloc(size_t s) {
	void *result = malloc(s);
	if (NULL == result) {
		fprintf(stderr, "Error Allocating memory. Problem==lots. Exiting... \n");
		exit(EXIT_FAILURE);
	}
	return result;
}
void efree(void *c){
	free(c);
	return;
}
void *erealloc(void *array, size_t s){
	void *result=realloc(array,s);
	if(result==NULL){
		fprintf(stderr,"Error Reallocating memory. Problem==lots. Exiting...\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout,"sucsessfully reallocated memory\n");
	return result;
}
int checkNumbers(char *checkedString){
	int checkCounter=0;
	while(checkedString[checkCounter]!='\0'){
		if(!((checkedString[checkCounter]>('1'-1))&&(checkedString[checkCounter]<('9'+1)))){
			return 0;
		}
		checkCounter++;
	}
	return 1;
	

}
