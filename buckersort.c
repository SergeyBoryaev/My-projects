#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void arrSort(float *arr,int size){
	int i, j;
	float temp;
	for (i = 1; i < size; i++){
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < temp)
				break;
		arr[j + 1] = arr[j];
        arr[j] = temp;
		}
	}
}
int main(){
	int N,b;
	scanf("%d",&N);
	float arr[N],buck[2*N][N],localbuck[N];
	int si[2*N];
	for(int i=0;i<N; i++)
		scanf("%f",&arr[i]);
	printf("Initial array:\n");
	for(int i=0;i<N;i++)
		printf("%.2f ", arr[i]);
	printf("\n\n");
	float min=arr[0],max=arr[0];
	for(int i=0;i<N; i++){
		if(arr[i]>max)
			max=arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	for(int i=0;i<2*N;i++)
		si[i]=0;
	int numberBuck;
	for(int i=0;i<N;i++){
		//if(min==max)
		//	numberBuck=0;
		//else
		numberBuck=(int)(((arr[i]-min)*2*N)/(max-min));
		if(arr[i]==max){
			buck[2*N-1][si[2*N-1]]=arr[i];
			si[2*N-1]++;
		}
		else{
			buck[numberBuck][si[numberBuck]]=arr[i];
			si[numberBuck]++;
		}
	}
	for(int i=0;i<2*N;i++){
		for(int j=0;j<si[i];j++)
			localbuck[j]=buck[i][j];
		if(si[i]!=0){
			printf("Bucket:\n");
			for(int j=0;j<si[i];j++)
				printf("%.2f ",localbuck[j]);
		    printf("\n");
        }
		arrSort(localbuck,si[i]);
		if(si[i]!=0){
			printf("Sorted bucket:\n");
			for(int j=0;j<si[i];j++)
				printf("%.2f ",localbuck[j]);
		    printf("\n\n");
        }
		for(int j=0;j<si[i];j++)
			buck[i][j]=localbuck[j];
	}
	int k=0;
	for(int i=0;i<2*N;i++)
		for(int j=0;j<si[i];j++)
			arr[k++]=buck[i][j];
	printf("Final array:\n");
	for(int i=0;i<N;i++)
		printf("%.2f ", arr[i]);
	return 0;
}