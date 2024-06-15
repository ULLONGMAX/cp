#include <bits/stdc++.h>
using namespace std;
 
struct Node{
	int val;
	map<int,Node*> children; // [number] -> actual NODE it (number) belongs to
	Node *parent;
};
 
Node *jefaso=new Node(); // root node (LAMBDA)!

Node *curr; // used for INSERTING or SEARCHING
 
// these functions are just for REMEMBERING how to do both operations, DO NOT copy paste!
void Ins(vector<int> abc){
    for (int cero=0; cero<26; cero++){
        if (abc[cero]!=0) continue;
        vector<int> aa=abc;
        for (int i=0; i<26; i++){
            if (i==cero) continue;
            if (aa[i]==1) continue;
            aa[i]=3;
        }
	/// bla bla till here
	    
	// IMPORTANT:
        curr=jefaso; // we set curr to root node and then INSERT this prefix
        for (int i=0; i<26; i++){
            auto fi=curr->ma.find(ii(i,aa[i]));
            if (fi!=curr->ma.end()){
                curr=fi->second;
            }else{
                curr->ma[ii(i,aa[i])]=new Node();
                curr=curr->ma[ii(i,aa[i])];
            }
        }
        curr->val++; // we achieved the last node
    }
}
 
int sea(vector<int> abc){
	curr=jefaso; // we set curr to root node and then SEARCH this prefix
	for (int i=0; i<26; i++){
		auto fi=curr->ma.find(ii(i,abc[i]));
		if (fi!=curr->ma.end()){
			curr=fi->second;
		}else{
			return 0;
		}
	}
	return curr->val;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}
