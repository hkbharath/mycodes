#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		vector<int> srt;
		scanf("%d",&n);
		int ar[n+1];
		for(int i=0;i<n;i++)scanf("%d",ar+i);
		int q;
		scanf("%d",&q);
		while(q--){
			int d,x,y,k;
			scanf("%d",&d);
			if(d){
				scanf("%d%d",&x,&k);
				ar[x-1]=k;
			}
			else{
				scanf("%d%d%d",&x,&y,&k);
				srt.clear();
				for(int i=x-1;i<y;i++)
					srt.push_back(ar[i]);
				sort(srt.begin(),srt.end());
				printf("%d\n",srt[k-1]);	
			}
		}
	}

}
