#include<stdio.h>
int arr[50][50];
int row,col;
int min=999;
void minPath(int arr[50][50],int r,int c,int sum){
	
	if(r==row || c==col)
		return;
	if(r==row-1 && c==col-1){
		if(sum<min)
			min=sum;
		return;
	}
	if(r<2)
		minPath(arr,r+1,c,sum+arr[r+1][c]);
	if(c<2)
		minPath(arr,r+1,c,sum+arr[r][c+1]);
	if(r<2 && c<2)
		minPath(arr,r+1,c+1,sum+arr[r+1][c+1]);
}
int main(){
	int i,j;
	scanf("%d %d",&row,&col);
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
	minPath(arr,0,0,0);
	printf("%d",min);
	return 0;
}