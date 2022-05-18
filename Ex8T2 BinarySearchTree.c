#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//following code is from GeeksForGeeks
struct TreeNode* newNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return (newNode);
}
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TreeNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TreeNode* root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}

//exercise solution again
struct TreeNode* insert (struct TreeNode* root, int val) { //insert (where to insert, what to insert
	//first create a pointer to the new TreeNode we will insert 
	//i.e. a struct TreeNode pointer
	struct TreeNode* newTreeNode = NULL; //random pointer
	
	//first, we check if there are already any nodes in our tree
	//if tree empty, insert at root
	if (root == NULL) {
		newTreeNode = malloc(sizeof(struct TreeNode)); //reserves memory for our struct
		newTreeNode -> val = val;
		newTreeNode -> left = NULL; //NULL values following new value val
		newTreeNode -> right = NULL;
		return newTreeNode; //new root of the tree
	}
	
	//else look for the correct place to insdrt the node
	//we do this recursively until we reach 'empty' tree
	//val is the value we want to insert
	if (val > root -> val) {
		root -> right = insert(root->right, val); //we call the function recursively on the RIGHT chilf of current node
		}else {
			root -> left = insert(root -> left, val);
		}
		return root;
	}
	
	//if the value we want to insert is LARGER than the node we're currently looking at
	//then we have to insert the new node in the RIGHT subtree!
	 

/*
struct TreeNode* search(struct TreeNode* root, int v) { //not sure if correct --> from pseudo code Sl06 17/65 -->> should be correct
	while (root != NULL && root -> val != v) {
		if (v < root -> val) {
			root = root -> left;
			
		}
		else {
			root = root -> right;
		}
	}
	return root; //returns index
}*/
struct TreeNode* search(struct TreeNode* root, int val) {
	//we need some temporary node pointer to traverse the tree
	struct TreeNode* current = root;
	
	//we should traverse the tree until we reach a NULL node
	//or until we reach the node we wanted to find
	
	//if the value we are looking for is smaller than the current node we're at
	//then we only have to look at the left subtree
	//else only look at right subtree
	while (current != NULL && current -> val != val){ //as long as we're not at a null node AND we didn't find our value yet
		if (val < current ->val) {//traversing the tree!!!!
			current = current -> left; //change pointer, i.e. go to the left subtree
		}
		else { //only look at the right subtree
			current = current -> right;
		}
	}
	return current;   //
}
	

struct TreeNode* delete(struct TreeNode* root, int val) {
	struct TreeNode* x = search(root, val);
	if (x == NULL) { //search did not find an element, hence do nothing, just simply return the root.
		return root;
	}
	struct TreeNode* u = root;
	struct TreeNode* parent = NULL; //parent of tree node with value = val
	while (u !=x) {
		parent = u;
		if (x -> val < u -> val) {
			u = u->left;
		}
		else {
			u = u->right;
		}
	}
	//Leaf and root case also handled in the no right or left branch
	//Since if it's leaf, its null anyway.
	if (u->right == NULL) {//there is no right branch
		if (parent == NULL) { //delete root
		root = u->left;
		}
		else if (parent ->left ==u) {//if it's a left child, make left the new chil
		parent->left = u->left;
		}
		else {
			parent->right = u->left;
		}
	}
	else if (u->left ==NULL) {//there is no left branch
	if (parent ==NULL) {//delete root
		root = u->right;
	}else if (parent->left==u) { //if it's a left child, make right the new child
	parent -> left = u->right;
	}
	else{
		parent->right = u->right;
	}
	
	}else{
		struct TreeNode* p = x->left;
		struct TreeNode* q=p;
		while (p->right != NULL) {//Whilst right is null
		q=p;
		p=p->right;
		}
	if (parent == NULL) {//if we are at root
		root = p;
	}else if (parent->left ==u) {//if its a left child
	parent->left =p;
	}else {//if its a right child
	parent->left = p;
	}
	p->right=u->right;
	if (q!=p) {
		q->right=p->left;
		p->left = u->left;
	}
	}
	free(u);
	return root;
}

void printTreeRecursive(struct TreeNode* root) {
	if (root == NULL) return;
 	if (root->left != NULL) {
 		printf("%d -- %d\n", root->val, root->left->val);
 		printTreeRecursive(root->left);
}
 	if (root->right != NULL) {
 		printf("%d -- %d\n", root->val, root->right->val);
 		printTreeRecursive(root->right);
 	}
}

void printTree(struct TreeNode* root) {
 	printf("graph g {\n");
	printTreeRecursive(root);
 	printf("}\n");
 	}



int main() {
	 int arr[] = {10,20,23,30,31,32,33,34,35,45,67,65,66};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct TreeNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("n PreOrder Traversal of constructed BST ");
    printTree(root);
 
    return 0;
	
}
