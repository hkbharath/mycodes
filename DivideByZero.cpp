// BEGIN CUT HERE

// END CUT HERE
#line 5 "DivideByZero.cpp"

#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

class DivideByZero {
	public:
	int CountNumbers(vector <int> numbers) {
		int x, n=numbers.size(),ct=0;
		int present[101]={0};
		//sort(numbers.begin(),numbers.end());
		for(int i=0;i<n;i++)present[numbers[i]]++,printf("%d ",numbers[i]);
		printf("\n");
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			 if(numbers[j]>numbers[i]){
			 	x=numbers[j]/numbers[i];
			 	if(!present[x])
			 		numbers.push_back(x),ct++,present[x]++;
			 }
		}
		if(ct==0)return n;
		return CountNumbers(numbers);
	}
};
