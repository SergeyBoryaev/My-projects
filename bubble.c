#include<stdio.h>
#define N 5
int main(){
	int l;
	int a[N];
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(a[j]>a[j+1]){
				l=a[j];
				a[j]=a[j+1];
				a[j+1]=l;
			}
		}
	}
	for(int i=0;i<N;i++)
		printf("%d",a[i]);
}