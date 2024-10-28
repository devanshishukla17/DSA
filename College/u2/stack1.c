/*
expression normally will be in infix notation
3 types of giving an expression:
infix-human readable
postfix-machine readable
prefix-machine readable
expression consists of operators and operands.
operators-arithmetic,logical,relational-any binary operator can be considered
operands- constants,variables,expressions
eg- 
1. 2+3
2. a+b*c
3. (a+b)/(c-e)
4. a+3/b-7-(4+2)

order of operation:
1. paranthesis (),{},[],((a+b)+c)
2. exponents- ^
3. multiplication(*) and division(/)
4. addition(+) and subtraction (-)

to parse an expression we have to see
1. precedence
2. associativity(if operators in the expression have the same precedence)

infix: human readable
eg: 2+3-4*(6/8)+9
(2+3)-(4*(6/8)+9)
paranthesis gives more readiblity to the expression

postfix and prefix- does not require any of the following
1. no paranthesis
2. no precedence
3. no associativity
4. no ambiguity

postfix- a straight forward one
    reverse polish notation
    less compilation time 
    less memory
    easy to parse

infix--------postfix-------prefix
a+b            ab+            +ab
a+b*c        abc*+         +a*bc
(a+b)*c       ab+c*        *+abc
a+b*c+d      a+bc*+d-->abc*++d-->abc*+d+     a+(*bc)+d-->+a*bc+d-->++a*bcd
(a+b)*(c+d)   ab+cd+*     (+ab)*(+cd)-->*+ab+cd
a-b-d*e/f+b*c  a-b-(de*)/f+b*c  a-b-(de*f/)+b*c  a-b-(de*f/)+bc*  (ab-)-(de*f/)+bc*  ab-de*f/-+bc* (ab-de*f/-bc*+)
a-b-(*de)/f+b*c  a-b-(/*def)+b*c  a-b-(/*def)+(*bc)  (-ab)-(/*def)+*bc      +--ab/*def*bc
*/