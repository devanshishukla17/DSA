/*

N-array traversal-->inorder(<child><root><sibling>)
                    postorder(<child><sibling><root>)
                    preorder(<root><child><sibling>)


1. convert n-array tree to binary tree.


----------infix to prefix-------------

application of stack- recursion,nested functions,infix to postfix,infix to prefix,postfix evaluation,paranthesis matching.

QUESTION--(a+b)*c-d+f
+ab*c-d+f
*+abc-d+f
-*abcd+f
+-*+abcdf

**POSTFIX--REVERSE POLISH NOTATION
**PREFIX--POLISH NOTATION

1. Reverse the infix expression
2.  evluate using postfix evaluation--take care that in postfix what happens is that agar - hai stack 
mai already toh + ko push it in stack and put - outside. in prefix agar same associativity aa jaye toh
usko stack ke bagal mai hi rakh do.
3. reverse the final output.

-----------SKIP LIST-----------
probabilistic data structre

skip list is used to store a sorted data structure.
advanced data structure
it allows efficient searching,inserting and deleting data elements.
it is like an expressway that crosses the below signals. but skiplist is basically more expressways.

-----------CPU----------
shortest job first(preemptive)--jobs are put into the ready queue as they arrive.

shortest job first(non-preemptive)--shortest burst time is executed first.

*/