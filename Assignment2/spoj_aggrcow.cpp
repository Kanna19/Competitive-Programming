#include <iostream>
#include <algorithm>

const int MAXN = 100000;
using namespace std;

int s[MAXN];
int n, c;

bool chk(int dist)
{
	int cnt = 1;
	int prev = s[0];
	
	for(int i = 1; i < n; i++)
	{
		if(s[i] -prev >= dist)
		{
			prev = s[i];
			cnt++;
		}
	}
	
	return (cnt >= c);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> c;
		
		for(int i = 0; i < n; i++)
			cin >> s[i];
		
		sort(s, s +n);
		
		int l = 1, r = (int)1e9;
		
		while(l < r)
		{
			int mid = l +r +1 >> 1;
			
			if(chk(mid))
				l = mid;
			
			else
				r = mid -1;
		}
		
		cout << l << '\n';
	}

	return 0;
}
