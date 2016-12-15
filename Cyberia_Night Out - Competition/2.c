#include<stdio.h>
void encode(int *n1,int *n2){
	*n2^=*n1;
	printf("%d %d",*n1,*n2);
}
void decode(int *n1,int *n2){
	*n2^=*n1;
	printf("\n%d %d",*n1,*n2);
}
int main(){
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	encode(&n1,&n2);
	decode(&n1,&n2);
}