#include<stdio.h>
void Insertsort(int arr[], int n)
{
	int temp = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
		}
		for (int j = i; arr[j - 1] > arr[j] && j > 0; j--)
		{
			arr[j] = arr[j-1];
			arr[j-1] = temp;
		}
	}
}
void Print(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BBsort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void Selectsort(int arr[], int n)
{
	int temp = 0; int k = 0;
	for (int i = 0; i < n; i++)
	{
		k = i;
		for (int j = i; j < n ; j++)
		{
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}
int main()
{
	int arr1[] = { 2,3,4,5,9,8,7,6,1 };
	Insertsort(arr1, 9);
	Print(arr1, 9);
	int arr2[] = { 2,3,4,5,9,8,7,6,0 };
	BBsort(arr2, 9);
	Print(arr2, 9);
	int arr3[] = { 2,9,4,5,10,8,7,6,0 };
	Selectsort(arr3, 9);
	Print(arr3, 9);
}