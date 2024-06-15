#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
#define Bolivia_is_SIIUUUUUUUUUUUUU ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

const ll ba=53;
const ll modus[2]={1000000123, 1000000007}; // (MOD, mod)
ll invmod[2]; // (invMOD, invmod)

// IMPORTANT:
// position 0 works with MOD
// position 1 works with mod
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

ll getDig(char c){
	if (c<='Z') return c-'A'+1;
	return c-'a'+1 +26;
}

void Base(int N){ // here N=maximum size of some string
	invmod[0]=power(ba,modus[0]-2,0);
	invmod[1]=power(ba,modus[1]-2,1);
	
	for (int i=0; i<2; i++) pw[i].resize(N),invpow[i].resize(N);
	
	pw[0][0]=pw[1][0]=1;
	for (int i=1; i<N; i++) pw[0][i]=(pw[0][i-1]*ba)%modus[0], pw[1][i]=(pw[1][i-1]*ba)%modus[1];
	
	invpow[0][0]=invpow[1][0]=1;
	for (int i=1; i<N; i++) invpow[0][i]=(invpow[0][i-1]*invmod[0])%modus[0], invpow[1][i]=(invpow[1][i-1]*invmod[1])%modus[1];
}

void pre(int n, string s, vector<ll> HA[]){
	for (int i=0; i<2; i++) HA[i].resize(n);
	HA[0][0]=HA[1][0]=getDig(s[0]);
	for (int i=1; i<n; i++){
		HA[0][i]=(HA[0][i-1] + (getDig(s[i])*pw[0][i])%modus[0])%modus[0];
		HA[1][i]=(HA[1][i-1] + (getDig(s[i])*pw[1][i])%modus[1])%modus[1];
	}
}

ll getHashPos(int l, int r, int mo, vector<ll> HA[]){
	ll res=HA[mo][r];
	if (l>0) res=((res-HA[mo][l-1])%modus[mo]+modus[mo])%modus[mo];
	res=(res*invpow[mo][l])%modus[mo];
	return res;
}

pair<ll,ll> query(int l, int r, vector<ll> HA[]){ // from l to r inclusive [l,r]
	return pair<ll,ll>(getHashPos(l,r,0,HA), getHashPos(l,r,1,HA)); // (MOD,mod)
}

int main(){ // I'll become Candidate Master
	Bolivia_is_SIIUUUUUUUUUUUUU;
  
	string s; cin>>s;
	Base(s.size());
	vector<ll> ha1[2]; //, ha2[2];
	//string sr=s;
	//reverse(sr.begin(),sr.end());
	pre(s.size(),s,ha1); //pre(sr.size(),sr,ha2);

  return 0;
}
