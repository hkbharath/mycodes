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
	double a,d;
	int n,dir=0;
	scanf("%lf%lf%d",&a,&d,&n);
	double tot=d;
	FOR(i,1,n){
		while(tot){
			if(tot > a){ 
				dir = (dir+1)%4;
				tot-=a;
				continue;
			}
			printf("%d ",dir);
			if(dir==0)
				printf("%lf %lf\n",0,tot);
			else if(dir==1)
				printf("%lf %lf\n",tot,a);
			else if(dir==2)
				printf("%lf %lf\n",a,a-tot);
			else 
				printf("%lf %lf\n",a-tot,0);
			tot=0;
		}
		tot=d-(a-tot);
	}
}

int main(){
	int t,it;
//	for(scanf("%d",&t),it=1;it<=t;it++)
		solve(it);
}
