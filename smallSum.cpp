// 最小和问题
 /*
 描述：在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组 的小和。
 例子： [1,3,4,2,5] 
 1左边比1小的数，没有； 
 3左边比3小的数，1； 
 4左边比4小的数，1、3； 
 2左边比2小的数，1； 
 5左边比5小的数，1、3、4、2； 
 所以小和为1+1+3+1+1+3+4+2=16
 */ 
 
#include<stdio.h>

int merge(int *arr,int l,int m,int r)
{
	int *help = new int[r-l+1];
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	int res = 0;
	
	while(p1 <= m && p2 <= r)
	{
		res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while(p1 <= m)
	{
		help[i++] = arr[p1++];
	}
	while(p2 <= r)
	{
		help[i++] = arr[p2++];
	}
	for(int k = 0;k<r-l+1;k++)
	{
		arr[l+k] = help[k];
	}
	return res;
}


int mergeSort(int *arr,int l,int r)
{
	if(l == r)
		return 0;
	int mid = (l+r) / 2;
	return mergeSort(arr,l,mid) + mergeSort(arr,mid+1,r) + merge(arr,l,mid,r);
}


int smallSum(int *arr,int len)
{
	if(arr == NULL || len < 2)
		return 0;
	return mergeSort(arr,0,len - 1);
 } 

int main()
{
	int arr[] = {1,3,4,2,5};
	int len = sizeof(arr) / sizeof(int);
	printf("len = %d\n",len);
	int smallsumRes = smallSum(arr,len);
	printf("res = %d \n",smallsumRes);
	return 0;
 } 
