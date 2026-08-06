vector<int> color,distinct;
vector<set<int>*> subtree;
 
void dfs(int i,int parent = -1){
	int largest = -1;
	vector<int> children;
	for(int node : graph[i]){
		if(node != parent){
			dfs(node,i);
			children.push_back(node);
			if(largest == -1 || subtree[largest]->size() < subtree[node]->size()){
				largest = node;
			}
		}
	}
	if(largest == -1){
		subtree[i] = new set<int>; // new set for leaf node
	}
	else{
		subtree[i] = subtree[largest]; // largest sized child
	}
	
	for(int child : children){
		if(child == largest)continue;
		subtree[i]->insert(subtree[child]->begin(),subtree[child]->end());
	}
	subtree[i]->insert(color[i]);
	distinct[i] = subtree[i]->size();
}
