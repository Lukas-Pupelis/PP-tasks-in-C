
#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"

void openMenu(List **head);
FILE* openFile();
char* getFileName();

int main()
{
    List *head = NULL;

    printf(
	"This program creates a singly linked list from integers in a given file and can insert a node "
	"before a node with a given value.\n");
    openMenu(&head);

    return 0;
}

void openMenu(List **head)
{
    int optionNumber;
	int value;
	int number;

    while(1)
    {
        printf ("\nChoose an option what you want this program to do by entering a number:\n");
        printf ("To create a list from a file: [0]\n");
        printf ("To print the created list: [1]\n");
        printf ("To insert a node before a node with a certain value: [2]\n");
        printf ("To exit the program: [3]\n");

        getValidOption(&optionNumber);

        switch(optionNumber)
        {
            case 0:
                printf ("To create a list, enter file name:\n");
                FILE *filePointer = openFile();
                readFromFile(&filePointer, head);
                goto repeat;
            case 1:
                printf("Printing the list:\n");
                printList(*head);
                goto repeat;
            case 2:
				printf("Enter value before whitch the node must be inserted: ");
				getValidInteger(&value);
				insertBefore(number, &value, head);
                printf("The node is inserted.\n");
                goto repeat;
            case 3:
                printf ("Exiting the program...\n");
                fclose(filePointer);
                exit(0);
        }

        repeat: ;
    }
}

FILE* openFile()
{
    FILE *file;
    char *name;

    while(1)
    {
        name = getFileName();
        file = fopen(name, "r");

        if(file != NULL)
        {
            break;
        }
        else
        {
            printf("Error while trying to open the file\n");
            printf("Please, enter a valid file:\n");
        }
    }

    return file;
}

char* getFileName()
{
    char character;
    int index = 0;
    char *name = malloc(255 * sizeof(char));
	
    while(1)
    {
        character = getchar();
        if(character != '\n')
        {
            name[index] = character;
            ++index;
        }
        else
        {
            name[index] = '\0';
            break;
        }
    }

    return name;
}


