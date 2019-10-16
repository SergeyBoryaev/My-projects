#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 101
void removezero(char arr[F][F],int N,int max){
	for(int i=0;i<N;i++){
		while(arr[i][0]=='0'){
			for(int j=0;j<strlen(arr[i])-1;j++)
				arr[i][j]=arr[i][j+1];
			arr[i][strlen(arr[i])-1]='\0';
		}
	}
}

void addzero(char arr[F][F],int N, int max){
	for(int i=0;i<N;i++){
		if(strlen(arr[i])<max){
			int size=strlen(arr[i]);
			while(strlen(arr[i])<max){
				for(int j=strlen(arr[i]);j>0;j--)
					arr[i][j]=arr[i][j-1];
				arr[i][0]='0';
			}
		}
	}
}

void swap(char arr[F][F],int k,int max,int arr_size[]){
	char s[max];
	for(int i=0;i<max;i++){
		s[i]=arr[k][i];
	}
	for(int i=0;i<max;i++){
		arr[k][i]=arr[k+1][i];
	}
	for(int i=0;i<max;i++){
		arr[k+1][i]=s[i];
	}
	int tmp=arr_size[k];
	arr_size[k]=arr_size[k+1];
	arr_size[k+1]=tmp;
}

void radixsort(char arr[F][F], int N, int arr_size[]){
	int max=strlen(arr[N-1]);
	for(int i=0;i<N;i++)
		if(strlen(arr[i])>max)
			max=strlen(arr[i]);
	for(int i=max-1;i>=0;i--){
		printf("Sorting by %d digit:\n",i);
		addzero(arr,N,max);
		for(int j=0;j<N-1;j++)
			for(int k=0;k<N-j-1;k++)
				if((arr[k][i]>arr[k+1][i])||((arr[k][i]==arr[k+1][i])&&(arr_size[k]>=(max-i)))&&(arr_size[k+1]<(max-i))){
					swap(arr,k,max,arr_size);
				}
		removezero(arr,N,max);
		for(int j=0;j<N;j++)
    		printf("%s\n", arr[j]);
		printf("\n");
	}
}

int main(){
	int N;
	scanf("%d",&N);
	char str_arr[F][F];
	for(int i=0;i<N;i++)
    	scanf("%s",str_arr[i]);
	int arr[N];
	for(int i=0;i<N;i++)
		arr[i]=strlen(str_arr[i]);
	radixsort(str_arr, N, arr);
	
}