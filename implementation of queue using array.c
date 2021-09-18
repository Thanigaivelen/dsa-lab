#include <stdio.h>
#include <stdlib.h>

void enqueue(int *f, int *r, int *arr);
void dequeue(int *f, int *r, int *arr);
void display(int *f, int *r, int *arr);

int main() {
	int choice, front = -1, rear = -1;
	int arr[50];

	while(choice != 4) {
		printf("\nenqueue(1)/ dequeue(2)/ display(3) / quit(4): ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				enqueue(&front, &rear, arr);
				break;
			case 2:
				dequeue(&front, &rear, arr);
				break;
			case 3:
				display(&front, &rear, arr);
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


void enqueue(int *f, int *r, int *arr) {
	int element;
	int front = *f, rear = *r;

	printf("enter element: ");
	scanf("%d", &element);

	if(front == -1 && rear == -1) {
		arr[0] = element;
		front = 0;
		rear = 0;
	}
	else if (rear == 99) {
		printf("overflow\n");
		return;
	} 
	else {
		rear++;
		arr[rear] = element;
	}
	
	*f = front; *r = rear;	// to update in main variables 
}

void dequeue(int *f, int *r, int *arr) {
	int front = *f, rear = *r;

	if(front == -1 && rear == -1) {
		printf("underflow\n");
		return;
	}
	
	printf("element deleted: %d\n", arr[front]);
	if(front == rear) {
		front = -1; 
		rear = -1;
	}
	else {
		front++;
	}

	*f = front; *r = rear; 	// to update in main variables
}

void display(int *f, int *r, int *arr) {
	int i, front = *f, rear = *r;

	if(front == -1 && rear == -1) {
		printf("empty queue\n");
		return;
	}

	printf("\nprinting elements: \n");
	printf("front -> ");
	for(i = front; i <= rear; i++)
	{
		printf("%d -> ", arr[i]);
	}
	printf("rear\n");
}
