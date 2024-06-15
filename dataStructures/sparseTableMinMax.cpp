
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
 
int query(int l, int r, vector<vector<int> > &arr){
	int msb=31-__builtin_clz(r-l+1);
	int uno=arr[l][msb];
	int dis=r-(l+(1<<msb))+1;
	int dos=arr[l+dis][msb];
	return max(uno,dos); // can change max->min
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // test array b:
  int n; cin>>n;
  vector<int> b(n);
  for (int &x:b) cin>>x;
  
  // sparse table: dp idea (when preprocessing)
  int LOG = log2(n)+2;
	vector<vector<int> > arr(n,vector<int>(LOG)); // table
	for (int i=0; i<n; i++){
		arr[i][0]=b[i]; // jump 2^0
	}
	for (int lev=1; lev<LOG; lev++){ // jump 2^i
		for (int j=0; j+(1<<lev)<=n; j++){
			arr[j][lev] = max(arr[j][lev-1],arr[j+(1<<(lev-1))][lev-1]); // can change max->min
		}
	}
  
  return 0;
}
