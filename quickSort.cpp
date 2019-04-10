// 2019-04-09 快速排序 
/*
过程：在数组中随机选择一个数字，小于等于该数字的元素放在其左边，大于等于该元素的数字放在右边， 分别递归调用左右两个部分 
*/

#include<stdio.h>

// 交换元素值 
void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;	
}

// 分治法将数组分为两个部分
int patition(int *arr,int left,int right)
{
	printf("\n");
	int j = left;						// 用来遍历数组 
	int i = j - 1;						// 用来指向最小基准元素的位置（第一次没元素为-1）,每一次递归调用都会重新赋值 
	printf("i = %d ",i);
	printf("left = %d ",left);
	printf("right = %d \n",right);
	int key = arr[right];				// 最后一个元素为基准元素 
	for (;j<right;++j)					// 从左到右遍历数组，把小于等于基准元素的放到左边，大于基准元素放到右边 
	{
		/*
		在每一次迭代过程中，
		如果 arr[j] <= key 则 i 和 j 的值相差 1（j = i+1），此时通过  swap(&arr[j],&arr[++i]);将小于基准的元素放在原来不动的位置上；
		如果 arr[j] > key 则 i 和 j 的值相差2(j = i+2)，此时通过下一次  swap(&arr[j],&arr[++i]);将大于基准的元素与此刻 a[j] 上的元素交换；
		*/
		if(arr[j] <= key)				// 如果该元素小于基准元素 
		{
			printf("arr[%d] = %d ",j,arr[j]);
			printf("key = %d \n",key);
			swap(&arr[j],&arr[++i]);	// 将此元素放到最小基准元素位置上 
		}
	}
	swap(&arr[right],&arr[++i]);		// 将基准元素放到中间 
	return i;							// 返回数组中间位置 
 } 
 
// 快速排序 
void quickSort(int *arr,int left,int right)
{
	if(left >= right)
	{
		return; 
	}
	
	int mid = patition(arr,left,right);
	quickSort(arr,left,mid-1);
	quickSort(arr,mid+1,right);			
}

int main()
{
	int arr[] = {10,6,5,7,99,23,45,63,1,12,2,56,98,34};
	int n = sizeof(arr) / sizeof(int);
	 
	quickSort(arr,0,n-1);
	printf("\n排好序的数组为：\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
 
 /*
打印实现过程： 
 i = -1 left = 0 right = 13
arr[j] = 10 key = 34
arr[j] = 6 key = 34
arr[j] = 5 key = 34
arr[j] = 7 key = 34
arr[j] = 23 key = 34
arr[j] = 1 key = 34
arr[j] = 12 key = 34
arr[j] = 2 key = 34

i = -1 left = 0 right = 7
arr[j] = 1 key = 2

i = 1 left = 2 right = 7
arr[j] = 5 key = 6

i = 3 left = 4 right = 7
i = 4 left = 5 right = 7
arr[j] = 10 key = 23
arr[j] = 12 key = 23

i = 4 left = 5 right = 6
arr[j] = 10 key = 12
i = 8 left = 9 right = 13
arr[j] = 45 key = 99
arr[j] = 63 key = 99
arr[j] = 56 key = 99
arr[j] = 98 key = 99

i = 8 left = 9 right = 12
arr[j] = 45 key = 98
arr[j] = 63 key = 98
arr[j] = 56 key = 98

i = 8 left = 9 right = 11
arr[j] = 45 key = 56

排好序的数组为：
1 2 5 6 7 10 12 23 34 45 56 63 98 99
 */ 
