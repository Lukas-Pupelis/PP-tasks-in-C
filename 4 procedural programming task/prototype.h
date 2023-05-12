#ifndef HEADER_FILE
#define HEADER_FILE 
#include <stdio.h>

typedef struct LinkedList
{
    int element;
    struct LinkedList *next;
} List;

void getValidOption(int *optionNumber);
void readFromFile(FILE **filePointer, List **head);
void makeNewListElement(List **head, int number);
void printList(List *head);
void insertBefore(int *value, List **head);
void getValidInteger(int *value);

#endif 	
	