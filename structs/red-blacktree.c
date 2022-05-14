#include <stdlib.h>
#include <stdio.h>

#define black 0
#define red 1


struct rb_node { 
    int val;
    int color; 
    struct rb_node* left; 
    struct rb_node* right;
    struct rb_node* parent;
};

// a) insertion
struct rb_node* insert(struct rb_node* root, int x, int color) {
    struct rb_node* newTreeNode = NULL; // only used if root doesn't exist yet
    // struct TreeNode* current = root; // not used???
    if (root == NULL) {
        newTreeNode = malloc(sizeof(struct rb_node));
        newTreeNode -> val = x; 
        newTreeNode -> color = color;
        newTreeNode -> left = NULL;
        newTreeNode -> right = NULL;
        newTreeNode -> parent = NULL;
        return newTreeNode;
    }

    // x is greater than root so should be inserted to right of root
    else if (x > root -> val) { 
        root -> right = insert(root -> right, x, color);
    }    
    // x is smaller than root so should be inserted to left
    else { 
        root -> left = insert(root -> left, x, color);
    }
    return root;
}

// b) searching
struct rb_node* search(struct rb_node* root, int x) {  
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

// // c) deletion
// struct rb_node* delete(struct rb_node* root, int el) {
//     struct rb_node* x = search(root, el);
//     if (x == NULL) {
//         return root; 
//     } 
    
//     struct rb_node* u = root; // uncle of t
//     struct rb_node* parent = NULL; 

//     while (u != x) {
//         parent = u; // parent = root ... Not needed???
//         if (x -> val < u -> val) { // if x is smaller than root, go left
//             u = u -> left; 
//         } else { // if x is larger than root, go right
//             u = u-> right; 
//         }
//     }

//    if (u -> right == NULL) {
//        if (parent == NULL) {
//            root = u -> left; 
//        } else {
//            parent -> right = u -> left; 
//        }
//    } else if (u -> left == NULL) {
//        if (parent == NULL) {
//            root = u -> right; 
//        } else if (parent -> left == u) {
//            parent -> left  = u -> right; 
//        } else {
//            parent -> right = u -> right; 
//        }
//    } else {
//        struct TreeNode* p = x -> left; 
//        struct TreeNode* q = p; 
//        while (p -> right != NULL) {
//            q = p; 
//            p = p -> right; 
//        }
//     if (parent == NULL) {
//         root = p; 
//     } else if (parent -> left == u) {
//         parent -> left = p;
//     } else {
//         parent -> right = p; 
//     }
//     p -> right = u -> right; 
//     if (q != p) {
//         q -> right = p -> left;
//         p -> left = u -> left; 
//     }
//    } 
// }

void printTree(struct rb_node* root) {
    if (root == NULL) {
        return; 
    }
    if (root -> left != NULL) {
        printf("%d, %d -- %d, %d\n", root -> val, root -> color, root -> left -> val, root -> left -> color);
        printTree(root -> left);
    }
   if (root -> right != NULL) {
       printf("%d is %d -- %d is %d\n", root -> val, root -> color, root -> right -> val, root -> right -> color);
       printTree(root -> right);
   }
}

// creates a BST that shows the nbr of elements smaller than the current node
// int MaxRank(struct TreeNode* node, int rank) {
//     if (node == NULL) {
//         return 0;
//     }
//     int rankR = MaxRank(node->right, rank);
//     node -> val = max(rank, rankR);
//     int rankL = MaxRank(node -> left, node -> val + 1);
//     return max(rankL, node -> val + 1);
// }

// void InorderTraversal(struct TreeNode∗ root) {
//     if (root == NULL) {
//         return;
//     }
//     InorderTraversal(root−>left);
//     int inorder_id = 0; 
//     int inorder_array[inorder_id] = root−>val;
//     inorder_id++;
//     InorderTraversal(root−>right);
// }

// // Then we present the function for constructing binary search tree from the sorted array.
// struct TreeNode∗ ConstructBSTFromArray(int start, int end) {
//     if (start > end) {
//     return NULL;
//     }
//     struct TreeNode∗ root = malloc(sizeof(struct TreeNode));
//     int mid = (start + end) / 2;
//     root−>val = inorder array[mid];
//     root−>left = ConstructBSTFromArray(start, mid − 1);
//     root−>right = ConstructBSTFromArray(mid + 1, end);
//     return root;
// }

int main() {
    struct rb_node* root = NULL;
    root = insert(root, 5, black);
    root = insert(root, 4, red);
    root = insert(root, 7, red);
    root = insert(root, 8, black);
    root = insert(root, 6, black);
    printTree(root);
    // delete(root, 8);
    // printf("after deletion");
    // printTree(root);
}