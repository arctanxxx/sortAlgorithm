// 选择排序 2019-04-09
// 依次选出最小的数放在数组的最前面

#include<stdio.h>

void selectSort(int *arr,int n)
{
	for(int i = 0;i < n;i++)		 
	{
		int key = i;				// 用 key 记录最小元素坐标 
		for(int j = i+1;j<n;j++) 	// 从第二个元素向后开始寻找 
		{
			key = arr[j] < arr[key] ? j : key;
			/*
			if(arr[j] < arr[key])	// 如果找到比 arr[key] 小的元素 
			{
				key = j;			// 此时将最小元素坐标赋值给 key 
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
	printf("\n排好序的数组为：\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
