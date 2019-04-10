// 插入排序 2019-04-09 

#include<stdio.h>

void insertSort(int *arr,int n)
{
	int tmp = 0;
	for(int i = 1;i<n;i++)				// 从第二个元素开始与前面的元素比较 
	{
		int j = i - 1;					// 获取当前元素前一个元素的下标 
		if(arr[i] < arr[j])				// 如果 arr[i] < arr[j](后面的元素小于前面的元素)，则交换元素值 
		{
			tmp = arr[i];				// 记录较小元素值作为比较对象 
			arr[i] = arr[j];			// 将较大值赋值给 arr[i] 
			while(tmp < arr[j-1])		// 利用较小的值循环比较位于前面的值，如果前面元素值较小则一直交换值并比较 
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = tmp;				// 将较小的值相应位置的元素 
		}
	}
}


void insertSort_Two(int *arr,int n)
{
	for(int i = 1;i < n;i++)
	{
		for(int j = i-1;j >= 0 && arr[j] > arr[j+1];j--)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}

int main()
{
	int arr[] = {10,6,5,7,99,23,45,63,1,12,2,56,98,34};
	int n = sizeof(arr) / sizeof(int);
	 
	// insertSort(arr,n);
	insertSort_Two(arr,n);
	printf("\n排好序的数组为：\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
 } 
