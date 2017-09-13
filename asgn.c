#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<getopt.h>
#include"mylib.h"
#include "htable.h"
/*
Asher And Oscar 6/09/2017,
Main creates a Hashtable that has a set ammount of container objects,
each container object stores each string with that integer value 

*/
int main(int argc,char **argv){
	FILE *infile;
	int enteredWords=0;
	char *word;
	char *inputWord;
	char **wordArray;
	int result=0;
	int argCounter=1;
	int counter=0;
	int sizeOfInput=1;
	int robust=0;
	word=emalloc(60 * sizeof(word[0]));
	inputWord=emalloc(60 * sizeof(word[0]));
	wordArray=emalloc(sizeOfInput * sizeof(wordArray[0][0]));
	hashTable cool;
	
	/*
	
	
	
	
	
	
	*/
	
	const char *optstring = "rps:hi";
	char option;
	while ((option = getopt(argc, argv, optstring)) != EOF) {
		switch (option) {
			case 'r':
				printf("robust function called\n");
				robust=1;
				cool=createNewTable(0);
				break;
				
			case 'p':
				printf("print function called\n");
				break;
				
			case 's':
				if(!(checkNumbers(optarg)>1)){
					fprintf(stderr,"-s requires and integer above 0 after\n");
				}
				else{
					printf("table size function called with size %s\n",optarg);
				}
				break;
			case 'h':
				fprintf(stderr,"this is the hash table appplication.\n");
				fprintf(stderr,"here are the commands: \n\n'-r' > run the applciation with the containers having a robust RBT");
				fprintf(stderr,"layout\n\n'-s ,tablesize' > run the applciation with a hash table size of 'tablesize', 'tablesize'");
				fprintf(stderr,"must be greater than 0\n\n'-p' > print every non-empty container with index");
				fprintf(stderr," from the read file. Do not compare with stdin \n\n'-i' > print information (to stderr)");
				fprintf(stderr,"about how long it took to fill the hash table,\nhow long it took to search the hash table,and ");
				fprintf(stderr,"how many unknown words were found like this:\n");
				fprintf(stderr,"Fill time :  1.390000 \nSearch time :  0.450000  \nUnknown words :  8690");
				fprintf(stderr,"\n\n'-h' > Ask for help. You probably alredy know this one\n");
				break;
			case 'i':
				fprintf(stderr,"print info on table\n");	
				break;
			default:
				
				break;
			/* if an unknown option is given */
		}
	}
	
	
	
	/*
	
	
	
	
	
	
	
	
	*/
	if(!(robust==1)){
		cool=createNewTable(1);
	}
	if(optind>0){
		if (NULL == (infile = fopen(argv[optind], "r"))) {
						fprintf(stderr, "%s: Cant open the File %s or it isn't a valid command\n", argv[0],argv[optind]);
						efree(word);
						exitTable(&cool);
						return EXIT_FAILURE;
		}
		printf("opened %s\n",argv[optind]);
		/*while((counter<sizeOfInput) && (fscanf(infile,"%s",inputWord))==1){
			if((sizeOfInput)==(counter+1)){
					sizeOfInput=(sizeOfInput*2);
					wordArray=erealloc(wordArray,sizeOfInput*sizeof(wordArray[0]));
				}
			wordArray[counter]=emalloc(sizeof(inputWord)+1);
			printf("putting %s in %d\n",inputWord,counter);
			addInto(&cool,inputWord);
			strcpy(wordArray[counter],inputWord);
			counter++;
		}*/
		while((fscanf(infile,"%s",inputWord))==1){
			printf("putting %s in %d\n",inputWord,counter);
			addInto(&cool,inputWord);
		}
		fclose(infile);	
		
	}
	while(scanf("%59s",word)==1){
			result=returnStringValue(word);
			printf("result : %s had  a hash key of %d\n",word,result);
			enteredWords++;
	}
	word=erealloc( word,70 * sizeof( word[0]) );
	printf("freeing inputWord\n");
	efree(word);
	efree(inputWord);
	counter=0;
	while(counter<sizeOfInput){
		printf("freeing wordArray %d\n",counter);
		efree(wordArray[counter]);
		counter++;
	}
	exitTable(&cool);
	return 1;

}
/*

/*if (NULL == (infile = fopen(fscanf(stdin,"%s",inputfilelocation), "r"))) {
			fprintf(stderr, "%s: Cant open the File %s or it isn't a valid command\n", argv[0],inputfilelocation);
					efree(inputWord);
					efree(inputfilelocation);
					efree(word);
					exitTable(&cool);
					return EXIT_FAILURE;
	}
	while(fscanf(infile,"%s",inputWord)==1){
			fprintf(stdout,"printing %s\n",inputWord);
				
	}
	fclose(infile);
	*/
