#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front

#define typePt double
#define EPS 1e-9
#define PI acos(-1)

struct pt{
	typePt x,y;
	pt() {x=y=0;}
	pt(typePt ax, typePt ay){x=ax; y=ay;}
	pt operator + (pt p) {return pt(x+p.x, y+p.y);}
	pt operator - (pt p) {return pt(x-p.x, y-p.y);}
	pt operator * (typePt k) {return pt(x*k, y*k);}
	pt operator / (typePt k) {return pt(x/k, y/k);}
	//bool operator == (pt p) {return x==p.x && y==p.y;} // WARNING: precision (can use EPS instead, comment this)
	//bool operator != (pt p) {return !(*this==p);} // WARNING: precision (can use EPS instead, comment this)
	bool operator == (pt p) {return abs(this->x - p.x)<EPS && abs(this->y - p.y)<EPS;} // in case of precision errors use this
	bool operator != (pt p) {return !(*this==p);} // in case of precision errors use this
	void read(){cin>>this->x>>this->y;}
	void show(){cout<<this->x<<' '<<this->y<<endl;}
};

typePt sq(pt p) {return p.x*p.x + p.y*p.y;}
typePt Abs(pt p) {return sqrt(sq(p));}
typePt cross(pt a, pt b) {return a.x*b.y - a.y*b.x;} // axb
typePt dot(pt a, pt b) {return a.x*b.x + a.y*b.y;}
typePt angle(pt a, pt o, pt b) { // angle [0,pi] between vectors oa,ob
	pt oa = a-o, ob = b-o;
	return acos(dot(oa,ob)/(sqrt(sq(oa)*sq(ob))));
}
int signOf(typePt k){
	if (k==0) return 0;
	if (k>-EPS) return 1;
	if (k<EPS) return -1;
}
pt unit(pt p) {return {p.x/Abs(p), p.y/Abs(p)};}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
