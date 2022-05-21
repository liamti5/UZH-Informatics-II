#include <stdio.h>
//assume that left child of node temp exists
struct node {
	struct node* p; //parent
	struct node* r; //right child
	struct node* l; //left child
};

void rightrotate(struct node* temp) {
	struct node * g = temp->p;
	struct node* left = temp->l;
	temp->l = l->r // 'b' becomes left chilf of 'temp'
	if (left->r) {
		___________ //'temp' becomes parent of 'b'
	}
	if (temp ==g->l){
		g->l = left;
	}
	else {
		g->r = left;
	}
	_____________// 'temp' becomes right child of 'left'
	____________// 'left' becomes parent of 'temp'
}
