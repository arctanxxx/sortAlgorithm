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
		if(key != i)				// �Ƚ� key �� i�������Ԫ���±꣩ ��ֵ �����������˵�������Ԫ�ز�����Сֵ��Ҫ���� 
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
	printf("\nThe sorted array is��\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
