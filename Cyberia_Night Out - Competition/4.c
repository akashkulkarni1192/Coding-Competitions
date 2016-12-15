#include<stdio.h>
#include<ctype.h>
char str[50][50];
int row[50],col[50];
int main(){
	int i,j,k=0,r,c;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			scanf("%c",&str[i][j]);
			if(!isalpha(str[i][j])){
				j--;
				continue;
			}
			if(str[i][j]=='Z'){
				row[k]=i;
				col[k++]=j;
			}
		}
	for(i=0;i<k;i++)
		for(j=0;j<c;j++)
			str[row[i]][j]='X';
	for(i=0;i<k;i++)
		for(j=0;j<r;j++)
			str[j][col[i]]='X';
	printf("\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%c ",str[i][j]);
		printf("\n");
	}
	return 0;
}