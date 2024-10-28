// program to convert a valid infix to postfix:
/*ALGORITHM FOR INFIX to POSTFIX:
Input is the token of the infix expression - char array

1. Create an empty stack called opstack for keeping operators.
2. Create an empty array for the output.
3. Scan the input array from L-R
        1. If the token is an operand, add it to the output array.
        2. If the token is a left paranthesis (, push it on to the stack.
        3. IF the token is a right paranthesis ) , pop the stack until the
        corresponding left paranthesis is found. Add all the operators to the
        end of the output array.
        4. If the token is an operator, *,/,+,(,-, push it on to stack.
        However, first remove any operator already on the stack that has higher
        or equal precedence and add them to the output array.
4. When the input is completely processed, check the stack for any leftover
    operators. Pop them to the end of the output array.
*/

void convert_postfix(char *infix, char *postfix);
char pop(char *stack, int *top);
void push(char *stack, int *top, char ch);
int input_prec(char ch);
int stack_prec(char ch);
#include <stdio.h>
int main()
{
    char infix[20], postfix[20];
    printf("Enter a valid infix exp:\n");
    scanf("%s", infix); //(a*b)+(c*d)
    convert_postfix(infix, postfix);
    printf("%s\n",postfix);
}

void convert_postfix(char *infix, char *postfix)
{
    int i, j;
    char ch;
    char stack[20]; // stack
    int top = -1;
    i = 0;
    j = 0;
    push(stack, &top, '#');
    while (infix[i] != '\0')
    {
        ch = infix[i];
        while(stack_prec(stack[top]) > input_prec(ch))
        {
            postfix[j++] = pop(stack, &top);
        }
        if (input_prec(ch) > stack_prec(stack[top]))
        {
            push(stack, &top, ch);
        }
        else
        {
            pop(stack, &top); // paranthesis
        }
        i++;
    }
    while(stack[top]!='#')
    {
        postfix[j++] = pop(stack,&top);
    }
    postfix[j] = '\0';
}

void push(char *stack, int *top, char ch)
{
    *top = *top + 1;
    stack[*top] = ch;
}

char pop(char *stack, int *top)
{
    char x;
    x = stack[*top];
    --*top; // *top = *top - 1; // (*top)--;
    return x;
}

int input_prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1; // Low precedence
    case '*':
    case '/':
        return 3;
    case '(':
        return 7;
    case ')':
        return 0;
    default:
        return 5;
    }
}

int stack_prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2; // Low precedence
    case '*':
    case '/':
        return 4;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 6; // operands
    }
}
