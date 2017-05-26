#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return (b ? gcd(b, a % b) : a);
}

int main()
{
	int a, b, c, d;
	scanf(" %d%d%d%d", &a, &b, &c, &d);
	
	int p, q;
	
	if(b *c >= a *d)
		p = b *c -d *a, q = b *c;
	
	else
		p = a *d -b *c, q = a *d;
	
	int common_divisor = gcd(p, q);
	p /= common_divisor;
	q /= common_divisor;
	
	printf("%d/%d\n", p, q);
	return 0;
}
