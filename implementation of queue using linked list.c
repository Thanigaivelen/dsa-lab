#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
}node;

void enqueue(node *front, node *rear);
void dequeue(node *front, node *rear);
void display(node *front, node *rear);

int main() {
	int choice;

	node *front = (node*) malloc(sizeof(node));
	node *rear = (node*) malloc(sizeof(node));
	if(front == NULL || rear == NULL) {
		printf("no memory available\n");
		return 1;
	}
	front->next = NULL;
	rear->next = NULL;

	while(choice != 4) {
		printf("\nenqueue(1)/ dequeue(2)/ display(3) / quit(4): ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				enqueue(front, rear);
				break;
			case 2:
				dequeue(front, rear);
				break;
			case 3:
				display(front, rear);
				break;
			case 4:
				printf("quiting the program\n");
				break;
			default:
				printf("invalid choice\n");
				break;
		}
	}	

	return 0;
}


void enqueue(node *front, node *rear) {
	node *newnode = (node*) malloc(sizeof(node));
	if(newnode == NULL) {
		printf("overflow\n");
		return;
	}

	printf("enter element: ");
	scanf("%d", &newnode->num);

	if(front->next == NULL) {
		front->next = newnode;
		newnode->next = rear;
		return;
	}

	node *temp = front->next;
	while (temp->next != rear) {
		temp = temp->next;
	}

	temp->next = newnode;
	newnode->next = rear;
}

void dequeue(node *front, node *rear) {
	node *first = front->next;
	if(first == NULL) {
		printf("underflow\n");
		return;
	}

	printf("deleted element: %d\n", first->num);

	front->next = first->next;
	free(first);
}

void display(node *front, node *rear) {
	node *temp = front->next;
	if(temp == NULL) {
		printf("empty queue\n");
		return;
	}

	printf("printing elements: \n");
	printf("front -> ");
	while (temp != rear) {
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("rear\n");
}
