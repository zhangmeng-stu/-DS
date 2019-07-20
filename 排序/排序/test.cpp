#include <stdio.h>
#include <stdlib.h>
//直接插入排序
//有序区间：[0,i)
//无序区间：[i,size)
void insertSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		for (j = i - 1; j >= 0 && k < array[j]; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = k;
	}
}

//希尔排序
void shellSort(int array[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++)
		{
			int j ;
			int k = array[i];
			for (j = i - gap; j >= 0 && k < array[j]; j-=gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = k;
		}
		if (gap == 1)
		{
			break;
		}
	}
}

//直接选择排序
//有序区间[size-i,size-1)
//无序区间[0,size-i)
void selectSort(int array[],int size)
{
	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 0; j < size - i; j++)
		{
			if (array[j]>array[max])
			{
				max = j;
			}
		}
		int t = array[max];
		array[max] = array[size - 1 - i];
		array[size - 1 - i] = t;

	}
}

//堆排序
//1.建大堆
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(int array[], int size, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;
	if (right < size &&array[right] > array[left])
	{
		max = right;
	}
	if (array[index] >= array[max])
	{
		return;
	}
	int t = array[max];
	array[max] = array[index];
	array[index] = t;

	index = max;
	heapify(array, size, max);
}
void createHeap(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify(array, size, i);
	}
}
void heapSort(int array[], int size)
{
	createHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		int t = array[0];
		array[0] = array[size - i-1];
		array[size - 1 - i] = t;
		heapify(array, size - i - 1, 0);
	}
}

//冒泡排序
//无序区间[0,size - i)
//有序区间[size-i,size-1)
void bubbleSort(int a[], int size) {
	// 把最大的数冒泡到最后去
	for (int i = 0; i < size; i++) {
		int sorted = 1;//优化
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				sorted = 0;
			}
		}

		if (sorted == 1) {
			break;
		}
	}
}
//快速排序
//前后指针法
int partition(int array[], int left, int right) 
{
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
void quickSort(int array[], int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int index = partition(array, left, right);
	//分治左右两个小区间
	quickSort(array, left, index - 1);
	quickSort(array, index + 1, right);
}
//归并排序
void merge(int array[], int temp[], int left, int m, int right)//合并两个有序序列
{
	int leftend = m - 1;
	int p = left, i;
	int num = right - left + 1;
	while (left <= leftend&&m <= right)
	if (array[left] <= array[m])
		temp[p++] = array[left++];
	else
		temp[p++] = array[m++];
	while (left <= leftend)
		temp[p++] = array[left++];
	while (m <= right)
		temp[p++] = array[m++];
	for (i = 0; i<num; i++, right--)
		array[right] = temp[right];
}
void m_Sort(int array[], int temp[], int left, int right)
{
	int mid;
	if (left<right)
	{
		mid = (left + right) / 2;
		m_Sort(array, temp, left, mid);
		m_Sort(array, temp, mid + 1, right);
		merge(array, temp, left, mid + 1, right);
	}
}
void mergeSort(int array[], int size)
{
	int *temp = (int *)malloc(size*sizeof(int));
	if (!temp)
	{
		return;
	}
	m_Sort(array, temp, 0, size - 1);
	free(temp);
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
	int size = sizeof (array)/ sizeof(int);
	printArray(array, size);
	//insertSort(array, size);
	//shellSort(array, size);
	//selectSort(array, size);
	//heapSort(array, size);
	//bubbleSort(array, size);
	//quickSort(array, 0,size-1);
	mergeSort(array, size);
	printArray(array, size);
}