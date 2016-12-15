#include<stdio.h>
int arr[50][50];
int main(){
	int r,c,i,j,pool=0;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	for(i=1;i<r-1;i++)
		for(j=1;j<c-1;j++){
			if(arr[i][j]==0){
				if(arr[i][j-1]==1 && arr[i-1][j]==1)
					pool++;
			}
		}
	printf("%d",pool);
}