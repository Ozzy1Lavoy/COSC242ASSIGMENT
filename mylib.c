#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
//In here go any functions that can be called

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
