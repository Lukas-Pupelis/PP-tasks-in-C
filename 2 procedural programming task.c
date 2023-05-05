#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *S)
{
    printf("Result is %d", *S);
}

void count(int N, int a[], int* S, int xCount, int yCount)
{
    int x[xCount];
    int y[yCount];
    int swapTemp = 0;
    int p = 0;

    for (int i = 0; i < N-1; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (a[i] > a[j])
            {
                swapTemp = a[i];
                a[i] = a[j];
                a[j] = swapTemp;
            }
        }
    }

    for(int i = 0; i < xCount; ++i)
    {
        x[i] = a[i];
    }

    for(int i = xCount; i < N; ++i)
    {
        y[i-xCount] = a[i];
    }

    if (xCount < yCount)
    {
        p = xCount;
    }
    else
        p = yCount;

    for(int i = 0; i < p; ++i)
    {
        *S += (x[i]*y[i]);
    }
}

void scan_elements(int N, int a[], int *xCount, int *yCount)
{
    char c;
    int temp;
    int input;
    *xCount = 0;
    *yCount = 0;

    printf("Enter %d integers.\n", N);

    for(int i = 0; i < N; ++i)
    {
        temp = scanf("%d", &input);

        if(temp == 1 || getchar() != '\n')
        {
            a[i] = input;
        }

        else
        {
            printf("Value you have entered is invalid, try again.\n");
            i--;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if(a[i] < 0)
        {
            ++*xCount;
        }
        else
        {
            ++*yCount;
        }

    }

    if(*xCount == N)
    {
        printf("All members of array are negative.\n");
        exit(0);
    }

    if(*yCount == N)
    {
        printf("All members of array are not negative.\n");
        exit(0);
    }
}

void scan_size(int* N)
{   
    int temp;
    char c;

    printf("Enter the size of array (an integer positive value).\n");

    while(*N <= 0)
    {   
        temp = scanf("%d", N);
        
        // checks if N is valid
        if (temp == 1 && *N > 0 || getchar() != '\n')
        {
            // Consume any extra input characters, if any
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else
        {
            printf("Value you have entered is invalid, try again.\n");
        }    
    }
    printf("Size of array scanned succesfully.\n");
}

int main()
{
    int N = 0;
    int *a;
    int S = 0;
    int xCount = 0;
    int yCount = 0;

    scan_size(&N);

    // Dynamically allocate memory for array 'a'
    a = (int*) malloc(N * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    scan_elements(N, a, &xCount, &yCount);
    count(N, a, &S, xCount, yCount);
    print(&S);

    // Free dynamically allocated memory
    free(a);

    return 0;
}
