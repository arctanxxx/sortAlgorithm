// 2019-04-09 ц╟ещеепР 
#include<stdio.h>

void bubbleSort(int *arr,int n)
{
	for	(int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {1,5,4,8,2,10,9,6,7,3};
	int n = sizeof(arr) / sizeof(int);
	bubbleSort(arr,n); 
	
	for(int j = 0;j<n;j++)
		printf("%d ",arr[j]);
		
	printf("\n");
	return 0;
}
