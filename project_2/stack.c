#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200
 

//This is the stack struc, acompanying with top index inside.
typedef struct
{
    char Data[MAXSIZE];
    int index_of_top;
}stack;

//This will create a stack and inital the top index as 0.
void initial_stack(stack *char_stack)
{
    char_stack->index_of_top = 0;
}


//This function will push char into stack,and index will rise.
char push(stack *char_stack, char tem_char)
{
    //to check if whole stack is full.
    if(char_stack->index_of_top == MAXSIZE - 1)
    {
        printf("The stack is fall!!!\n");
        exit(-1);
    }

    char_stack->Data[(char_stack->index_of_top)] = tem_char;
    (char_stack->index_of_top)++;
    return tem_char;
}

//This function will pop or remove the top char in stack
char pop(stack *char_stack)
{
    //to check if the stack is empty.
    if(char_stack->index_of_top == 0)
    {
        printf("The stack is totally empty\n");
        exit(0);
    }
    char tem_char = char_stack->Data[char_stack->index_of_top];
    char_stack->index_of_top--;
    return tem_char;
}

//If the stack is empty, yes then return 1, no then return -1
int is_empty(stack char_stack)
{
    if(char_stack.index_of_top == 0)
    {
        printf("The whole stack is empty!!\n");
        return 1;
    }
    else
    {
        printf("The stack is not empty!!!\n");
        return -1;
    }
}

//To check if the stack is full.
int is_full(stack char_stack)
{
    if(char_stack.index_of_top == MAXSIZE - 1)
    {
        printf("The whole stack is totally full!!\n");
        return 1;
    }
    else
    {
        printf("The stack is not full yet!!\n");
        return -1;
    }
}
