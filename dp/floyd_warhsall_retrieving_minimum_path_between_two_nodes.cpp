// this uses 1-indexing input/output and 0-indexing processing
// also be careful of the constraints (nodes, weights) when modifying this code

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int NAX = 300;
int adj[NAX][NAX], dp[NAX][NAX], lastmodif[NAX][NAX];

void getCam(int u, int v){                               // function that prints the path [u, v)
	if (lastmodif[u][v]==-1) cout<<u+1<<' ';
	else{
		getCam(u,lastmodif[u][v]);
		getCam(lastmodif[u][v],v);
	}
}

int main(){
	int n, m; cin>>n>>m;
	for (int i=0; i<n; i++){
		adj[i][i]=dp[i][i]=0;
		for (int j=0; j<n; j++){
			lastmodif[i][j]=-2;                     // never modified
			if (j==i) continue;
			dp[i][j]=adj[i][j]=INF;
		}
	}
	for (int i=0; i<m; i++){
		int u,v,w; cin>>u>>v>>w;        u--,v--;
		adj[u][v]=dp[u][v]=w;
		lastmodif[u][v]=-1;                       // modified for the 1st time when edges are being created
	}
	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (i==k || j==k) continue;
				int newwe = dp[i][k] + dp[k][j];
				if (newwe < dp[i][j]){
					dp[i][j]=newwe;
					lastmodif[i][j]=k;                  // new minimum path that passes through node (k)
				}
			}
		}
	}
	
	int q; cin>>q;
	while(q--){
		int u,v; cin>>u>>v;        u--,v--;
		if (dp[u][v]==INF) cout<<"No existe camino entre u y v";
		else{
			cout<<"el camino minimo entre "<<u+1<<" y "<<v+1<<" es: "<<dp[u][v]<<endl;
			cout<<"uno de los caminos minimos es: ";
			getCam(u,v); cout<<v+1<<' ';
		}
		cout<<endl<<endl;
	}
	
	return 0;
}
