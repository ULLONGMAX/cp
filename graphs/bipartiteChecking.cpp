#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;

vvi graph(6);
vi Color(6, -1);

bool dfs(int u, int p){
	bool ans=true;
	for (int i=0; i<graph[u].size(); i++){
		int v=graph[u][i];
		if (v!=p){
			int adj=1-Color[u];
			if (Color[v]==-1){
				Color[v]=adj;
				ans=ans and dfs(v, u);
			}else{
				if (Color[v]==Color[u]){
					ans=false;
				}
			}
		}
	}
	return ans;
}

//-1 not visited
//0 black
//1 red

int main(){
	for (int i=0; i<7; i++){
		int from,to;
		cin>>from>>to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	int numberNodes=6;
	bool itsBipartite=true;
	for (int i=0; i<numberNodes; i++){
		if (Color[i]==-1){
			Color[i]=0;
			itsBipartite= itsBipartite and dfs(i, -1);
		}
	}
	cout<<itsBipartite<<endl;

	for (int i=0; i<6; i++) cout<<Color[i]<<" ";


	return 0;
}
