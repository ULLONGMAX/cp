#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define pob pop_back
#define psf push_front
#define pof pop_front

// printing & reading:
#define NL cout<<'\n'
template <typename T> void IMP(T x) {cout<<x;}
template <typename T> void IMPL(T x) {IMP(x); NL;}
template <typename T> void LEE(T &x) {cin>>x;}


// change to LONG DOUBLE if needed:
typedef double db;
// the datatype that we're using for the STRUCT POINT (it's RECOMMENDED to be the SAME datatype as 'db'):
#define typePt db
// the value of EPS depends on the PROBLEM:
const db EPS = 1e-9;
// C++ works with RADIANS:
#define PI acos(-1)

/* THINGS TO TAKE INTO ACCOUNT:

1) abs() works better for INTEGER TYPE NUMBERS ; fabs() works better for FLOATING TYPE NUMBERS.
	If this doesn't work visit cpp reference or other references.
	
2) Depending on the problem, CHANGE typePt (for example, to defer floating-point operations change typePt to long long).
	Floating-point precision can also cause WA (for example when using sqrt(), or division) so better use addition, multiplication, subtraction.

3) Geometry problems usually have tricky(CORNER) cases. Also be careful with this when implementing the solution.

*/

struct pt{
	typePt x,y;
	pt() {x=y=0;}
	pt(typePt ax, typePt ay){x=ax; y=ay;}
	bool operator < (pt p) const{ // const tells the compiler that no member variable will change inside this member function
		if (fabs(x-p.x) > EPS) return x<p.x; // first sort by x
		return y<p.y; // if tie in x, sort by y
	}
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
	if (k==(typePt)0) return 0;
	if (k>-EPS) return 1;
	if (k<EPS) return -1;
}
pt unit(pt p) {return {p.x/Abs(p), p.y/Abs(p)};}

// double (or long double) is needed for angles (for example I want to rotate a vector by PI radians):
db DEG_to_RAD(db ang) {return ang*PI/180.0;}
db RAD_to_DEG(db ang) {return ang*180.0/PI;}
pt rotate(const pt &p, db theta){ // theta is measured in DEGREES and can be ANY real number
	db rad=DEG_to_RAD(theta);
	return pt((db)p.x*cos(rad) - (db)p.y*sin(rad), (db)p.x*sin(rad) + (db)p.y*cos(rad));
}

////////////////// LINES //////////////////

struct Line{
	db a,b,c; // ax + by + c = 0
	Line(db _a, db _b, db _c){a=_a, b=_b, c=_c;}
};

Line pointsToLine(pt a, pt b){ // given 2 points build the line that passes through them
	if (abs(a.x-b.x)<EPS) return Line(1,0,-a.x); // any vertical line can be represented with b=0 => we represent ANY vertical line with b=0
	db A=(a.y-b.y)/(b.x-a.x); // = -m = -slope = -GRADIENT
	return Line(A,1,-a.y-A*a.x); // any non-vertical line can be represented with b!=0 => we represent all NON-vertical lines with b!=0
}

bool Parallel(Line L1, Line L2){
	return abs(L1.a-L2.a)<EPS && abs(L1.b-L2.b)<EPS;
}

bool Same(Line L1, Line L2){
	return Parallel(L1,L2) && abs(L1.c-L2.c)<EPS;
}

void checkLines(Line L1, Line L2){ // checks the intersection of lines (3 cases: they are the same line, they are parallel, or intersect at one point)
	if (Parallel(L1,L2)){
		if (Same(L1,L2)) cout<<"LINE\n";
		else cout<<"NONE\n";
	}else{
		if (L2.b) swap(L1,L2); // => L1 has always b!=0 => b=1
		db x=(-L2.c+L1.c*L2.b)/(L2.a-L1.a*L2.b);
		db y=-L1.c-L1.a*x;
		cout<<"POINT "<<fixed<<setprecision(11)<<x<<' '<<y<<'\n';
	}
}

db distToLine(pt p, pt a, pt b){ // minimum distance from point p to the line formed by points a and b
	pt ap=p-a;
	pt ab=b-a;
	db u=dot(ap,ab)/sq(ab);
	pt c = a + ab*u; // c is the point which is on the line, and is closest to p
	return Abs(p-c);
}

db distToLineSegment(pt p, pt a, pt b){ // minimum distance from point p to the line SEGMENT formed by points a and b
	// very SIMILAR to distToLine function:
	pt ap=p-a;
	pt ab=b-a;
	db u=dot(ap,ab)/sq(ab);
	pt c; // c is the point which is on the line SEGMENT, and is closest to p
	if (u<(db)0){ // p is closest to a
		c=a;
		return Abs(c-p);
	}
	if (u>(db)1){ // p is closest to b
		c=b;
		return Abs(c-p);
	}
	c = a + ab*u;
	return Abs(c-p);
}

///////////////////////////////////////////



////////////////// CIRCLES /////////////////

int insideCircle(const pt &p, const pt &c, db r){ // check if p is inside the circle, on the border of the circle, or outside the circle with center 'c' and radius 'r'
	db dx=p.x-c.x, dy=p.y-c.y;
	db distsq=dx*dx + dy*dy, rSq=r*r;
	return distsq<rSq? 1 : (distsq==rSq? 0 : -1); // inside|border|outside
}

bool circle2PtsRad(pt p1, pt p2, db r, pt &c){ // given 2 points p1 and p2, finds the possible circle(s) with radius r that intersect with both p1 and p2 (there can be 0, 1 or 2 of such circles)
	db dissq = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
	db radicand = r*r/dissq - 0.25;
	if (radicand < EPS) return false; // if radicand<0 => 0 possible circles
	// else there are 1 or 2 possible circles:
	db h=sqrt(radicand);
	// c is the center of one of the possible circle(s), to get the other reverse p1 and p2 when calling this function (that is, the following call should be circle2PtsRad(p2,p1,r,c) ), if there is JUST ONE possible circle, then both calls return the same center:
	c.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
	c.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
	return true;
}

////////////////////////////////////////////

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	pt A(1,2), B(1,2.0000000001);
	IMPL(A!=B);
	
	IMPL("------------------");
	
	pt C(1,3), D(2,2);
	set<pt> pts; // the overloaded operator < inside struct pt is used for sorting inside the set Data Structure.
	pts.insert(A);
	pts.insert(B); pts.insert(B);
	pts.insert(C);
	pts.insert(D);
	cout<<setprecision(11);
	for (pt p:pts) p.show();
	
	IMPL("------------------");
	
	pt ro=rotate(A, -90 -360*100);
	ro.show();
	
	IMPL("------------------");
	
	

	return 0;
}
