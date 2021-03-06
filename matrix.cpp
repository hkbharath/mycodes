/**
 *	Author : hkbharath
 *	Problem : FLIP MATRIX CodeForces #238-D2
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

int n,sols[10001][4],mat[1000][1000],frow[1001],fcol[1001];

void solve(int tt){
	scanf("%d",&n);
	FOR(i,0,n-1)FOR(j,0,n-1) scanf("%d",mat[i]+j);
	FOR(i,0,n-1){		
		FOR(j,0,n-1){
			sols[i][0] = (sols[i][0]+mat[i][j]*mat[j][i])%2;
			sols[i][1] = (sols[i][1]+mat[i][j]*!(mat[j][i]))%2;
			sols[i][2] = (sols[i][2]+!(mat[i][j])*mat[j][i])%2;
			if(i!=j)sols[i][3] = (sols[i][3]+!(mat[i][j])*!(mat[j][i]))%2;
			else sols[i][3] = (sols[i][3]+(mat[i][j])*(mat[j][i]))%2;
		}
		printf("%d => %d %d %d %d\n",i,sols[i][0],sols[i][1],sols[i][2],sols[i][3]);
	}	
	int q;
	scanf("%d",&q);
	while(q--){
		int op,sel;
		scanf("%d",&op);
		if(op==1){scanf("%d",&sel);frow[sel-1] = (frow[sel-1]+1)%2;}
		else if(op==2){scanf("%d",&sel);fcol[sel-1]= (fcol[sel-1]+1)%2;}
		else{
			int sol=0;
			FOR(i,0,n-1){
				if(!(frow[i]) && !(fcol[i])) sol=(sol+sols[i][0]);
				else if(!(frow[i]) && fcol[i]) sol=(sols[i][1]+sol);
				else if(frow[i] && !(fcol[i])) sol=(sols[i][2]+sol);
				else sol=(sol+sols[i][3]);
				
			}
			printf("%d",(sol%2));
		}
	}
}

int main(){
	int t,it;
//	for(scanf("%d",&t),it=1;it<=t;it++)
		solve(it);
}
