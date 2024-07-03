/*
EL BICHO⠀⠀⠀⠀⣴⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦⠀
⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿
⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀
⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀
⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆⠂⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀
⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀
⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀
⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀
⠀⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤⠄
¡SIIUUUUUUUUUUUUU!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
#define Bolivia_is_nice ios::sync_with_stdio(0); cin.tie(0)

const int NAX = 200002;
vector<int> st(NAX*4), lazy(NAX*4);
const int INF = 1000000000;

void Erase(set<int>&se, int x){
	auto fi=se.find(x);
	if (fi==se.end()) return;
	se.erase(fi);
}

void build(int node, int l, int r, vector<int>&a){
	if (l==r){
		st[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid,a);
	build(node*2+1,mid+1,r,a);
	st[node]=min(st[node*2],st[node*2+1]);
}

void prop(int node, int l, int r){
	if (lazy[node]){
		st[node]+=lazy[node];
		if (l!=r){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void Merge(int node, int l, int r){
	int mid=(l+r)/2;
	prop(node*2,l,mid);
	prop(node*2+1,mid+1,r);
	st[node]=min(st[node*2],st[node*2+1]);
}

int query(int node, int l, int r, int xl, int xr){
	prop(node,l,r);
	if (xl<=l && r<=xr) return st[node];
	int mid=(l+r)/2;
	int ans=INF;
	if (xl<=mid) ans=min(ans,query(node*2,l,mid,xl,xr));
	if (xr>=mid+1) ans=min(ans,query(node*2+1,mid+1,r,xl,xr));
	Merge(node,l,r);
	return ans;
}

void update(int node, int l, int r, int xl, int xr, int delta){
	prop(node,l,r);
	if (xl<=l && r<=xr){
		st[node]+=delta;
		if (l!=r){
			lazy[node*2]+=delta;
			lazy[node*2+1]+=delta;
		}
		return;
	}
	int mid=(l+r)/2;
	if (xl<=mid) update(node*2,l,mid,xl,xr,delta);
	if (xr>=mid+1) update(node*2+1,mid+1,r,xl,xr,delta);
	Merge(node,l,r);
}

int val;
void bs(int node, int l, int r){
	prop(node,l,r);
	if (l==r){
		val=l;
		return;
	}
	Merge(node,l,r);
	int mid=(l+r)/2;
	if (st[node*2]<0) bs(node*2,l,mid);
	else bs(node*2+1,mid+1,r);
}

void solve(){
	int n,q; cin>>n>>q;
	string s; cin>>s;
	vector<int> pref(n);
	if (s[0]=='(') pref[0]=1;
	else pref[0]=-1;

	for (int i=1; i<n; i++) pref[i]=pref[i-1]+(s[i]=='('? 1:-1);

	set<int> o,c;
	for (int i=0; i<n-1; i++){
		if (s[i]==s[i+1]){
			if (s[i]=='(') o.insert(i);
			else c.insert(i);
		}
	}
	
	build(1,0,n-1,pref);
	for (int i=0; i<=4*n; i++) lazy[i]=0;
	while(q--){
		int x; cin>>x; x--;
		for (int i=x-1; i<=x; i++){
			if (i<0) continue;
			Erase(o,i);
			Erase(c,i);
		}
		if (s[x]=='(') s[x]=')', update(1,0,n-1,x,n-1,-2);
		else s[x]='(', update(1,0,n-1,x,n-1,+2);
		for (int i=x-1; i<=x; i++){
			if (i<0) continue;
			if (i+1<n){
				if (s[i]==s[i+1]){
					if (s[i]=='(') o.insert(i);
					else c.insert(i);
				}
			}
		}

		int pr=query(1,0,n-1,n-1,n-1);
		if (pr%2!=0){
			cout<<"NO\n";
			continue;
		}
		
		int minall=query(1,0,n-1,0,n-1);
		if (minall>=0){
			if (pr==0){
				cout<<"YES\n";
			}else{
				if (c.size()){
					auto en=c.end(); en--;
					int closest=*en;
					int minirange=query(1,0,n-1,closest,n-1);
					if (pr<=minirange) cout<<"YES\n";
					else cout<<"NO\n";
				}else{
					cout<<"NO\n";
				}
			}
		}else{
			if (o.size()){
				int clo=*o.begin();
			    bs(1,0,n-1);
				if (clo>val){
					cout<<"NO\n";
				}else{
					int miniran=query(1,0,n-1,val,n-1);
					if (pr==miniran){
						cout<<"YES\n";
					}else{
						if (c.size()){
							auto en=c.end(); en--;
							int closest=*en;
							int minirange=query(1,0,n-1,closest,n-1);
							if (pr<=minirange) cout<<"YES\n";
							else cout<<"NO\n";
						}else{
							cout<<"NO\n";
						}
					}
				}
			}else cout<<"NO\n";
		}
	}
}
 
int main(){
	Bolivia_is_nice;

	int t=1;// cin>>t;
	while(t--) solve();
 
	return 0;
}
// el monito araña uwu
