// 2019-04-09 �������� 
/*
���̣������������ѡ��һ�����֣�С�ڵ��ڸ����ֵ�Ԫ�ط�������ߣ����ڵ��ڸ�Ԫ�ص����ַ����ұߣ� �ֱ�ݹ���������������� 
*/

#include<stdio.h>

// ����Ԫ��ֵ 
void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;	
}

// ���η��������Ϊ��������
int patition(int *arr,int left,int right)
{
	printf("\n");
	int j = left;						// ������������ 
	int i = j - 1;						// ����ָ����С��׼Ԫ�ص�λ�ã���һ��ûԪ��Ϊ-1��,ÿһ�εݹ���ö������¸�ֵ 
	printf("i = %d ",i);
	printf("left = %d ",left);
	printf("right = %d \n",right);
	int key = arr[right];				// ���һ��Ԫ��Ϊ��׼Ԫ�� 
	for (;j<right;++j)					// �����ұ������飬��С�ڵ��ڻ�׼Ԫ�صķŵ���ߣ����ڻ�׼Ԫ�طŵ��ұ� 
	{
		/*
		��ÿһ�ε��������У�
		��� arr[j] <= key �� i �� j ��ֵ��� 1��j = i+1������ʱͨ��  swap(&arr[j],&arr[++i]);��С�ڻ�׼��Ԫ�ط���ԭ��������λ���ϣ�
		��� arr[j] > key �� i �� j ��ֵ���2(j = i+2)����ʱͨ����һ��  swap(&arr[j],&arr[++i]);�����ڻ�׼��Ԫ����˿� a[j] �ϵ�Ԫ�ؽ�����
		*/
		if(arr[j] <= key)				// �����Ԫ��С�ڻ�׼Ԫ�� 
		{
			printf("arr[%d] = %d ",j,arr[j]);
			printf("key = %d \n",key);
			swap(&arr[j],&arr[++i]);	// ����Ԫ�طŵ���С��׼Ԫ��λ���� 
		}
	}
	swap(&arr[right],&arr[++i]);		// ����׼Ԫ�طŵ��м� 
	return i;							// ���������м�λ�� 
 } 
 
// �������� 
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
	printf("\n�ź��������Ϊ��\n");
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
 } 
 
 /*
��ӡʵ�ֹ��̣� 
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

�ź��������Ϊ��
1 2 5 6 7 10 12 23 34 45 56 63 98 99
 */ 
