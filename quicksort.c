#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define F 101
void quicksort(int number[],int first,int last,int size){
    if(first<last){
        int bufright[F],bufleft[F],l=first,r=first,mid;
        mid=(first+last)/2;
        int piv = number[mid];
        for(int i=first;i<mid;i++)
            if(number[i]>piv){
                bufright[r]=number[i];
                r++;
            }
            else{
                bufleft[l]=number[i];
                l++;
            }
        for(int i=(mid+1);i<=last;i++)
            if(number[i]>piv){
                bufright[r]=number[i];
                r++;
            }
            else{
                bufleft[l]=number[i];
                l++;
            }
        bufleft[l]=piv;
        for(int i=first;i<=l;i++)
            number[i]=bufleft[i];
        if(r!=first)
            for(int i=l+1;i<=last;i++)
                number[i]=bufright[i-l-1];
        printf("Pivot index: %d , pivot element: %d\n",mid, piv);
        printf("Array after partition: ");
        for(int m=0;m<size;m++)
            printf("%d ",number[m]);
        printf("\n\n");
        quicksort(number,first,l-1,size);
        quicksort(number,l+1,last,size);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    int(arr[F]);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("Initial array:\n");
	for(int i=0;i<N;i++)
	    printf("%d ", arr[i]);
	printf("\n\n");
    quicksort(arr,0,N-1,N);
    return 0;
}