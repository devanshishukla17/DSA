/*

EXPRESSION TREE-TYPE OF BINARY TREE
-->OPERANDS WILL BE THE LEAF NODES(NO CHILD OR CHILDREN)/EXTERNAL NODES(eg. A,B,D,k)
-->OPERATORS WILL BE THE NON-LEAF NODES/INTERNAL NODES(+,-,*,/)

------ALGORITHM------
1. INFIX TO POSTFIX
2. READ ALL THE CHARACTERS FROM LEFT TO RIGHT IN THE POSTFIX EXP.
3. IF THE CHARACTER IS AN OPERAND--> PUSH THE CHAR ONTO THE STACK
4. IF THE CHARACTER IS AN OPERATOR--> POP THE TOP MOST 2 ELEMENTS FROM THE STACK-->construct a tree
with the operator as the root and the popped operands as RIGHT AND LEFT child.-->push the tree as an element
into the stack.
5. REPEAT THE PROCESS UNTIL ALL CHARACTERS ARE READ FROM THE POSTFIX EXP.
----------------------


*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10

typedef struct treeNode
{
    int isOperator; // 0 for operand, 1 for operator
    char operator;  // Store operator if isOperator == 1
    float operand;  // Store operand if isOperator == 0
    struct treeNode *left;
    struct treeNode *right;
} NODE;

static int top = -1;

void push(NODE *nn, NODE *stack[])
{
    if (top < MAX - 1)
    {
        stack[++top] = nn;
    }
    else
    {
        printf("STACK FULL\n");
    }
}

NODE *pop(NODE *stack[])
{
    if (top == -1)
    {
        printf("STACK EMPTY\n");
        return NULL;
    }
    return stack[top--];
}

NODE *construct(char exp[])
{
    NODE *nn, *stack[MAX];
    int i = 0;

    while (exp[i])
    {
        nn = (NODE *)malloc(sizeof(NODE));
        if (isdigit(exp[i]))
        {
            nn->isOperator = 0;
            nn->operand = exp[i] - '0'; //basically character to integer
            nn->left = nn->right = NULL;
            push(nn, stack);
        }
        else
        {
            nn->isOperator = 1;
            nn->operator= exp[i]; // Store operator
            nn->right = pop(stack);
            nn->left = pop(stack);
            push(nn, stack);
        }
        i++;
    }
    return pop(stack); // Final pop gives the root of the tree
}

void inorder(NODE *bst)
{
    if (bst != NULL)
    {
        inorder(bst->left);
        if (bst->isOperator == 0)
            printf("%g ", bst->operand);
        else
            printf("%c ", bst->operator);
        inorder(bst->right);
    }
}

float calculate(float x, char op, float y)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y != 0)
            return x / y;
        else
        {
            printf("Division by zero error\n");
            exit(1);
        }
    default:
        printf("Invalid operator\n");
        exit(1);
    }
}

float evaluate(NODE *bst)
{
    if (bst->isOperator == 0)
    {
        return bst->operand;
    }
    float x = evaluate(bst->left);
    float y = evaluate(bst->right);
    return calculate(x, bst->operator, y);
}

int main()
{
    NODE *bst;
    char exp[MAX] = "567*+8-";
    bst = construct(exp);
    if (bst == NULL)
    {
        printf("Failed to construct tree\n");
        return 1;
    }
    printf("In-order traversal: ");
    inorder(bst);
    printf("\n");
    printf("Evaluation result: %g\n", evaluate(bst));
    return 0;
}