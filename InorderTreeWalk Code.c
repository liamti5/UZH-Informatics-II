#include <stdio.h>
//Code similar and partly from GeeksForGeeks
struct node {
    int data;
    struct node* left;
    struct node* right;
};
//helper function which automatically allocates memory--> From GeeksForGeeks
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

void InorderTreeWalk(struct node* node) {
	if (node != NULL) {
		InorderTreeWalk(node->left);
		printf("%d ",node->data);
		InorderTreeWalk(node->right);
	}
}




int main() {
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	
	printf("InoderTreeWalk: \n");
	InorderTreeWalk(root);
}
