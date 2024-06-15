#include <bits/stdc++.h>
using namespace std;

const int NAX = 1001;
vector<int> parent(NAX,-1);

int Find(int u){
  if (parent[u]==-1) return u;
  return parent[u] = Find(parent[u]); // path compression
}

void Union(int u, int v){
  int pu = Find(u), pv = Find(v);
  if (pu!=pv){
    parent[pu]=pv; // this is NOT union by rank
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  Union(1,2);
  
  return 0;
}
