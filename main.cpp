#include <fstream>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//1. Bubble Sort
void bubbleSort(long long int arr[], long long int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

//2. Insertion Sort
void insertionSort(long long arr[], long long n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//3. Selection Sort
void insertionSort(int arr[], long long n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//4. Merge sort
void Merge(long long *a,long long low, long long high, long mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

//5. Quick sort
int partition(long long* arr, long long start, long long end)
{
    int index = 0, pivotElement = arr[end], pivotIndex;
    int* temp = new int[end - start + 1];
    for (int i = start; i <= end; i++)
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivotElement;
    index++;

    for (int i = start; i < end; i++)
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }



    index = 0;
    for (int i = start; i <= end; i++)
    {
        if(arr[i] == pivotElement)
        {

            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex;
}

void quickSort(long long* arr, long long start, long long end)
{
    if(start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
    return;
}

//6. Counting Sort
void countSort(long long arr[], long long n, long long exp)
{
	int output[n], i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

//7. Heap Sort
void heapify(long long int arr[], long long N, long long i)
{

    long long largest = i;

    long long l = 2 * i + 1;

    long long r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(long long arr[], long long N)
{

    for (long long i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (long long i = N - 1; i > 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

//8. Radix Sort
int getMax(long long arr[], long long n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
void radixsort(long long arr[], long long n)
{
	long long exp, m;
	m = getMax(arr, n);

	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

int main(){
    return 0;
}
