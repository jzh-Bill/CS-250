#define MAXSIZE 200
typedef struct
{
    char Data[MAXSIZE];
    int index_of_top;
}stack;
void initial_stack(stack *char_stack);
char push(stack *char_stack, char tem_char);
char pop(stack *char_stack);
int is_empty(stack char_stack);
int is_full(stack char_stack);
