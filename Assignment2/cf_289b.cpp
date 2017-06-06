#include <iostream>
#include <algorithm>

const int MAXN = 10000;
using namespace std;

int a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, d;
	cin >> n >> m >> d;
	
	for(int i = 0; i < n *m; i++)
		cin >> a[i];
	
	nth_element(a, a +(n *m)/2, a +(n *m));
	
	int median = a[(n *m)/2];
	int ans = 0;
	
	for(int i = 0; i < n *m; i++)
	{
		if(a[i] % d != median % d)
		{
			cout << "-1\n";
			return 0;
		}
		
		ans += abs((a[i] -median)/d);
	}
	
	cout << ans << endl;
	
	return 0;
}
