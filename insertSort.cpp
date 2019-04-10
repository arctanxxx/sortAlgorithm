// �������� 2019-04-09 

#include<stdio.h>

void insertSort(int *arr,int n)
{
	int tmp = 0;
	for(int i = 1;i<n;i++)				// �ӵڶ���Ԫ�ؿ�ʼ��ǰ���Ԫ�رȽ� 
	{
		int j = i - 1;					// ��ȡ��ǰԪ��ǰһ��Ԫ�ص��±� 
		if(arr[i] < arr[j])				// ��� arr[i] < arr[j](�����Ԫ��С��ǰ���Ԫ��)���򽻻�Ԫ��ֵ 
		{
			tmp = arr[i];				// ��¼��СԪ��ֵ��Ϊ�Ƚ϶��� 
			arr[i] = arr[j];			// ���ϴ�ֵ��ֵ�� arr[i] 
			while(tmp < arr[j-1])		// ���ý�С��ֵѭ���Ƚ�λ��ǰ���ֵ�����ǰ��Ԫ��ֵ��С��һֱ����ֵ���Ƚ� 
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = tmp;				// ����С��ֵ��Ӧλ�õ�Ԫ�� 
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
	printf("\n�ź��������Ϊ��\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
 } 
