#include<stdio.h>
#include<math.h>
int main(){
	int n,arr[20],i,j,pick,bit[20],counter=0,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		pick=arr[i];
		k=0;
		for(j=8;j--;(pick&(1<<j))?bit[k++]=1:bit[k++]=0);
		bit[k]='\0';
		printf("\n j= %d k= %d ",j,k);
		for(j=0;bit[j]!='\0';j++)
			putchar(bit[j]);
		printf("\n j= %d k= %d ",j,k);
	}

	return 0;
}