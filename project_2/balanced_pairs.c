#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "input.h"


int main(int argc, char * argv[])
{
    //This is the file open function.
    FILE *f = open_file(argv[1]);

    //Delcare 4 variables to store 2 pairs.
    char first_pair_one;
    char first_pair_two;


    char second_pair_one;
    char second_pair_two;

    //input the 4 pair characters
    printf("Please enter first pair of characters: ");
    first_pair_one = getchar();
    first_pair_two = getchar();

    char dummy = getchar();

    printf("Please enter first pair of characters: ");
    second_pair_one = getchar();
    second_pair_two = getchar();

    //Store the c-string in here
    char *target_string = pull_out_string(f) ;

    stack char_stack;
    initial_stack(&char_stack);

    char balanced_char;

    //Give the infinite loop until EOF returned.
    while(-1 != 2)
    {
        //return the matched the pair characters.
        balanced_char = input_function(first_pair_one, first_pair_two, second_pair_one, second_pair_two, target_string);

	//If there is no more pair character to return, then end loop.
        if(balanced_char == EOF)
        {
            break;
        }
        //push the pair into stack.
        push(&char_stack, balanced_char);

	//If the characters are paired in stack, then pop both of them.
        if(char_stack.Data[(char_stack.index_of_top) - 2] == first_pair_one && char_stack.Data[(char_stack.index_of_top) - 1] == first_pair_two)
        {
            pop(&char_stack);
            pop(&char_stack);
        }
        if(char_stack.Data[(char_stack.index_of_top) - 2] == second_pair_one && char_stack.Data[(char_stack.index_of_top) - 1] == second_pair_two)
        {
            pop(&char_stack);
            pop(&char_stack);
        }
    }
    int emty_or_full = 0;
    emty_or_full = is_empty(char_stack);
    //If the stack is empty, then that means the line is balanced.
    if(emty_or_full == 1)
    {
        printf("Nice,the line is balanced\n");
    }
    else
    {
        printf("The line is not balanced!!!\n");
    }

}
