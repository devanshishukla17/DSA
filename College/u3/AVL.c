// how can we improve BST
/* ex: 30,20,10
                30    left skewed tree
                /
            ___20
            __/
            _10 
*********************rotations - can be done only on 3 nodes*******************************
this can be rotated to ->           20
                                    / \
                                ___10  30
no of possible trees = 30,20,10  &  30,10,20   &  10,30,20  &  10,20,30  &  20,30,10   &  20,10,30
3 elements = 6 trees = 3! trees
***********n elements = n! possible trees **********************

4 types of rotations -> convert BST to balanced BST[AVL tree]
balanced factor = height of left sub tree - height of right sub tree
                = Hl - Hr = {-1,0,1}
            |Bf| = |Hl - Hr| <= 1

ex:                             o  2-2 =0
                            ___/ \
                    1-0=1   __o   o   1-0 = 1
                            _/    /
                    0-0=0   o    o    0-0 = 0


ex:                            o  3-1=2    // not balanced BST [AAVL tree]  bcuz Bf =2 where it should only range between (-1,0,1)
                            __/ \
                0-1 = -1    _o   o  0-0=0
                            __\
                            ___o  1-0 = 1
                            __/
                            _o    0-0 = 0

rotataions in AVL tree
1. LL rotation
        //the 30,20,10 tree is rotated , because the imbalance is on left side the tree is pulled to the right
        30                           30   2-0 = 2                          20    1-1=0
        /    -> insert 10            /                                     / \
    ___20                           20            =>conversion            10  30  0-0=0
                                    /
                                ___10  // this is imbalanced

2. LR rotation [2 rotations first L then R]  
        //first 10,20 tree is rotated left side & then 30,20,10 tree is rotated right side 
        30                           30   2-0 = 2                    30                                20    1-1=0
        /    -> insert 20            /                               /                                 / \
    ___10                           20            =>conversion      20   =>conversion                 10  30  0-0=0   //now this is balanced
                                    _\                              /
                                    __10  // this is imbalanced    10//this is imbalanced aswell


3. RR rotation
        //the 10,20,30 tree is rotated , because the imbalance is on right side the tree is pulled to the left
        10                             10   2-0 = 2                            20    1-1=0
        _\    -> insert 30              \                                      / \
        __20                            20            =>conversion            10  30  0-0=0
                                        _\
                                        __30  // this is imbalanced

44. RL rotation
        //first 10,30 tree is rotated right side & then 10,20,30 tree is rotated left side 
        10                            10   2-0 = 2                    10                                     20    1-1=0
        _\    -> insert 20             \                               \                                     / \
        _30                            30            =>conversion      20  =>conversion                     10  30  0-0=0   //now this is balanced
                                    ___/                                \
                                    __20  // this is imbalanced         30//this is imbalanced aswell


********** single rotations -> LL & RR
********** double rotations -> LR & RL
rotations in greater trees -> JSP notes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
insertion in an AVL tree
elements -> 40,20,10,25,30,22,50

                                    40                             20
                                ___/                               / \
                                __20   =>LL rotation              10 40
                                __/
                                _10

                                20                        20    1-3=-2
                            ___/ \                        / \ 
                            __10 40       =>             10 40  2-0=2
                                _/                          /
                                25                         25
                                                            \
                                                            30
if multiple imbalances found
-> then consider the immediate ancestor of the recently added node
recently added node = 30 -> ancestor = 40
                                                    
                                        _20                 20
                                        / \                 / \
                                    ___10 40       ->      10  30
                                        __/                    / \
                                        _30                   25 40
                                        _/
                                        25
inserting further on 
                        20       1-3=-2                                                  25
                        / \                                                              / \
                    ___10  30       => RL rotation on nodes 20,30,25                    20  30        
                        ___/ \                                                         / \   \
                        __25 40                                                       10 22   40
                        __/
                        _22 
inserting 50
                    25  2-3=-1
                    / \
                ___20 30   0-2=-2
                __ / \  \
                __10 22  40
                        __\
                        __50
RR rotation on 30,40,50
                    _25  
                    /  \
                ___20   40      ==> AVL tree
                __ / \  / \
                __10 22 30 50

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ex: if the tree is balanced then insert 42
                                    40  //2-4=-2   so here we have RLLR  on the nodes below 40 hence just do RL roatation on 40,50,45
                                ___/  \
                                __30  50
                                __/ \  / \                                         rotation would give 
                                _20 35 45 60                                               45
                                    ___/ \  \                                              / \
                                    __41 40  70                                           40 50
                                    __\
                                    __42

                                    45  
                                ___/  \
                                __40   50
                                __/ \  / \
                                _30 41 42 60   
                                _/  ___/ \  \
                                20  __41 40  70
                                    __\
                                    __42
//insert into AVL tree -> 9,15,20,8,7,13,10

AVL-tree deletion
AVL is a strictly balanced bst
deletion is same like bst

1. check the balance factor in all nodes.
2. if the bf is not 

*/