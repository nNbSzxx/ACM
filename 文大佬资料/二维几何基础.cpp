#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

const double eps=1e-6;

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x=_x;
		y=_y;
	}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b)
{
	return Vector(a.x+b.x,a.y+b.y);
}
Vector operator - (Vector a,Vector b)
{
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (Vector a,double p)
{
	return Vector(a.x*p,a.y*p);
}
Vector operator / (Vector a,double p)
{
	return Vector(a.x/p,a.y/p);
}

int dcmp(double p)
{
	if(abs(p)<eps)
		return 0;
	else
		return p<0?-1:1;
}
bool operator < (Point a,Point b)
{
	return dcmp(a.x-b.x)<0||dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<=0;
}
bool operator == (Vector a,Vector b)
{
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
	return sqrt(dot(a,a));
}
double angle(Vector a)
{
	return atan2(a.y,a.x);
}
double angle(Vector a,Vector b)
{
	return acos(dot(a,b)/length(a)/length(b));
}
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double area(Point a,Point b,Point c)
{
	return cross(b-a,c-a)/2;
}
Vector rotate(Vector a,double rad)
{
	return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector normal(Vector a)
{
	return Vector(-a.y/length(a),a.x/length(a));
}
struct Line
{
	Point p;
	Vector v;
	Line(Point _p,Vector _v)
	{
		p=_p;
		v=_v;
	}
	Point point(double t)
	{
		return p+v*t;
	}
	Line move(double d)
	{
		return Line(p+normal(v)*d,v);
	}
};
struct Circle
{
	Point c;
	double r;
	Circle(Point _c,double _r)
	{
		c=_c;
		r=_r;
	}
	Point point(double a)
	{
		return Point(c.x+cos(a)*r,c.y+sin(a)*r);
	}
};
Point get_line_intersection(Point p1,Point v1,Point p2,Point v2)
{
	Point v=p1-p2;
	double t=cross(v2,v)/cross(v1,v2);
	return p1+v1*t;
}
Point get_line_intersection(Line l1,Line l2)
{
	return get_line_intersection(l1.p,l1.v,l2.p,l2.v);
}
double distant_to_line(Point p,Point a,Point b)
{
	Vector v1=b-a,v2=p-a;
	return abs(cross(v1,v2)/length(v1));
}
double distant_to_segment(Point p,Point a,Point b)
{
	if(a==b)
		return length(p-a);
	Vector v1=b-a,v2=p-a,v3=p-b;
	if(dot(v1,v2)<0)
		return length(v2);
	else if(dot(v1,v3)>0)
		return length(v3);
	else
		return abs(cross(v1,v2)/length(v1));
}
Point get_line_projection(Point p,Point a,Point b)
{
	Vector v=b-a;
	return a+v*(dot(v,p-a)/dot(v,v));
}
bool segment_proper_intersection(Point a1,Point a2,Point b1,Point b2)
{
	return dcmp(cross(b1-a1,a2-a1))*dcmp(cross(b2-a1,a2-a1))<0&&dcmp(cross(a1-b1,b2-b1))*dcmp(cross(a2-b1,b2-b1))<0;
}
bool on_segment(Point p,Point a,Point b)
{
	return dcmp(cross(a-p,b-p))==0&&dcmp(dot(a-p,b-p))<0;
}
double polygon_area(Point *p,int num)
{
	double ans=0;
	for(int i=2;i<num;i++)
		ans+=area(p[1],p[i],p[i+1]);
	return ans;
}
int get_line_circle_intersection(Line l,Circle o,vector<Point> &ans)
{
	double a=l.v.x,b=l.p.x-o.c.x,c=l.v.y,d=l.p.y-o.c.y;//(at+b)^2+(ct+d)^2=r^2
	double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-o.r*o.r;//et^2+ft+g=0
	double de=f*f-4*e*g;
	if(dcmp(de)<0)
	{
		return 0;
	}
	else if(dcmp(de)==0)
	{
		ans.push_back(l.point(-f/(2*e)));
		return 1;
	}
	else
	{
		ans.push_back(l.point((-f-sqrt(de))/(2*e)));
		ans.push_back(l.point((-f+sqrt(de))/(2*e)));
		return 2;
	}
}
int get_circle_circle_intersection(Circle c1,Circle c2,vector<Point> &ans)
{
	double d=length(c1.c-c2.c);
	if(dcmp(d)==0)
	{
		if(dcmp(c1.r-c2.r)==0)
			return -1;
		else
			return 0;
	}
	if(dcmp(c1.r+c2.r-d)<0||dcmp(fabs(c1.r-c2.r)-d)>0)
		return 0;
	double a=angle(c2.c-c1.c);
	double da=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
	Point p1=c1.point(a+da),p2=c1.point(a-da);
	ans.push_back(p1);
	if(p1==p2)
		return 1;
	ans.push_back(p2);
	return 2;
}
int get_tangents(Point p,Circle o,vector<Vector> &ans)
{
	Vector v=o.c-p;
	double d=length(v);
	if(dcmp(d-o.r)<0)
	{
		return 0;
	}
	else if(dcmp(d-o.r)==0)
	{
		ans.push_back(rotate(v,acos(-1)/2));
		return 1;
	}
	else
	{
		double da=asin(o.r/d);
		ans.push_back(rotate(v,-da));
		ans.push_back(rotate(v,da));
		return 2;
	}
}
Circle circumscribed_circle(Point p1,Point p2,Point p3)
{
	Vector v1=p2-p1,v2=p3-p1;
	Point c=get_line_intersection(Point((p1.x+p2.x)/2,(p1.y+p2.y)/2),normal(v1),Point((p1.x+p3.x)/2,(p1.y+p3.y)/2),normal(v2));
	double r=length(p1-c);
	return Circle(c,r);
}
Circle inscribed_circle(Point p1,Point p2,Point p3)
{
	double a=length(p3-p2);
	double b=length(p3-p1);
	double c=length(p2-p1);
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);
	return Circle(p,distant_to_line(p,p1,p2));
}
int tangent_line_through_point(Point p,Circle o,vector<double> &ans)
{
	vector<Vector> f;
	get_tangents(p,o,f);
	for(int i=0;i<f.size();i++)
	{
		double da=angle(f[i])*180/acos(-1);
		while(da<0)
			da+=180;
		while(da>=180)
			da-=180;
		ans.push_back(da);
	}
	sort(ans.begin(),ans.end());
}
vector<Point> circle_through_point_tangent_to_line_given_radius(Point p,Line l,double d)
{
	vector<Point> ans;
	get_line_circle_intersection(l.move(d),Circle(p,d),ans);
	get_line_circle_intersection(l.move(-d),Circle(p,d),ans);
	sort(ans.begin(),ans.end());
	return ans;
}
vector<Point> circle_tangent_to_lines_given_radius(Line l1,Line l2,double d)
{
	vector<Point> ans;
	ans.push_back(get_line_intersection(l1.move(d),l2.move(d)));
	ans.push_back(get_line_intersection(l1.move(-d),l2.move(d)));
	ans.push_back(get_line_intersection(l1.move(d),l2.move(-d)));
	ans.push_back(get_line_intersection(l1.move(-d),l2.move(-d)));
	sort(ans.begin(),ans.end());
	return ans;
}
vector<Point> circle_tangent_to_two_disjoint_circles_with_radius(Circle c1,Circle c2,double d)
{
	vector<Point> ans;
	get_circle_circle_intersection(Circle(c1.c,c1.r+d),Circle(c2.c,c2.r+d),ans);
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
// 	freopen("data.out","w",stdout);
#endif
	
	return 0;
}