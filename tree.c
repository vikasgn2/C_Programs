#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Depth of binary tree is equal to the height of the binary tree
// It is calculated by adding number of edges from root to deepest node

typedef struct Node{
	int data;
	struct Node* left;
	struct Node *right;
}node;

node *create_node(int data) {
	node *temp = malloc(sizeof(node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void insert_node(node **root, int data) {
	node *ptr = NULL;

	if(*root == NULL) {
		*root = create_node(data);
		return;
	}

	ptr = *root;
	if(data < ptr -> data) {
		insert_node(&(ptr->left),data);
	}
	else
		insert_node((&ptr->right),data);
}

void preorder(node *root) {
	if(root == NULL)
		return;
	printf("%d ", root -> data);
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(node *root) {
	if(root == NULL)
		return;
	inorder(root -> left);
	printf("%d ", root -> data);
	inorder(root -> right);
}

void postorder(node *root) {
	if(root == NULL)
		return;
	postorder(root -> left);
	postorder(root -> right);
	printf("%d ", root -> data);
}

int tree_depth(node *root) {
	int max_depth;
	if(root == NULL)
		return 0;

	int left_depth,right_depth;
	left_depth = tree_depth(root->left);
	right_depth = tree_depth(root->right);

	if(left_depth > right_depth)
		max_depth = left_depth + 1;
	else
		max_depth = right_depth + 1;
	return max_depth;
}

int main(int argc, char **argv)
{
	node *root = NULL;
	int depth_or_height_of_tree = 0;

	insert_node(&root,4);
	insert_node(&root,2);
	insert_node(&root,1);
	insert_node(&root,3);
	insert_node(&root,6);
	insert_node(&root,5);
	insert_node(&root,7);
	insert_node(&root,8);
	
	printf("Inorder Traversal   -> ");
	inorder(root);
	printf("\n");
	printf("Preorder Traversal  -> ");
	preorder(root);
	printf("\n");
	printf("Postorder Traversal -> ");
	postorder(root);
	printf("\n");

	depth_or_height_of_tree = tree_depth(root);
	printf("The depth or height of tree is %d\n", depth_or_height_of_tree);
	return 0;
}
