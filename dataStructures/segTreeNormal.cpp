#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front

void Merge(int node, int l, int r){
	if (l==r){
    
	}else{
	    
	}
}

void update(int node, int l, int r, int pos){ // single point update
    if (l>pos || r<pos) return;
    if (l==r){
        get<0>(v[l])=0;
        Merge(node,l,r);
        return;
    }
    int mid = (l+r)>>1;
    update(node*2,l,mid,pos);
    update(node*2+1,mid+1,r,pos);
    Merge(node,l,r); // IMPORTANT
}

void build(int node, int l, int r){
	if (l==r){
		Merge(node,l,r);
		return;
	}
	int mid = (l+r)>>1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	Merge(node,l,r);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // build(1,0,n-1);      read data before
  return 0;
}
