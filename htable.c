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
		while((counter<ArraySize)){
			/*printf("creating flex table\n");*/
			result->containerArray[counter]=container_new();
			counter++;
		}	
	}/*else if(typeString==0){
		while(counter<(ArraySize)){
			printf("creating new RBT table\n");
			result->containerArray[counter]=container_new_rbt();
			counter++;
		}
	}*/else{
		fprintf(stderr,"There was a problem identifying container types");
	}
	return result;
	
}
int compareTable(hashTable d,char *word){
	int keyPlace=returnStringValue(word);
	if(keyPlace<(ArraySize-1)){
		return container_check(d->containerArray[keyPlace],word);
	}else{
		return container_check(d->containerArray[ArraySize-1],word);
	}

}
void exitTable(hashTable c){
	int countero=0;
	while(countero<ArraySize){
		countero++;
	}
}
int addInto(hashTable c,char *wordInput){
	int keyPlace=returnStringValue(wordInput);
	if(keyPlace<(ArraySize-1)){
		c->containerArray[keyPlace]=erealloc(c->containerArray[keyPlace],(sizeof(c->containerArray[keyPlace])+(2*sizeof(c->containerArray[0]))));
		if((container_add(c->containerArray[keyPlace],wordInput))!=1){
			fprintf(stderr,"error adding word");
			exit(EXIT_FAILURE);
		}
	}
	else if(keyPlace>=(ArraySize-1)){
		int a=ArraySize-1;
			c->containerArray[a]=erealloc(c->containerArray[a],((sizeof(c->containerArray[a]))+(2*sizeof(c->containerArray[0]))));
			if(1!=(container_add(c->containerArray[a],wordInput))){
				fprintf(stderr,"error adding word");
				exit(EXIT_FAILURE);
			}
			
	}else{
		fprintf(stderr,"unexcpected Error trying to place converted word into hashtable"); 
	}


}
