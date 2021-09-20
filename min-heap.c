// Max-Heap data structure in C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10], n, data, choice = 0;

//   insert(array, 3);
//   insert(array, 4);
//   insert(array, 9);
//   insert(array, 5);
//   insert(array, 2);

  printf("enter size of heap: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    printf("enter data: ");
    scanf("%d", &data);
    insert(array, data);
  }

  printf("Min-Heap array: ");
  printArray(array, size);

  while(choice != 4) {
		printf("enter choice: insert(1)/delete(2)/print(3)/quit(4): ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("enter data: ");
    		scanf("%d", &data);
				insert(array, data);
				break;
			case 2:
				printf("enter data to be deleted: ");
    		scanf("%d", &data);
				deleteRoot(array, data);
				break;
			case 3:
				printArray(array, size);
				break;
			case 4:
				printf("quitting the program\n");
				break;
			default:
				printf("invalid choice\n");
		}
	}
	return 0;
}
