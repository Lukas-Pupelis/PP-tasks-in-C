/*  
Changing digits of a word to the last letter of a word
Words are taken as input from a .txt file and outputed to another .txt file
for example: he11o -> heooo 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* getInput();
FILE* openFile(char* mode);
char* readFromFile(FILE* file);
void printToFile(FILE* file, char** data, unsigned* size);

int main()
{
    printf("Enter data file name.\n");
    FILE* rf = openFile("r");

    printf("Enter result file name.\n");
    FILE* wf = openFile("w");

    char** data = malloc(255 * sizeof(char*));
    unsigned dataSize = 0;
    char* buffer;
	buffer = malloc(255*sizeof(char*));
	
	while(feof(rf) == 0)
    {
        buffer = readFromFile(rf);

        if(buffer != NULL)
        {
            ++dataSize;
            data = realloc(data, (dataSize)*sizeof(char*));
            data[dataSize-1] = malloc(strlen(buffer)+1); 
            strcpy(data[dataSize-1], buffer);
        }
    }

    printToFile(wf, data, &dataSize);
	
    free(data);
	free(buffer);
	
	fclose(rf);
	fclose(wf);
	return 0;
}

char* getInput()
{
    char c = 0;
    int i = 0;
    char* str = malloc(255 * sizeof(char*));

    if(str == NULL) 
    {
        printf("Error: could not locate memory.\n");
        return NULL;
    }
	
	while(1)
    {
        c = getchar();
        if(c != '\n')
        {
            str[i] = c;
            ++i;
        }
        else
        {
            str[i] = '\0';
            break;
        }
    }
    return str;
}

FILE* openFile(char* mode)
{
    FILE* file;
    char* name;

    while(1)
    {
        name = getInput();
        file = fopen(name, mode);

        if(file != NULL)
        {
            break;
        }
        else
        {
            printf("Please enter a valid file name.\n");
        }
    }

    return file;
}

char *readFromFile(FILE* file)
{
    char c = 0;
    int i = 0;
    char* word;
    char characters[256] = {};
	char number;
    word = malloc(255*sizeof(char*));
    c = fgetc(file);

    while(1)
    {
			if((c == ' ') || (c == '\n') || (feof(file) != 0))
			{ 										
				if (i > 1)
				{
					if(isalpha(characters[i-1]) != 0)
					{	
						for(int j = 0; j < i-1; ++j)
						{	
							for(char k = 48; k < 58; ++k)
							{
								if (characters[j] == k)
								{
									characters[j] = characters[i-1];
								}								
							}
						}
					}
					strcpy(word,characters);
												
					return word;
				}
				else return NULL;
			}
			else
			{	
				characters[i] = c;
				++i;	
			}	
			c = fgetc(file);
	}			
}

void printToFile(FILE* file, char** data, unsigned* size)
{
    for(int i = 0; i < *size; ++i)
    {
		fprintf(file, "%s ", data[i]);
    }

}