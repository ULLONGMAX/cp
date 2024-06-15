#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  a=0,b=3;
  
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> gen(a,b); // generates ints uniformly in the range [a,b]
  // example generation:
  cout<<gen(rng)<<'\n';
  
  return 0;
}
