/**
 *	Author : hkbharath
 *	Problem :
 *	Lang : C++
 */	

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <map>
#include <cassert>
#include <queue>

#define FOR(a,b,c) for(int a=b;a<=c;++a)
#define RFOR(a,b,c) for(int a=b;a>=0;--a)
#define PB(a,b) a.push_back(b);
#define MP(a,b) make_pair(a,b);
#define MOD 1000000007

typedef long long int64;

using namespace std;

void solve(int tt){
	int n,al,ar,x,y;
	scanf("%d",&n);
	scanf("%d%d",&al,&ar);
	int cnt[101]={0};
	FOR(i,0,n-2){
		scanf("%d%d",&x,&y);
		FOR(j,x,y-1)cnt[j]+=1;
	}	
	int ans=0;
	FOR(i,al,ar-1)
		if(!cnt[i])ans++;
	printf("%d\n",ans);
}

int main(){
	int t,it=1;
//	for(scanf("%d",&t),it=1;it<=t;it++)
		solve(it);
}
