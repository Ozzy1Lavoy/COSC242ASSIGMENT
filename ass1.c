#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"mylib.h"
#include "htable.h"
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
	word=emalloc(60 * sizeof(word[0]));
	if(argc>1){
		fprintf(stderr,"there is input\n");
		while(argCounter<argc){
			if(strcmp(argv[argCounter],"-r")==0){
				printf("robust function called\n");
			}
			if(strcmp(argv[argCounter],"-p")==0){
				printf("print function called\n");
			}
			if(strcmp(argv[argCounter],"-s")==0){
				if((argCounter+1>=argc)){
					fprintf(stderr,"-s requires input after\n");
				}
				else if(checkNumbers(argv[argCounter+1])!=1){
					fprintf(stderr,"-s requires and integer above 0 after\n");
				}
				else{
					printf("table size function called with size %s\n",argv[argCounter+1]);
					argCounter++;
				}
				
			}
			if(strcmp(argv[argCounter],"-i")==0){
				printf("information function called\n");
			}
			if(strcmp(argv[argCounter],"-h")==0){
				fprintf(stderr,"this is the hash table appplication.\n");
				fprintf(stderr,"here are the commands: \n\n'-r' > run the applciation with the containers having a robust RBT");
				fprintf(stderr,"layout\n\n'-s ,tablesize' > run the applciation with a hash table size of 'tablesize', 'tablesize'");
				fprintf(stderr,"must be greater than 0\n\n'-p' > print every non-empty container with index");
				fprintf(stderr," from the read file. Do not compare with stdin \n\n'-i' > print information (to stderr)");
				fprintf(stderr,"about how long it took to fill the hash table,\nhow long it took to search the hash table,and ");
				fprintf(stderr,"how many unknown words were found like this:\n");
				fprintf(stderr,"Fill time :  1.390000 \nSearch time :  0.450000  \nUnknown words :  8690");
				fprintf(stderr,"\n\n'-h' > Ask for help. You probably alredy know this one\n");
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
		word=erealloc( word,70 * sizeof( word[0]) );
		
	
	}
	efree(word);
	hashTable cool=createNewTable(1);
	exitTable(&cool);
	return 1;

}
