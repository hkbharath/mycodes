#include<cstdio>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int a[1001],b[1001][1001],c[1001][1001],x[1001];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k,i,j;
		scanf("%d%d%d",&n,&m,&k);
		int pb=0;
		for(i=0;i<n;i++)scanf("%d",a+i);
		for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&b[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&c[i][j]);
		for(i=0;i<n;i++){
			x[i]=b[i][a[i]-1];
			for(j=0;j<m;j++){
				x[i] =( x[i]>=b[i][j]-c[i][j]?x[i]:b[i][j]-c[i][j]);
			}
			x[i]=x[i]-b[i][a[i]-1];
			pb+=b[i][a[i]-1];
		}
		sort(x,x+n);
		//if(0)for(i=0;i<n;i++)printf("%d. ",x[i]);
		for(i=1;i<=k && i<=n ;i++)pb+=x[n-i];
		printf("%d\n",pb);				
	}
}
