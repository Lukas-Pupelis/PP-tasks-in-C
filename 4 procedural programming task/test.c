#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "prototype.h"

void testMakeNewListElement(List **head);
void testPrintList(List *head);
void test

int main()
{
    List *head = NULL;
    printf ("This program tests list functions\n");

    testMakeNewListElement(&head);
    testPrintList(head);

    return 0;
}

void testMakeNewListElement(List **head)
{
    makeNewListElement(head, -7);
    assert((*head)->next == NULL);
    assert((*head)->element == -7);
    printf ("First element was inserted successfully\n");

    makeNewListElement(head, -42);
    assert((*head)->next != NULL);
    assert(((*head)->next)->next == NULL);
    assert(((*head)->next)->element == -42);
    printf ("Second element was inserted successfully\n");

    makeNewListElement(head, 2);
    assert(((*head)->next)->next != NULL);
    assert((((*head)->next)->next)->next == NULL);
    assert((((*head)->next)->next)->element == 2);
    printf ("Third element was inserted successfully\n");

    printf("Test with InsertNewListElement function passed successfully\n");
}

void testPrintList(List *head)
{
    printf("List is: ");
    printList(head);
    printf("\n");
}

