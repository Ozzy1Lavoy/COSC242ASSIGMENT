#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"mylib.h"
#define HASH_SIZE 3877
/*
Asher And Oscar 6/09/2017,
Main creates a Hashtable that has a set ammount of container objects,
each container object stores each string with that integer value 

*/
int main(int argc,char **argv){
	int enteredWords=0;
	char *word;
	int result=0;
	int argCounter=0;
	word=malloc(60 * sizeof(word[0]));
	if(argc>1){
		fprintf(stderr,"there is input");
		while(argCounter<argc){
			if(strcmp(argv[argCounter],"-r")==0){
				printf("function called");
			}
			argCounter++;
		}
	
	
	}else{
	printf("there is no inputs\n");
		while(scanf("%59s",word)==1&&(enteredWords<5)){
		result=returnStringValue(word);
			printf("result : %d\n",result);
			enteredWords++;
		}
	
	}
	return 1;

}
