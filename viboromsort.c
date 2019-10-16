#include<stdio.h>
#define N 5
int main(){
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(a[i]>a[j]){
				a[i]+=a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	for(int i=0;i<N;i++){
		printf("%d",a[i]);
	}
}
