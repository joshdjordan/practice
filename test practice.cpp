#include <iostream>

void swap(int arr[], int first, int last)
{
	int temp;
	
	temp = arr[first];
	arr[first] = arr[last];
	arr[last] = temp;
}

void RNG(int arr[], int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int RandNum = rand() % 20;
		swap(arr, i, RandNum);
	}
}

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
}

void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{	
		int SmallIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[SmallIndex])
			{
				SmallIndex = j;
			}
		}
		swap(arr, SmallIndex, i);
	}
}

template <class T>
void InsertionSort(T list[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])
		{
			T temp = list[i];
			int index = i;

			while (index > 0 && list[index - 1] > temp)
			{
				list[index] = list[index - 1];
				index--;
			}
			list[index] = temp;
		}
	}
}

template <class T>
int partition(T list[], int first, int last)
{
	T pivot;
	int SmallIndex;

	swap(list, first, (first + last) / 2);

	pivot = list[first];
	SmallIndex = first;

	for (int i = first + 1; i <= last; i++)
	{
		if (list[i] < pivot)
		{
			SmallIndex++;
			swap(list, i, SmallIndex);
		}
	}
	swap(list, first, SmallIndex);

	return SmallIndex;
}

template <class T>
void recursion_QuickSort(T list[], int first, int last)
{
	int PivotLocation;

	if (first < last)
	{
		PivotLocation = partition(list, first, last);
		recursion_QuickSort(list, first, PivotLocation - 1);
		recursion_QuickSort(list, PivotLocation + 1, last);
	}
}

template <class T>
void QuickSort(T list[], int length)
{
	recursion_QuickSort(list, 0, length - 1);
}

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int const size = 20;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	RNG(arr, size);
	std::cout << "----- Randomized Array -----\n";
	print(arr, size);

	// BubbleSort(arr, size);
	// SelectionSort(arr, size);
	// QuickSort(arr, size);
	InsertionSort(arr, size);
	std::cout << "\n----- Sorted Array -----\n";
	print(arr, size);

	return 0;
}