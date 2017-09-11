#include<stdlib.h>
#include<stdio.h>
#include<getopt.h>
#include <string.h>
int main(int argc,char *argv){
	const char *optstring = "ab:c";
	char option;
	while ((option = getopt(argc, argv, optstring)) != EOF) {
		switch (option) {
			case 'a':
			printf("argument a \n");
			break;
			case 'b':
			/* the argument after the -b is available
			in the global variable ’optarg’ */
			printf("argument b with %s \n",optarg);
			break;
			case 'c':
			printf("argument c \n");
			break;
			default:
			printf("default\n");
			break;
			/* if an unknown option is given */
		}
	}
	return 1;

}
