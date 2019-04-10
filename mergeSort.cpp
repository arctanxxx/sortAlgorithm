// 归并排序 2019-04-10 
#include<stdio.h>
#include<limits.h>

void Merge(int arr[],int left,int mid,int right)
{
	int len = right - left +1;
	int *temp = new int[len];
	int k = 0;
	int i = left;
	int j = mid + 1;
	while(i <= mid && j<=right)
	{
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}
	// 两个必有一个越界 
	while(i <= mid)
	{
		temp[k++] = arr[i++];
	 } 
	while(j <= right)
	{
		temp[k++] = arr[j++];
	}
	for(int k = 0;k < len;k++)
	{
		arr[left++] = temp[k];
	}
}

void mergeSort(int arr[],int left,int right)
{
	if(left == right)
		return;
	int mid = (left + right) / 2;	// L和 R 中点的位置 （L+R）/ 2 
	mergeSort(arr,left,mid);		// T(n/2)
	mergeSort(arr,mid+1,right);		// T(n/2)
	Merge(arr,left,mid,right);		// O(N)
	// T(N) = 2 T(N/2) + O(N)
}

int main()
{
	int arr[] = {5,7,9,3,2,1};
	int n = sizeof(arr) / sizeof(int);
	 
	mergeSort(arr,0,n-1);
	printf("\n排好序的数组为：\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
 } 
