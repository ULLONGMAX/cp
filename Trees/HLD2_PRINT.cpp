V<AR<int,2> > g[NAX];
int sz[NAX];
int par[NAX];
int lev[NAX];

void dfs(int u, int pa, int le){
  lev[u]=le;
  par[u]=pa;
  sz[u]=1;
  for (int i=0; i<g[u].size(); i++){
    int v=g[u][i][0];
    if (v==pa) continue;
    dfs(v,u,le+1);
    sz[u]+=sz[v];
    if (sz[v]>sz[g[u][0][0]]){
      swap(g[u][0],g[u][i]);
    }
  }
}

int T;
int idx_in_list[NAX];
int head[NAX];
void decompose(int u, int pa, int hcurr){
  head[u]=hcurr;
  idx_in_list[u]=T;
  T++;
  for (int i=0; i<g[u].size(); i++){
    int v=g[u][i][0];
    if (v==pa) continue;
    if (i) decompose(v,u,v);
    else decompose(v,u,hcurr);
    upd(1, 0,n-1, idx_in_list[v],g[u][i][1]);
  }
}

int qhld(int a, int b){ // no need for LCA, I can also calculate LCA with this function
  int res=0;
  while(head[a]!=head[b]){
    if (lev[head[a]]>lev[head[b]]){
      res=max(res,que(1,0,n-1, idx_in_list[head[a]],idx_in_list[a]));
      a=par[head[a]];
    }else{
      res=max(res,que(1,0,n-1, idx_in_list[head[b]],idx_in_list[b]));
      b=par[head[b]];
    }
  }
  if (a!=b){
    if (lev[a]<lev[b]) swap(a,b);
    res=max(res,que(1,0,n-1, idx_in_list[b]+1,idx_in_list[a]));
  }
  return res;
}
