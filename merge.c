#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include<stdio.h> 
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l+1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    printf("Left part: ");
    for(i = 0;i<n1;i++)
        printf("%d ",L[i]);
    printf("\n");
    printf("Right part: ");
    for(i = 0;i<n2;i++)
        printf("%d ",R[i]);
    printf("\n");
    printf("Merged parts: ");
    for(i = l;i<l+n2+n1;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
} 
 
void mergeSort(int arr[], int l, int h) { 
    if (l != h) {
        int m = (int)(((float)(h+l)/2)+0.5);
        if(m!=l){
        mergeSort(arr, l, m-1);
        mergeSort(arr,m,h);
        merge(arr,l,m-1,h);
        }
        else{
            mergeSort(arr, l, m);
            mergeSort(arr,m+1,h);
            merge(arr,l,m,h);
        }
    } 
} 

int main() 
{ 
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);  
    printf("Initial array:\n");
	for(int i=0;i<N;i++)
	    printf("%d ", arr[i]);
	printf("\n\n");
    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);  
}