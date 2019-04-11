// 2019-04-09 selectSort 
// Pick the smallest number in turn and put it first in the array

#include<stdio.h>

void selectSort(int *arr,int n)
{
	for(int i = 0;i < n;i++)		 
	{
		int key = i;				// Record the minimum element coordinates with key 
		for(int j = i+1;j<n;j++) 	// Look backwards from the second element
		{
			key = arr[j] < arr[key] ? j : key;
			/*
			if(arr[j] < arr[key])	
			{
				key = j;			
			}
			*/
			
		}
		if(key != i)				// 比较 key 与 i（最左边元素下标） 的值 ，如果不等则说明最左边元素不是最小值需要调换 
		{
			int tmp = arr[key];
			arr[key] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main()
{
	int arr[] = {10,6,5,7,99,23,45,63,1,12,2,56,98,34};
	int n = sizeof(arr) / sizeof(int);
	 
	selectSort(arr,n);
	printf("\nThe sorted array is：\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
