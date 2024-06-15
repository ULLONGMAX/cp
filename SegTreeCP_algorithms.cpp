// cool submission with lazy and BS in ST: https://codeforces.com/contest/1838/submission/208644188
#include <bits/stdc++.h>
using namespace std;

const int NAX = 101;
vector<int> a(NAX);
vector<int> st(NAX*4);

void build(int node, int l, int r){
	if (l==r){
		st[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	st[node]=st[node*2]+st[node*2+1];
}

int query(int node, int l, int r, int xl, int xr){
	if (xl<=l && r<=xr) return st[node]; // this case is FIRST because instead of calling left or right child and waste time
	int ans=0; // for merging from any child (left or right) when necessary
	int mid=(l+r)/2;
	if (xl<=mid) ans+=query(node*2,l,mid,xl,xr); // some part of [xl,xr] lies on left child
	if (xr>mid) ans+=query(node*2+1,mid+1,r,xl,xr); // some part of [xl,xr] lies on right child
	return ans;
}

void update(int node, int l, int r, int pos, int newval){
	if (l==r){
		st[node]=newval;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) update(node*2,l,mid,pos,newval); // pos lies on left child
	else update(node*2+1,mid+1,r,pos,newval); // pos lies on right child
	st[node]=st[node*2]+st[node*2+1]; // merge updated values
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
	build(1,0,n-1);
	cout<<query(1,0,n-1,0,4)<<'\n';
	update(1,0,n-1,1,100);
	cout<<query(1,0,n-1,1,3)<<'\n';
	
	return 0;
}
