#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#define HASH_SIZE 3877



int returnStringValue(char *wordinput){
	int total=0;
	int wordCounter=0;
	while(wordinput[wordCounter]!='\0'){
		total=total+(wordinput[wordCounter]+0);
		wordCounter++;
	}
	return total;

}








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
