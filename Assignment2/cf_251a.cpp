#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll nc2(int n)
{
	if(n < 2)
		return 0;
		 
	return (1ll *n *(n -1)) >> 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, d;
	cin >> n >> d;
	
	vector <int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	ll ans = 0;
	for(auto i = v.begin(); i != v.end(); i++)
	{
		auto it = upper_bound(i, v.end(), *i +d);
		int len = (it -i -1);
		ans += nc2(len);
	}
	
	cout << ans << endl;
	return 0;
}
