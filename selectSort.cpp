// ѡ������ 2019-04-09
// ����ѡ����С���������������ǰ��

#include<stdio.h>

void selectSort(int *arr,int n)
{
	for(int i = 0;i < n;i++)		 
	{
		int key = i;				// �� key ��¼��СԪ������ 
		for(int j = i+1;j<n;j++) 	// �ӵڶ���Ԫ�����ʼѰ�� 
		{
			key = arr[j] < arr[key] ? j : key;
			/*
			if(arr[j] < arr[key])	// ����ҵ��� arr[key] С��Ԫ�� 
			{
				key = j;			// ��ʱ����СԪ�����긳ֵ�� key 
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
	printf("\n�ź��������Ϊ��\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
