#include<stdio.h>
#include<string.h>
#include<ctype.h>
int ans[50];
int main(){
	char str[50][30],copyStr[50][30];
	int n,i,j,k,res=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf(" %[^\n]s",str[i]);
	for(i=0;i<n;i++){
		for(j=i+1;j<n ;j++){
			if(ans[j]==-1){
				continue;
			}
			res=0;
			for(k=0;str[i][k];k++)
				if(isalpha(tolower(str[i][k])))
					res^=tolower(str[i][k]);
			for(k=0;str[j][k];k++)
				if(isalpha(tolower(str[j][k])))
					res^=tolower(str[j][k]);
			if(res==0){
				ans[i]|=(1<<j);
				ans[j]=-1;
			}
			
		}
	}
	for(i=0;i<n;i++){
		if(ans[i]==-1 || ans[i]==0)
			continue;
		printf("%s",str[i]);
		for(j=1;j<n;j++){
			if(ans[i]&(1<<j))
				printf(", %s", str[j]);
		}
		printf(" are same\n");
	}
	return 0;
	
}