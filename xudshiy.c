// worst case for qsort with midle pivot
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
   int N;
   scanf("%d", &N);
   int xydmas[N],k=N-1;
   for(int i=k;i>0;i--)
      if(i%2==1){
         k=i;
         break;
      }
   xydmas[(N-1)/2]=N;
   for(int i=0;i<(N-1)/2;i++)
      xydmas[i]=2*(i+1);
   for(int i=((N-1)/2+1);i<N;i++){
      xydmas[i]=k;
      k-=2;
   }
   for(int i=0;i<N;i++)
      printf("%d ",xydmas[i]);
}