// this solves the version of problem parquet using 2x1 and 1x2 dominoes (count the number of ways in which you can fully fill an nxm grid)

#include <bits/stdc++.h>
using namespace std;

int n=33,m=3;
// dp[i][mask] = total # of ways to fill the prefix making i-1 a "perfect" subgrid and mask being the last-put dominoes "heads"
vector< vector<long long> > dp(n, vector<long long>(1<<m));

void calc(int pos, int bit, int mask, int next_mask){
	if (bit>=m){ // mask is full of 1's now
		dp[pos+1][next_mask] += dp[pos][mask];
		return;
	}
	// brute force putting the dominoes recursively:
	int new_on = (1<<bit);
	if ((new_on & mask)){
		calc(pos, bit+1, mask, next_mask);
	}else{
		// put horizontally:
		calc(pos, bit+1, mask, (next_mask | new_on));
		// put vertically:
		if (bit+1<m && !(bool)(mask & (1<<(bit+1))) )
			calc(pos, bit+2, mask, next_mask);
	}
}

int main(){
	dp[0][0]=1;
	for (int i=0; i<n-1; i++) // n-1 is important to prevent RTE
		for (int mask=0; mask<(1<<m); mask++)
			calc(i,0,mask,0);
	
	/*
	int q;
	while(scanf("%d", &q) != EOF){
		if (q==-1) return 0;
		printf("%d\n", dp[q][0]);
	} */
	return 0;
}
