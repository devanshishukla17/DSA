#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char infix[100], postfix[100], stack[40];
int top = -1;

int check_oper(char c)
{
    switch (c)
    {
    case '*':
    case '/':
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int input_prec(char c) // function determining input precedence with * and / having higher precedence than + and -
{
    switch (c)
    {
    case '*':
    case '/':
        return 3;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        printf("ERROR\n");
        return -999;
    }
}

int stack_prec(char c) // function determining stack precedence with * and / having higher precedence than + and -
{
    switch (c)
    {
    case '*':
    case '/':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    default:
        printf("ERROR\n");
        return -999;
    }
}

void convert_exp()
{
    int index = 0, opindex = 0;
    printf("input a valid infix expression\n");
    scanf("%s", infix);
    while (infix[index] != '\0')
    {
        // case 0   ~~~~~ to check if stack is empty or not
        if (check_oper(infix[index]))
        {
            if (top == -1)
            {
                top++;
                stack[top] = infix[index]; // step 2 of infix to postfix(see notes)
                index++;
                // so now if the stack is empty then put the operator onto the stack
            }
            else
            {
                // case 1   ~~~ compare input precedence and stack precedence and then do step 3
                if (input_prec(infix[index]) > stack_prec(stack[top]))
                {
                    top++;
                    stack[top] = infix[index];
                    index++;
                }
                else
                { // case 2 ~~~ to pop out elements from stack when lower precedence encountered and inserting in into postfix
                    while ((stack_prec(stack[top]) > input_prec(infix[index])) && (top >= 0))
                    {
                        postfix[opindex] = stack[top];
                        top--;
                        opindex++;
                    }
                }
            }
        }
        else
        {
            postfix[opindex] = infix[index]; // or postfix[opindex++] = infix[index++]
            opindex++;
            index++;
        }
    }
    while(top>=0)
    {
        postfix[opindex++] = stack[top--];   
        //copy remaining operators from stack to postfix string
    }
    postfix[opindex] ='\0';
    printf("postfix expression is %s",postfix);
}
int main()
{
    convert_exp();
    return 0;
}