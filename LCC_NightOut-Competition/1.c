#include<stdio.h>
int main(){
	int n,len=0,i,j,k;
	char str[10][50],ans[10][50],ch;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		len=0;
		while((ch=getchar())!='\n')
			putchar(str[i][len++])=ch;
		str[i][len]='\0';
	}
	for(i=0;i<n;i++){
		for(len=0;str[i][len];len++);
		for(j=0,k=len-1;k>=0 && str[i][j]!='\0';j++){
			if(str[i][k]==' '){
				k--;
			}
			if(str[i][j]!=' ')
				ans[i][j]=str[i][k--];
			else
				ans[i][j]=' ';

		}
		ans[i][len]='\0';
	}
	for(i=0;i<n;i++){
		printf("\n%s",ans[i]);
	}
}