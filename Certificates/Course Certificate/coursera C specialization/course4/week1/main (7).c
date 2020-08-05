/*
 * File:   main.c
 * Author: <CHERUKURI NARESH>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct Vector Vector;
struct Vector
{
	float x;
	float y;
	float z;
};

typedef struct MoveInfo MoveInfo;
struct MoveInfo
{
	Vector velocity;
	float duration;
};

// prototypes for suggested student-implemented functions
// uncomment the prototypes for the functions you implement
int countInputFileLines(char inputFileName[]);
void getPointFromString(char string[], Vector *point);
void getMoveInfoBetweenPoints(MoveInfo *moveInfo, Vector firstPoint, Vector secondPoint);

/*
 * I, Robot Programming Assignment
 */
int main(int argc, char** argv)
{
	// IMPORTANT: Only add code in the section
	// indicated below. The code I've provided
	// makes your solution work with the 
	// automated grader on Coursera
	char rawFileName[MAX_LENGTH];
	fgets(rawFileName, MAX_LENGTH, stdin);
	while (rawFileName[0] != 'q')
	{		
		int stringEndIndex = -1;
		char *result = NULL;
		char *stringStart = &rawFileName[0];

		// handle Windows, MacOS, and Linux
		// check for carriage return
		result = strchr(rawFileName, '\r');
		if (result == NULL)
		{
			// no carriage return found, so find new line
			result = strchr(rawFileName, '\n');
		}

		stringEndIndex = result - stringStart;
		char* inputFileName = malloc((stringEndIndex + 1) * sizeof(char));
		strncpy(inputFileName, rawFileName, stringEndIndex);
		inputFileName[stringEndIndex] = '\0';

		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed
		int lines=countInputFileLines(inputFileName);
		if(lines!=-1)
		{
			FILE *F = fopen(inputFileName,"r");
			int i = 0;
			char line[100000];
			Vector v[lines];
			while (i < lines)
			{
				fscanf(F, "\n%[^\n]\n", line);
				getPointFromString(line, &v[i]);
				i++;
			}
			fclose(F);
			lines--;
			MoveInfo mi[lines];
			float totalDist=0;
			for (i = 0; i < lines; i++)
			{
				//printf("%d %d\n",noLines-1,i);
				getMoveInfoBetweenPoints(&mi[i], v[i], v[i + 1]);
				totalDist += mi[i].duration;
				printf("%.2f,%.2f,%.2f,%.2f ", mi[i].velocity.x, mi[i].velocity.y, mi[i].velocity.z, mi[i].duration);
			}
			printf("%.2f\n",totalDist);
		}

		
		// Don't add or modify any code below
		// this comment except as indicated below
		free(inputFileName);
		inputFileName = NULL;
		fgets(rawFileName, MAX_LENGTH, stdin);
	}

	return 0;
}

// Add your function implementations between this 
// comment and the comment below. You can of course 
// add more space between the comments as needed
int countInputFileLines(char inputFileName[])
{
  	FILE* F = fopen(inputFileName, "r");
	char line[MAX_LENGTH];
	int n = 1;
	if (F == NULL)
	{
		return -1;
	}
	else
	{
		fscanf(F, "\n%[^\n]\n", line);
		while (!feof(F))
		{
			n++;
			fscanf(F, "\n%[^\n]\n", line);
		}
	}
	fclose(F);
	return n;
}
void getPointFromString(char string[], Vector *point)
{
	int commaIndex = strchr(string, ',') - string;
	char st[MAX_LENGTH];
	strncpy(st, string, commaIndex);
	st[commaIndex] = '\0';
	point->x = atof(st);

	string = string + commaIndex + 1;
	commaIndex = strchr(string, ',') - string;
	strncpy(st, string, commaIndex);
	st[commaIndex] = '\0';
	point->y = atof(st);

	string = string+commaIndex + 1;
	point->z = atof(string);
}

void getMoveInfoBetweenPoints(MoveInfo* moveInfo, Vector firstPoint, Vector secondPoint)
{
	float dx = secondPoint.x - firstPoint.x;
	float dy = secondPoint.y - firstPoint.y;
	float dz = secondPoint.z - firstPoint.z;
	moveInfo->duration = sqrt(powf(dx,2) + powf(dy,2) + powf(dz,2));
	moveInfo->velocity.x = dx / moveInfo->duration;
	moveInfo->velocity.y = dy / moveInfo->duration;
	moveInfo->velocity.z = dz / moveInfo->duration;
}
// Don't add or modify any code below this comment
