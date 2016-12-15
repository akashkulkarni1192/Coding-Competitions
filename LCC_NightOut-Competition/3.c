#include<stdio.h>
int main(){
	int n,matrix[10][10][20],i,j,m,p,q,l,flag;
	scanf("%d",&n);
	for(l=0;l<n;l++){
		scanf("%d",&m);
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				scanf("%d",&matrix[l][i][j]);
	}
	for(l=0;l<n;l++){
		for(m=0;matrix[l][0][m];m++);
		flag=0;
		for(i=0;i<=m/2 && flag==0;i++){
			for(p=0,q=m-1;p<m && q>=0 && flag==0;p++,q--)
				if(matrix[l][i][p]!=matrix[l][m-1-i][q]){
					flag=1;
				}
		}
		if(flag)
			printf("\n0");
		else
			printf("\n1");
	}
	return 0;
}