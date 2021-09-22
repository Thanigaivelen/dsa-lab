#include <stdio.h>
#include <stdlib.h>

int *arr;
int capacity = 10;
int size = 0;

void initArray() {
	int loadfactor = size/capacity;
	if (loadfactor >= 0.5) {
		capacity = (capacity*2 >= 10) ? capacity * 2 : 10;
	}
	arr = malloc(capacity * sizeof(int));
}

int hashFunction(int key)
{
  return (key % capacity);
}

void linearProbing(int key) {
	int index = hashFunction(key);
	while(arr[index] != -1) {
		index += 1;
		index = (index >= capacity) ? index % capacity : index;
	}
	arr[index] = key;
	size++;
}

void quadraticProbing(int key)
{
	int index = hashFunction(key), count = 0;
	int temp = index;
	while(arr[index] != -1) {
		count++;
		index = temp + count*count;
		index = (index >= capacity) ? index % capacity : index;
	}
	arr[index] = key;
	size++;
}


void display()
{
	for(int i = 0; i < capacity; i++) {
		if (arr[i] == -1) {
			printf("element at %d: no data\n", i);
			continue;
		}
		printf("element at %d: %d\n", i, arr[i]);
	}
}

int main()
{
	int key, choice = 0, probing = 0;
	printf("enter size: ");
	scanf("%d", &size);
	initArray();
	
	for (int i = 0; i < capacity; i++) {
		arr[i] = -1;
	}

	printf("enter 1 for linear probing / 2 for quadratic probing: ");
	scanf("%d", &probing);
	printf("\n");

	int local = size;

	if (probing == 1) {
		for (int i = 0; i < local; i++) {
			printf("enter data %d: ", i);
			scanf("%d", &key);
			linearProbing(key);
		}
	}
	else if (probing == 2) {
		for (int i = 0; i < local; i++) {
			printf("enter data: ");
			scanf("%d", &key);
			quadraticProbing(key);
		}
	}

	while (choice != 3) {
		printf("press insert(1) / display(2) / quit(3): ");
		scanf("%d", &choice);

		if (choice == 1) {
			printf("enter data: ");
			scanf("%d", &key);
			if (probing == 1) 
				linearProbing(key);
			else if (probing == 2)
				quadraticProbing(key);
		}
		else if (choice == 2) 
			display();
		else if (choice == 3)
			printf("quitting the program\n");
	}

}
