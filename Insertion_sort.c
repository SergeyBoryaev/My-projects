#include<stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	printf("Initial array:\n");
    for(int i=0;i<N;i++)
		printf("%d ", arr[i]);
	int i, j, temp;
	for (i = 1; i < N; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < temp)
				break;
		arr[j + 1] = arr[j];
        arr[j] = temp;
		}
		printf("\nInsertion - Element #%d\n", i);
		for(int k=0;k<N;k++)
			printf("%d ", arr[k]);
	}
	printf("\n");
	return 0;
}