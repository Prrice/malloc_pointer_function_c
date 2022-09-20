#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[] = "this is   a test  only - just a test";
char *ptr1[100], *ptr2[100];

int main(){
	function1();
	function2();

	return 0;
}

void function1(){
	char *temp = strtok(str, " ");
	int counter = 0;

	while(temp != NULL){
		ptr1[counter] = temp;
		temp = strtok(NULL, " ");
		counter++;
	}
}

void function2(){
	int counter = 0;

	while (ptr1[counter] != NULL){
		printf("%s\n", ptr1[counter]);
		counter++;
	}

	counter = 0;
	while (ptr1[counter] != NULL){
		ptr2[counter] = (char*) malloc(sizeof ptr1[counter]);
		char *tempPtr1 = ptr1[counter];
		char *tempPtr2 = ptr2[counter];

		if(!ptr2[counter]){
			exit(-1);
		}

		int counter2 = 0;
		while(tempPtr1[counter2] != '\0'){
			tempPtr2[counter2] = tempPtr1[counter2];
			printf("%c", tempPtr2[counter2]);
			counter2++;
		}

		printf("\n");
		counter++;
	}

	counter = 0;
	while (ptr2[counter] != NULL){
		printf("%p\n", (void*)ptr1[counter]);
		printf("%p\n", (void*)ptr2[counter]);
		free(ptr2[counter]);
		counter++;
	}
}
