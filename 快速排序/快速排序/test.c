#include <stdio.h>

//hoare法
int partition1(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];
	while (begin < end)
	{
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		int t1 = array[begin];
		array[begin] = array[end];
		array[end] = t1;
	}
	int t2 = array[begin];
	array[begin] = array[right];
	array[right] = t2;

	return begin;
}
//挖坑法
int partition2(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = array[right];
	while (begin < end)
	{
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		array[end] = array[begin];
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;

	return begin;
}
//前后指针法
int partition(int array[], int left, int right) {
	//[left, div) 比基准小
	//[div, i) 比基准值大于等于
	int div = left;
	int i = left;
	for (; i < right; i++)
	{
		if (array[i] < array[right])
		{
			int t = array[i];
			array[i] = array[div];
			array[div] = t;
			div++;
		}
	}

	int temp = array[div];
	array[div] = array[right];
	array[right] = temp;
	return div;
}

void quickSortIn(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivotIndex = partition(array, left, right);
	quickSortIn(array, left, pivotIndex - 1);
	quickSortIn(array, pivotIndex + 1, right);

}
void quickSort(int array[], int size)
{
	quickSortIn(array, 0, size - 1);
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(array) / sizeof(int);
	printArray(array, size);
	quickSort(array, size);
	printArray(array, size);

}