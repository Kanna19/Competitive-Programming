#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	long long n, m;
	cin >> n >> m;
	
	if(m >= n)
	{
		cout << n << '\n';
		return 0;
	}	
	
	long long x = (sqrt(8 *(n -m)) -1)/2;
	
	while((x*(x +1))/2 < n -m)
		x++;
	
	cout << m +x << '\n';

	return 0;
}
