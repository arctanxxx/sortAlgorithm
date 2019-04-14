// 2019-04-11 heapSort
#include<stdio.h>

void swap(int *arr,int i,int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void heapify(int *arr,int index,int size)
{
	int left = index * 2 + 1;
	while(left < size)
	{
		int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1:left;
		largest = arr[largest] > arr[index] ? largest : index;
		if(largest == index)
		{
			break;
		 } 
		swap(arr,largest,index);
		index = largest;
		left = index * 2 + 1;
	}
}

void heapInsert(int *arr,int index)
{
	while(arr[index] > arr[(index - 1) / 2])
	{
		swap(arr,index,(index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void heapSort(int *arr,int len)
{
	for(int i = 0;i < len;i++)
	{
		heapInsert(arr,i);
	}
	int size = len;
	swap(arr,0,--size);
	while(size > 0)
	{
		heapify(arr,0,size);
		swap(arr,0,--size);
	}
}

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10,78,11};
	int n = sizeof(arr) / sizeof(int);
	 
	heapSort(arr,n);
	printf("\nThe sorted array is£º\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
