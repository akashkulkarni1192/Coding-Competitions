#include<stdio.h>
void display(int low,int high){
	int mid;
	if(low<=high){
		mid=(low+high)/2;
		printf("%d ",mid);
		display(low,mid-1);
		display(mid+1,high);
	}
}
int main(){
	int n,a,b,low,high,mid;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		display(1,a);
		printf("\n");
	}
}