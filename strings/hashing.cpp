#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front

const ll ba=31; // normally used for alphabet with 26 letters
const ll modus[2]={1000000123, 1000000007}; // (MOD, mod)
ll invmod[2]; // (invMOD, invmod)

// IMPORTANT:
// position 0 works with MOD
// position 1 works with mod
vector<ll> ha[2];
vector<ll> pw[2];
vector<ll> invpow[2];

ll power(ll b, ll ex, int mo){
	ll res=1;
	while(ex){
		if (ex&1) res=(res*b)%modus[mo];
		ex>>=1;
		b=(b*b)%modus[mo];
	}
	return res;
}

void pre(int n, string s){
	invmod[0]=power(ba,modus[0]-2,0);
	invmod[1]=power(ba,modus[1]-2,1);
	
	for (int i=0; i<2; i++) ha[i].resize(n);
	for (int i=0; i<2; i++) pw[i].resize(n),invpow[i].resize(n);
	
	pw[0][0]=pw[1][0]=1;
	for (int i=1; i<n; i++) pw[0][i]=(pw[0][i-1]*ba)%modus[0], pw[1][i]=(pw[1][i-1]*ba)%modus[1];
	
	invpow[0][0]=invpow[1][0]=1;
	for (int i=1; i<n; i++) invpow[0][i]=(invpow[0][i-1]*invmod[0])%modus[0], invpow[1][i]=(invpow[1][i-1]*invmod[1])%modus[1];
	
	ha[0][0]=ha[1][0]=s[0]-'a'+1; // we can change the -'a'
	for (int i=1; i<n; i++){
		ha[0][i]=(ha[0][i-1] + ((ll)(s[i]-'a'+1)*pw[0][i])%modus[0])%modus[0];
		ha[1][i]=(ha[1][i-1] + ((ll)(s[i]-'a'+1)*pw[1][i])%modus[1])%modus[1];
	}
}

ll getHashPos(int l, int r, int mo){
	ll res=ha[mo][r];
	if (l>0) res=((res-ha[mo][l-1])%modus[mo]+modus[mo])%modus[mo];
	res=(res*invpow[mo][l])%modus[mo];
	return res;
}

pair<ll,ll> query(int l, int r){ // from l to r inclusive [l,r]
	return pair<ll,ll>(getHashPos(l,r,0), getHashPos(l,r,1)); // (MOD,mod)
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	// read data:
	int n; cin>>n; // n = strlen(s)
	string s; cin>>s;
	
	//
	pre(n,s);
	
	return 0;
}
// NK
