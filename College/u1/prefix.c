#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct stack
{
    int top;
    char items[MAX];
} stack;

void init_stack(stack *s)
{
    s->top = -1;
}

int isempty(stack *s)
{
    return s->top = -1;
}

// function to push elements in stack
void push(stack *s, char ch)
{
    if (s->top == MAX - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        s->items[++(s->top)] = ch;
    }
    
}

// function to pop element from stack
char pop(stack *s)
{
    if (isempty(s))
    {
        printf("stack underflow\n");
    }
    return s->items[(s->top)--];
}

// function to return topmost element
char topmost(stack *s)
{
    if (!isempty(s)) // if stack is not empty
    {
        return s->items[s->top]; // return topmost element
    }
    return '\0';
}

// function to check if the two characters are opening and closing of the same type

int check(char open, char close)
{
    // basically check if the brackets are open and close by same bracket
    if (open == '(' && close == ')')
        return 1;
    else if (open == '{' && close == '}')
        return 1;
    else if (open == '[' && close == ']')
        return 1;
    else
        return 0;
}

int check_balance(char *expression)
{
    stack s;
    init_stack(&s); // & used since function declaration is pointer

    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(&s, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if ( (isempty(&s)) || (!check(topmost(&s), expression[i])) )
            {
                return 0;
            }
            else
            {
                pop(&s);
            }
        }
    }

    return isempty(&s);
}

int main()
{
    char expression[MAX];
    printf("enter an expression:");
    scanf("&s", expression);
    if (check_balance(expression))
    {
        printf("balanced\n");
    }
    else
    {
        printf("not balanced\n");
    }
    return 0;
}
