#include<stdio.h>
int main(){
	long long f[1000001];
	f[0]=1,f[1]=1;
	for(int i=2;i<1000001;i++)
		f[i]=(f[i-1]+f[i-2])%1000000007;
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",f[x]);
	}
}
