#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

struct TreeNode { 
    int val;
    struct TreeNode* left; 
    struct TreeNode* right;
};

// a) insertion
struct TreeNode* insert(struct TreeNode* root, int x) {
    struct TreeNode* newTreeNode = NULL; // only used if root doesn't exist yet
    struct TreeNode* current = root; // not used???
    if (root == NULL) {
        newTreeNode = malloc(sizeof(struct TreeNode));
        newTreeNode -> val = x; 
        newTreeNode -> left = NULL;
        newTreeNode -> right = NULL;
        return newTreeNode;
    }

    // x is greater than root so should be inserted to right of root
    else if (x > root -> val) { 
        root -> right = insert(root -> right, x);
    }    
    // x is smaller than root so should be inserted to left
    else { 
        root -> left = insert(root -> left, x);
    }
    return root;
}

// b) searching
struct TreeNode* search(struct TreeNode* root, int x) {  
    if (root -> val == x) {
        return root; 
    }
    else if (x > root -> val) {
        return search(root -> right, x);
    }
    else if( x < root -> val) {
        return search(root -> left, x);
    }
    else {
        return NULL;
    }
}

// c) deletion
struct TreeNode* delete(struct TreeNode* root, int el) {
    struct TreeNode* x = search(root, el);
    if (x == NULL) {
        return root; 
    } 
    
    struct TreeNode* u = root; // uncle of t
    struct TreeNode* parent = NULL; 

    while (u != x) {
        parent = u; // parent = root ... Not needed???
        if (x -> val < u -> val) { // if x is smaller than root, go left
            u = u -> left; 
        } else { // if x is larger than root, go right
            u = u-> right; 
        }
    }

   if (u -> right == NULL) {
       if (parent == NULL) {
           root = u -> left; 
       } else {
           parent -> right = u -> left; 
       }
   } else if (u -> left == NULL) {
       if (parent == NULL) {
           root = u -> right; 
       } else if (parent -> left == u) {
           parent -> left  = u -> right; 
       } else {
           parent -> right = u -> right; 
       }
   } else {
       struct TreeNode* p = x -> left; 
       struct TreeNode* q = p; 
       while (p -> right != NULL) {
           q = p; 
           p = p -> right; 
       }
    if (parent == NULL) {
        root = p; 
    } else if (parent -> left == u) {
        parent -> left = p;
    } else {
        parent -> right = p; 
    }
    p -> right = u -> right; 
    if (q != p) {
        q -> right = p -> left;
        p -> left = u -> left; 
    }
   } 
}

void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return; 
    }
    if (root -> left != NULL) {
        printf("%d -- %d\n", root -> val, root -> left -> val);
        printTree(root -> left);
    }
   if (root -> right != NULL) {
       printf("%d -- %d\n", root -> val, root -> right -> val);
       printTree(root -> right);
   }
}

// creates a BST that shows the nbr of elements smaller than the current node
int MaxRank(struct TreeNode* node, int rank) {
    if (node == NULL) {
        return 0;
    }
    int rankR = MaxRank(node -> right, rank);
    node -> val = max(rank, rankR);
    int rankL = MaxRank(node -> left, node -> val + 1);
    return max(rankL, node -> val + 1);
}

// MinAggregate modifies the tree such that each node contains the aggregated value of all nodes (i.e., summation of values) less
// than or equal to that node. (midterm 2020-2)
int minimumAggregateTree(struct TreeNode *node, int sum) {
    if (node == NULL) {
        return sum; 
    }
    sum = node -> val + minimumAggregateTree(node -> left, sum);  
    node -> val = sum; 
    sum = minimumAggregateTree(node -> right, sum); 
    return sum; 
}

void inorder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inorder(root -> left);
    printf("%d ", root -> val);
    inorder(root -> right);
}


// Then we present the function for constructing binary search tree from the !!!sorted array!!!.
struct TreeNode *ConstructBSTFromArray(int A[], int start, int end) {
    if (start > end) return NULL; 

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int mid = (start + end) / 2; 
    root -> val = A[mid];
    root -> left = ConstructBSTFromArray(A, start, mid -1);
    root -> right = ConstructBSTFromArray(A, mid + 1, end); 
    return root; 
}

// trimms the BST so that it only contains values that are in the given low and high
struct TreeNode *trimBST(struct TreeNode *root, int low, int high) {
    if (root == NULL) return root; 
    if (root -> val > high) return trimBST(root -> left, low, high); 
    if (root -> val < low) return trimBST(root -> right, low, high); 
    root -> left = trimBST(root -> left, low, high);
    root -> right = trimBST(root -> right, low, high); 
    return root; 
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]); 
    }
} 

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 6);
    trimBST(root, 5, 7); 
    printTree(root); 
    // inorder(root); 
    // printTree(root);
    // delete(root, 8);
    // printf("after deletion\n");
    // printTree(root);
    // int A[5] = {1, 2, 3, 4, 5}; 
    // printArray(A, 5); 
    // struct TreeNode *test = NULL;
    // test = ConstructBSTFromArray(A, 0, 4); 
    // printTree(test);  
    // MaxRank(root, 0);

    // // testing trimBST
    // root = trimBST(root, 5, 8); 
    // printTree(root); 
}