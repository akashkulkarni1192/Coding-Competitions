#include<stdio.h>
int matr[50][50];
void rotate(int matr[50][50],int n){
	int i,j,temp,layer,first,last,offset;
	for(layer=0;layer<n/2;layer++){
		first = layer;
		last = n- layer-1;
		for(i=first;i<last;i++){
			offset = i -first;
			temp = matr[first][i];
			matr[first][i] = matr[last-offset][first];
			matr[last-offset][first] = matr[last][last-offset];
			matr[last][last-offset] = matr[i][last];
			matr[i][last] = temp;
		}
	}
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matr[i][j]);
	rotate(matr,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",matr[i][j]);
		printf("\n");
	}
	return 0;
}