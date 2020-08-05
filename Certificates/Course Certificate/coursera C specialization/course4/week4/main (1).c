/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

/*
 * Walking the Walk Programming Assignment
 */
int main(int argc, char** argv)
{
	// IMPORTANT: Only add code in the section
	// indicated below. The code I've provided
	// makes your solution work with the 
	// automated grader on Coursera
	char input[MAX_LENGTH];
	fgets(input, MAX_LENGTH, stdin);
	while (input[0] != 'q')
	{
		int n = atoi(input);

		int* ptr; 
		
		ptr = (int*)malloc(n * sizeof(int)); 
		
		if (ptr == NULL) 
		{ 
        	printf("Memory not allocated.\n"); 
        	exit(0); 
    	} 
    	else
		{
			int sum=0,i;
			for(i=0;i<n;i++)		
			{
				ptr[i]=i;
				sum+=i;
			}
			
			for(i=0;i<n;i++)		
			{
				printf("%d ",ptr[i]);		
			}
			printf("%d\n",sum);
			
		}


		// Don't add or modify any code below
		// this comment
		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}
