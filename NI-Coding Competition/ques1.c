// Name: Akash Kulkarni
// USN: 4jc11cs006
// Summary: 

#include <stdio.h>
#include<string.h>
#define MAX_SIZE 100

// Remove additional scanf/printf before submission.
char* WhoWins(char arr[][MAX_SIZE], int n, int k)
{
	// Write your code here.
	int i,j,m,charPos,dotPos;
	char tempArr[MAX_SIZE][MAX_SIZE];
	for(i=0;i<n;i++){
		charPos=strlen(arr[i])-1;
		j=strlen(arr[i])-1;
		while(charPos >=0 && j>=0){
			for(;charPos>=0 && arr[i][charPos]=='.';charPos--);
			if(charPos==-1)
				break;
			for(;j>=0 && arr[i][j]!='.';j--);
			if(charPos<j)
				arr[i][j]=arr[i][j]+arr[i][charPos]-(arr[i][charPos]=arr[i][j]);
			else
				charPos--;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1 && arr[i][j]==arr[i][j+1] && arr[i][j]!='.';j++);
		if(j==n-1)
			return (arr[i][j-1]=='W')?"White":"Black";
		for(j=0;j<n-1 && arr[j][i]==arr[j+1][i] && arr[j][i]!='.';j++);
		if(j==n-1)
			return (arr[i][j-1]=='W')?"White":"Black";
		for(j=0;j<n-1 && arr[j][j]==arr[j+1][j+1] && arr[j][j]!='.';j++);
		if(j==n-1)
			return (arr[i][j-1]=='W')?"White":"Black";
		for(j=0,m=n-1;j<n-1 && m>0 && arr[j][m]==arr[j+1][m-1] && arr[j][m]!='.';j++,k--);
		if(j==n-1)
			return (arr[i][j-1]=='W')?"White":"Black";

	}
    return "None";
}

int main(void){

	int i, j, n, k;
	scanf("%d%d", &n, &k);
	char arr[MAX_SIZE][MAX_SIZE];
	
	for(i = 0; i<n; i++)
	{
	    scanf("%s", arr[i]);	        	    
	}
	printf("%s\n",WhoWins(arr, n, k));
		
	return 0;
}
