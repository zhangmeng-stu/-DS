#include <stack>
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
	std::stack<int> s;
	s.push(left);
	s.push(right);

	while (!s.empty())
	{
		int high = s.top(); s.pop();
		int low = s.top(); s.pop();
		if (low >= high)
		{
			continue;
		}
		int pivotIndex = partition(array, low, high);

		s.push(pivotIndex + 1);
		s.push(high);

		s.push(low);
		s.push(pivotIndex - 1);
	}
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