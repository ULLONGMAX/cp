#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front
 
const int n=100;
vector<int> fen(n+1); // BIT is 1 INDEXED.
 
void upd(int pos){
	while(pos<=n){
		fen[pos]++;
		pos+=pos&(-pos); // x&(-x) = LSB of x.
	}
}
 
int que(int pos){ // res = sum(array[1,pos])
	int res=0;
	while(pos){
		res+=fen[pos];
		pos^=pos&(-pos);
	}
	return res;
}

int main(){
  return 0; 
}
