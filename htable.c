#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "container.h"
#include "mylib.h"
#include "string.h"
#define ArraySize 3877
//In here go any functions that can be called
struct hashTablerec{
	container containerArray[ArraySize];

};

hashTable createNewTable(int typeString){
	printf("declearing new hash table\n");
	hashTable result=emalloc(sizeof(result));
	int counter=0;
	if(typeString==1){
		while(counter<ArraySize){
			printf("creating flex table\n");
			result->containerArray[counter]=container_new();
			counter++;
		}	
	}else if(typeString==0){
		while(counter<ArraySize){
			printf("creating new RBT table\n");
			result->containerArray[counter]=container_new_rbt();
			counter++;
		}
	}else{
		fprintf(stderr,"There was a problem identifying container types");
	}
	return result;
	
}
void compareTable(){

}
void exitTable(hashTable *c){
	int countero=0;
	while(countero<ArraySize){
		printf("freeing tables\n");
		/*free(c->containerArray[countero]);*/
		countero++;
	}
}
