#include<stdio.h>
#include<stdlib.h>

struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};
typedef struct tnode TNODE;

struct tree {
    TNODE *root;
};
typedef struct tree TREE;

void init(TREE*);
void inorder(TNODE*);
void preorder(TNODE*);
void postorder(TNODE*);
void insert(TREE*, int);
int count(TNODE*);
int leafcount(TNODE*);
int height(TNODE*);
TNODE* rinsert(TNODE*, int);
void tdelete(TREE*, int);
int search(TNODE*, int);
int rsearch(TNODE*, int);
int minimum(TNODE*);
int maximum(TNODE*);

void main() {
    TREE t;
    int ch, num, k, n;
    init(&t);

    while(1) {
        printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder");
        printf("\n5.No. of nodes\n6.No. of Leaf nodes\n7.Height of a tree");
        printf("\n8.Delete a node\n9.Recursively insert\n10.Search");
        printf("\n11.Recursively search\n12.Find smallest\n13.Find largest\n14.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Enter the element: ");
                    scanf("%d", &num);
                    insert(&t, num);
                    break;
            case 2: preorder(t.root);
                    break;
            case 3: postorder(t.root);
                    break;
            case 4: inorder(t.root);
                    break;
            case 5: k = count(t.root);
                    printf("\nThe number of nodes = %d", k);
                    break;
            case 6: k = leafcount(t.root);
                    printf("\nThe number of leaf nodes = %d", k);
                    break;
            case 7: k = height(t.root);
                    printf("\nThe height of the tree = %d", k);
                    break;
            case 8: printf("Enter the node to be deleted: ");
                    scanf("%d", &num);
                    tdelete(&t, num);
                    break;
            case 9: printf("Enter the element: ");
                    scanf("%d", &num);
                    t.root = rinsert(t.root, num);
                    break;
            case 10: printf("Enter the element to search: ");
                     scanf("%d", &num);
                     k = search(t.root, num);
                     if(k) printf("Key found\n");
                     else printf("Not found\n");
                     break;
            case 11: printf("Enter the element to recursively search: ");
                     scanf("%d", &num);
                     k = rsearch(t.root, num);
                     if(k) printf("Key found\n");
                     else printf("Not found\n");
                     break;
            case 12: n = minimum(t.root);
                     printf("\nThe smallest element = %d\n", n);
                     break;
            case 13: n = maximum(t.root);
                     printf("\nThe largest element = %d\n", n);
                     break;
            case 14: exit(0);
        }
    }
}

void init(TREE *t) {
    t->root = NULL;
}

void inorder(TNODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(TNODE *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TNODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int count(TNODE *root) {
    if (root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

int leafcount(TNODE *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return leafcount(root->left) + leafcount(root->right);
}

int height(TNODE *root) {
    if (root == NULL)
        return -1;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int minimum(TNODE *root) {
    if (root == NULL) {
        printf("Empty tree");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int maximum(TNODE *root) {
    if (root == NULL) {
        printf("Empty tree");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}