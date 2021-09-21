#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
}node;

// node *temp = NULL;

node *newnode(int data) {
	node *temp = malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

node* insert(node* node, int data)
{
    if (node == NULL)
        return newnode(data);
 
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
 
    return node;
} 

void inorder (node *node) {
	if(node == NULL) {
		return;
	}

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

void preorder (node *node) {
	if(node == NULL) {
		return;
	}

	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder (node *node) {
	if(node == NULL) {
		return;
	}

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}

node *findmin(node *node) {
	if(node == NULL) {
		return NULL;
	}

	if(node->left) {
		return findmin(node->left);
	}
	else {
		return node;
	}
	
}

//  Deleting a node
node *deleteNode(node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    node *tmp = root;
    if (root->left == NULL) {
      root = root->right;
      free(tmp);
      return root;
    } else if (root->right == NULL) {
      root = root->left;
      free(tmp);
      return root;
    }

    // If the node has two children
    struct node *temp = findmin(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}


int main() 
{
	// node *root = NULL;
	// root = insert(root, 5);
	// root = insert(root, 10);
	// root = insert(root, 3);
	// root = insert(root, 20);
	// root = insert(root, 30);
	// root = insert(root, 4);
	// root = insert(root, 1);


	// inorder(root);
	// printf("\n");

	// // preorder(root);
	// // printf("\n");

	// root = deleteNode(root, 20);

	// inorder(root);

	int choice, n, data;
	node *root = NULL;

	printf("enter size of bst: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    printf("enter data: ");
    scanf("%d", &data);
    root = insert(root, data);
  }

  while(choice != 6) {
		printf("\nenter choice: insert(1)/delete(2)/preorder(3)/inorder(4)/postorder(5)/quit(6): ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("enter data: ");
    		scanf("%d", &data);
				insert(root, data);
				break;
			case 2:
				printf("enter data to be deleted: ");
    		scanf("%d", &data);
				deleteNode(root, data);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				inorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				printf("quitting the program\n");
				break;
			default:
				printf("invalid choice\n");
		}
	}
	printf("\n");
} 
