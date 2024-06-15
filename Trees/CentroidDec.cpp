#include <bits/stdc++.h>
using namespace std;
#define pb push_back

//    // means reseted (for each test case)
const int NAX = 200002;
const int MAX = 1e9;
vector<int> g[NAX]; //
vector<int> pcen(NAX); //
vector<int> sb(NAX); //
vector<vector<int> > lca(NAX); //
vector<int> le(NAX); //
int LOG; //// should be > log(|V|)
vector<int> vis(NAX); //
// vis is only used when performing the Decomposition (pcen).
// le[u] = level[u] = dist(root,u) (original tree).

vector<int> svv(NAX); //
// svv[u] = dp[u] (centroid subtree of u).

void dfs(int u, int pa, int leve){
	sb[u]=1;
	le[u]=leve;
	if (pa){
		lca[u][0]=pa;
		int node=pa;
		for (int i=1; i<LOG; i++){
			lca[u][i]=lca[node][i-1];
			node=lca[u][i];
		}
	}
	for (int i=0; i<g[u].size(); i++){
		int v = g[u][i];
		if (v!=pa){
			dfs(v,u,leve+1);
			sb[u]+=sb[v];
		}
	}
}

void dec(int u, int pacen, int n){
	int cen=-1;
	while(cen==-1){
		bool found=true;
		for (int i=0; i<g[u].size(); i++){
			int v=g[u][i];
			if (!vis[v] && sb[v]>n/2){ //
				found=false;
				int com=n-sb[v];
				sb[u]-=sb[v];
				sb[v]+=com;
				u=v;
				break;
			}
		}
		if (found) cen=u;
	}
	
	vis[cen]=true; // for not going through this node again
	pcen[cen]=pacen; // only parent DS is needed for the current purpose (see example).
	for (int i=0; i<g[cen].size(); i++){
		int v=g[cen][i];
		if (!vis[v]) dec(v,cen,sb[v]);
	}
}

////// lca stuff:

void climb(int dis, int &v){
	for (int i=0; i<LOG; i++){
		if ((1<<i)&dis) v=lca[v][i];
	}
}

int dis(int u, int v){
	if (le[v]<le[u]) swap(v,u);
	// v->u
	int res=le[v]-le[u];
	climb(res,v);
	if (v==u) return res;
	for (int i=LOG-1; i>=0; i--){
		if (lca[v][i]==lca[u][i]) continue;
		v=lca[v][i];
		u=lca[u][i];
		res+=2*(1<<i);
	}
	res+=2;
	return res;
}

/////// centroid DP stuff:

void upd(int u){
	int curr=u;
	svv[u]=0;
	u=pcen[u];
	while(u){
		svv[u]=min(svv[u],dis(curr,u)); // subtree DP update (in centroid tree).
		u=pcen[u]; // climbing up until root (in centroid tree) is reached.
	}
}

int que(int u){ // BRUTE FORCE IDEA (view all nodes (except u) ).
	int curr=u;
	int ans=svv[u];
	u=pcen[u];
	while(u){
		ans=min(ans,svv[u]+dis(u,curr)); // since dis(a,b) = dis(a,LCAcentroid(a,b)) + dis(LCAcentroid(a,b),b)
		u=pcen[u]; // climbing up until root (in centroid tree) is reached.
	}
	return ans;
}

// example:

void solve(){
	int n,c0; cin>>n>>c0;
	vector<int> c(n-1);
	for (int &x:c) cin>>x;
	
	// reset:
	for (int i=1; i<=n; i++) g[i].clear(),vis[i]=false,pcen[i]=0,svv[i]=MAX;
	LOG = log2(n)+2;
	for (int i=0; i<=n; i++) lca[i].assign(LOG,0);
	
	for (int i=0; i<n-1; i++){
		int a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,0,0);
	dec(1,0,n);
	
	upd(c0);
	int answer=MAX;
	for (int u:c){
		int qq=que(u);
		answer=min(answer,qq);
		cout<<answer<<' ';
		upd(u);
	}
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
