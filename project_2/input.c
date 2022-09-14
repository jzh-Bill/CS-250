#include <stdio.h>
#include <stdlib.h>
#define MAX 200

//This function is used to open file, then return fp.
FILE *open_file(char *file)
{
  
    FILE *fp;
    if ( (fp = fopen(file, "r")) == NULL )
    {
        printf("Fail to open file!");
        exit(0);
    }
    return fp;
}

//This function will withdraw whole line from text file.
char *pull_out_string(FILE *f)
{
    static char strr_text[MAX - 1];

    fgets(strr_text, 200, f);

    return strr_text;
}

//This function will filter all pair characters from discarded chars
char input_function(char first_pair_left, char first_pair_right, char second_pair_left, char second_right_pair,char cstring[])
{
   static int index = 0;
    while(cstring[index] != '\0')
    {
        if(cstring[index] == first_pair_left)
        {
            index++;
            return cstring[index-1];
        }
        if(cstring[index] == first_pair_right)
        {
            index++;
            return cstring[index-1];
        }
        if(cstring[index] == second_pair_left)
        {
            index++;
            return cstring[index-1];
        }
        if(cstring[index] == second_right_pair)
        {
            index++;
            return cstring[index-1];
        }
        index++;
    }
    return EOF;
}
