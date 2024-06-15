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
//typedef pair<int,int> ii;
typedef double db;
#define Bolivia_is_SIIUUUUUUUUUUUUU ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
 
// bits:
#define LSB(x) __builtin_ctz(x)
#define LSBLL(x) __builtin_ctzll(x)
#define MSB(x) 31-__builtin_clz(x)
#define MSBLL(x) 63-__builtin_clzll(x)
 
// printing & reading:
#define NL cout<<'\n'
template <typename T> void IMP(T x) {cout<<x;}
template <typename T> void IMPL(T x) {IMP(x); NL;}
template <typename T> void LEE(T &x) {cin>>x;}
 
// vectors & tuples:
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
#define V vector
#define AR array
 
// misc:
template <typename T> void ASMIN(T &yo, T el) {yo=min(yo,el);}
template <typename T> void ASMAX(T &yo, T el) {yo=max(yo,el);}





/// LCA
const int NAX = 1000, LOG=19;
V<int> depth(NAX);
V<V<int> > adj(NAX);
V<V<int> > ju(NAX,V<int>(LOG));

void dfs(int v, int pa, int le) {
	///// lca stuff:
	depth[v]=le;
	ju[v][0]=pa;
	int node=pa;
	for (int i=1; i<LOG; i++){
		ju[v][i]=ju[node][i-1];
		node=ju[v][i];
	}
  ///////
	
	for (int u:adj[v]){
		if (u==pa) continue;
		dfs(u,v,le+1);
	}
}
 
void climb(int &u, int di){
    for (int i=0; i<LOG; i++){
		if ((1<<i)&di) u=ju[u][i];
	}
}
 
AR<int,2> dis(int u, int v){ // (lca,dist u->v)
	if (depth[u]<depth[v]) swap(u,v);
	int d=depth[u]-depth[v];
	climb(u,d);
	if (u==v) return {u,d};
	for (int i=LOG-1; i>=0; i--){
		if (ju[u][i]!=ju[v][i]){
			u=ju[u][i];
			v=ju[v][i];
			d+=(int)(1<<i)*2;
		}
	}
	d+=2;
	return {ju[u][0],d};
}
 
///

int main(){
  // 1) read tree in adjacency list "adj"
  // 2) run dfs (root the tree at node 1 for example).
  // 3) for a query (LCA) between 2 nodes u & v call dis(u,v).
  
  return 0;
}
