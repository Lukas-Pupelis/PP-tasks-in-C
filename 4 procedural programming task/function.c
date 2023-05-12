#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h" 
void getValidOption(int *optionNumber)
{
    int inputCount;
    char character;

    while(1)
    {
        inputCount = scanf("%d%c", optionNumber, &character);

        if ((inputCount == 2) && (character == '\n') && (*optionNumber <= 3) && (*optionNumber >= 0))
        {
            break;
        }
        else if ((inputCount == 2) && (character == '\n'))
        {
            printf("A number must be between 0 and 3. Try again \n");
        }
        else
        {
            printf("Invalid input, try again \n");
            while(character != '\n')
            {
                character = getchar();
            }
        }
    }
}

void readFromFile(FILE **filePointer, List **head)
{
    int number;
    char *string = calloc(255, sizeof(char)), *text;;
    char *word;


    while (fgets(string, 255, *filePointer) != NULL)
    {
        word = strtok(string, " \n");

        if (word != NULL)
        {
            if (strspn(word, "0123456789") == strlen(word))
            {
                number = atoi(word);
                makeNewListElement(head, number);
            }
            else if (word[0] == '-')
            {
                if (strspn(word, "-0123456789") == strlen(word))
                {
                    number = atoi(word);
                    makeNewListElement(head, number);
                }
            }
        }
            
        do
        {
            word = strtok(NULL, " \n");

            if(word != NULL)
            {
                if (strspn(word, "0123456789") == strlen(word))
                {
                    number = atoi(word);
                    makeNewListElement(head, number);
                }
                else if (word[0] == '-')
                {
                    if (strspn(word, "-0123456789") == strlen(word))
                    {
                        number = atoi(word);
                        makeNewListElement(head, number);
                    }
                }
            }

        } while (word != NULL);
    }
}

void makeNewListElement(List **head, int number)
{   
    List *newElement = (List*) malloc(sizeof(List));
    List *currentElement = *head;

    newElement->element = number;
    newElement->next = NULL;

    while((currentElement != NULL) && (currentElement->next != NULL))
    {
        currentElement = currentElement->next;
    }

    if (currentElement != NULL)
    {
        currentElement->next = newElement;
    }
    else
    {
        *head = newElement;
    }
}

void printList(List *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d ", head->element);

    printList(head->next);
}

void insertBefore(int *number, int *value, List *head) 
{
  List *currentElement = head;
  List *newElement = NULL;
  getValidInteger(&number);
  
  while (currentElement -> next -> element != value) 
  {
    currentElement = currentElement -> next;
  }
  
  newElement = (List*) malloc(sizeof(List));
  newElement -> element = number;
  newElement -> next = currentElement -> next;
  currentElement -> next = newElement;
}

void getValidInteger(int *value)
{
    int inputCount;
    char character;

    while(1)
    {
        inputCount = scanf("%d%c", value, &character);

        if ((inputCount == 2) && (character == '\n'))
        {
            break;
        }
        else
        {
            printf("Invalid input, try again \n");
            while(character != '\n')
            {
                character = getchar();
            }
        }
    }
}
