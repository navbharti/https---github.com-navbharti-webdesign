/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/*
 * Junior Codebreaker Programming Assignment
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
		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed
		
		int len=strlen(input),i=0;
		for(i=0; input[i]!='\0'; i++)
    	{
    		if(isalpha(input[i]))
    			input[i]=tolower(input[i]);
    	}
    	
//    	printf("%s",input);
    	
    	int count[26];
    	
		for(i=0; i<26; i++)
    	{
    		count[i]=0;
    	}
    	
    	for(i=0; input[i]!='\0'; i++)
    	{
    		switch(input[i])
    		{
    			case 'a':
    				count[0]+=1;
    				break;
    				
    			case 'b':
    				count[1]+=1;
    				break;
    				
    			case 'c':
    				count[2]+=1;
    				break;
    				
    			case 'd':
    				count[3]+=1;
    				break;
    				
    			case 'e':
    				count[4]+=1;
    				break;
    				
    			case 'f':
    				count[5]+=1;
    				break;
    				
    			case 'g':
    				count[6]+=1;
    				break;
    				
    			case 'h':
    				count[7]+=1;
    				break;
    				
    			case 'i':
    				count[8]+=1;
    				break;
    				
    			case 'j':
    				count[9]+=1;
    				break;
    				
    			case 'k':
    				count[10]+=1;
    				break;
    				
    			case 'l':
    				count[11]+=1;
    				break;

    			case 'm':
    				count[12]+=1;
    				break;
    				
    			case 'n':
    				count[13]+=1;
    				break;
    				
    			case 'o':
    				count[14]+=1;
    				break;
    				
    			case 'p':
    				count[15]+=1;
    				break;
    				
    			case 'q':
    				count[16]+=1;
    				break;
    				
    			case 'r':
    				count[17]+=1;
    				break;
    			case 's':
    				count[18]+=1;
    				break;
    				
    			case 't':
    				count[19]+=1;
    				break;
    				
    			case 'u':
    				count[20]+=1;
    				break;
    				
    			case 'v':
    				count[21]+=1;
    				break;
    				
    			case 'w':
    				count[22]+=1;
    				break;
    				
    			case 'x':
    				count[23]+=1;
    				break;

    			case 'y':
    				count[24]+=1;
    				break;
    				
    			case 'z':
    				count[25]+=1;
    				break;
				
				default:
					break;    			 			
			}
    	}
    	
    	for(i=0; i<26; i++)
    	{
    		if(count[i]!=0)
    		{
    			printf("%c%d ",i+65,count[i]);
			}
		}
		printf("\n");
//    	printf("%d %d",count[0],count[1]);
    	
		// Don't add or modify any code below
		// this comment
		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}
