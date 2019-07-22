
#include "test.h"


int main()
{
	int array[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(array) / sizeof(int);
	
	CreatHeap(array, size);
	printHeap(array, size);
}