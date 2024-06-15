#include <bits/stdc++.h>
using namespace std;

vector<int> processOdd(string s){
	string t="$"+s+"%";
	int n=t.size();
	vector<int> dp(n);
	int l=-1,r=-1; // (l,r)
	for (int i=1; i<n-1; i++){ // note that we start at 1 and end at n-2 for avoiding RTE
		if (i<r){ // retrieve dp mirror
			dp[i]=min(dp[l+r-i],r-i);
		}
		// always try to expand current (brute force algorithm):
		while(t[i+dp[i]]==t[i-dp[i]]) dp[i]++;
		// update r max:
		if (i+dp[i]>r){
			r=i+dp[i];
			l=i-dp[i];
		}
	}
	return dp;
}

vector<int> manacher(string s){
	string t="";
	for (char c:s){
		t.push_back('#');
		t.push_back(c);
	}
	t+="#";
	return processOdd(t);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s; cin>>s;
	int n=s.size();
	vector<int> arr=manacher(s);
	for (int i=1; i<(int)arr.size()-1; i++){ // BOUNDS DEPEND ON WHAT YOU ARE GOING TO DO
		if (arr[i]&1){ // pal=even (string[i]='#')
			int sz=arr[i]/2*2; // current size of LPSubstring
      
		}else{ // pal=odd (string[i]=LETTER)
			int sz=(arr[i]-2)/2*2+1; // current size of LPSubstring
      
		}
	}
	
	return 0;
}
