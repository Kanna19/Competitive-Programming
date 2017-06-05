#include <iostream>
#include <cmath>

#define ll long long

const double PI = 3.14159265358979323846;
const double INF = 1e15;
using namespace std;

int p_x, p_y;
double max_dist, min_dist;

inline double dist(double x, double y)
{
	return sqrt(pow(x -p_x, 2.0) +pow(y -p_y, 2.0));
}

void update_distances(double a, double b, double c, double d)
{
	double l1 = 0, r1 = 1, l2 = 0, r2 = 1;
	double p1_x, p1_y;
	
	int it = 200;
	while(it--)
	{
		double p11 = l1 +(r1 -l1)/3;
		double p12 = r1 -(r1 -l1)/3;
		double p21 = l2 +(r2 -l2)/3;
		double p22 = r2 -(r2 -l2)/3;
		
		p1_x = a +(c -a) *p11, p1_y = b +(d -b) *p11;
		double d11 = dist(p1_x, p1_y);
		
		p1_x = a +(c -a) *p12, p1_y = b +(d -b) *p12;
		double d12 = dist(p1_x, p1_y);
		
		p1_x = a +(c -a) *p21, p1_y = b +(d -b) *p21;
		double d21 = dist(p1_x, p1_y);
		
		p1_x = a +(c -a) *p22, p1_y = b +(d -b) *p22;
		double d22 = dist(p1_x, p1_y);
		
		if(d11 > d12)
			r1 = p11;
			
		else
			l1 = p12;
		
		if(d21 < d22)
			r2 = p22;
		
		else
			l2 = p21;
	}
	
	p1_x = a +(c -a) *l1, p1_y = b +(d -b) *l1;
	max_dist = dist(p1_x, p1_y);
	
	p1_x = a +(c -a) *l2, p1_y = b +(d -b) *l2;
	min_dist = dist(p1_x, p1_y);
}

int main()
{
	int n;
	scanf(" %d%d%d", &n, &p_x, &p_y);
	
	int start_x, start_y;
	scanf(" %d%d", &start_x, &start_y);

	double R = 0, r = INF;
	
	int a = start_x, b = start_y;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		scanf(" %d%d", &x, &y);
		
		update_distances(x, y, a, b);
		
		R = max(R, max_dist);
		r = min(r, min_dist);
		
		a = x, b = y;
	}
	
	update_distances(start_x, start_y, a, b);
	
	R = max(R, max_dist);
	r = min(r, min_dist);
	
	double ans = PI *(R *R -r *r);
	printf("%.10lf\n", ans); 
	
	return 0;
}

