#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>

using namespace std;

int w[50001],s1,s2,t,c[50001],v[50001],x;
vector <int> adj[50001],q;

void unn(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void init(){
	c[0]=0;c[1]=0;c[2]=1;
	for(int i=3;i<50001;i++)
		c[i]=c[i-1]+i-1;	
}

void dfs(int a){
	if(w[a])t++;
	v[a]=1;
	int n=adj[a].size();
	for(int i=0;i<n;i++)
		if(!v[adj[a][i]])dfs(adj[a][i]);		
}				

void dfs2(int a){
	v[a]=1;
	if(w[a])x=1;
	int n=adj[a].size();
	for(int i=0;i<n && !x;i++)
		if(!v[adj[a][i]])dfs2(adj[a][i]);
}
		
int main(){
	int n,m,a,b;
	init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",w+i);
	
	while(m--){
		scanf("%d%d",&a,&b);
		unn(a-1,b-1);
	}
	for(int i=0;i<n;i++)
		if(!v[i]){
			t=0;
			dfs(i);
		//	printf("%d.. ",t);
			s1+=c[t];
		//	for(int j=0;j<n;j++)printf("v %d ",v[j]);
		}	
	int y=0,p,s;	
	for(int i=0;i<n;i++){
		memset(v,0,sizeof(v));
		y=0;	
		v[i]=1;
		p=adj[i].size();
		if(w[i])y++;
		for(int j=0;j<p && y<2;j++){
			x=0;
			dfs2(adj[i][j]);
			if(x)y++;
		}		
		if(y>1)s2++;
	}			
	printf("%d %d\n",s1,s2);
}		
