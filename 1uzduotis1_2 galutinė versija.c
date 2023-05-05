
/*
Program expects an integer value. Insertion of two equal integer values
will terminate the program. The program then shows how many zeros,
positive and negative numbers have been entered
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	int last;
	int temp;
	int number_count = 0;
	int negative_count = 0;
	int positive_count = 0;
	int null_count = 0;
	printf("Write an integer value.\n");
	while(last != number || getchar() != '\n')
	{
	    number = last;
	    temp = scanf ("%d", &last);
	    if (temp == 1)
	    {
		    number_count++;
		    if (last == 0) null_count++;
		    else if(last > 0) positive_count++;
		    else negative_count++;
	    } 
		else 
		{	
			printf ("Value you have entered is invalid. Try again.\n");
		    last = number;
		}
	    
	}
	printf("Cycle has ended.\n");
	printf("number_count: %d\n", number_count);
	printf("null_count: %d\n", null_count);
	printf("positive_count: %d\n", positive_count);
	printf("negative_count: %d\n", negative_count);
	return 0;
}