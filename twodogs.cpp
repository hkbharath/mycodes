#include<cstdio>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int a[1000001],ga[500001];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",ga+i);
	for(int i=0;i<(n+1)/2;i++){
		if(!a[ga[i]])a[ga[i]]=i+1;
		if(!a[ga[n-i-1]])a[ga[n-i-1]]=i+1;
	}
	int ans=INT_MAX,f=0;
	for(int i=0;i<n;i++)
		if(k-ga[i]>0 && ga[i]!=k-ga[i] && a[k-ga[i]])
			ans=min(ans,max(a[ga[i]],a[k-ga[i]])),f=1;
	if(f)printf("%d\n",ans);
	else{
		if(!(k%2)){
			int x=0,z=0,c=0;
			for(int i=0;i<(n+1)/2;i++)
				if(ga[i]==k/2){
					if(!x)x=i+1;
					else if(!z)z=i+1;
					else break;
				}
			for(int i=0;i<n/2;i++)
				if(ga[n-i-1]==k/2){
					if(i+1<=x)z=x,x=i+1;
					else if(i+1<z)z=i+1;
				}			
			if(c>=2)
				printf("%d\n",z);
			else
				printf("-1\n");			
		}
		else
		printf("-1\n");
	}	
}
