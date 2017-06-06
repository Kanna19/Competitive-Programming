#include <iostream>

#define ll long long

const int MAXN = 501;
using namespace std;

int m, k;
int p[MAXN];
bool mark[MAXN];

void reset()
{
	for(int i = 1; i <= m; i++)
		mark[i] = 0;
}

void adjust_partitions(int rem)
{
	for(int i = 1; i <= m && rem > 0; i++)
	{
		if(!mark[i])
		{
			mark[i] = 1;
			rem--;
		}
	}
}

int min_scribers(ll max_pages)
{
	ll curr = p[m];
	int cnt = 1;
	
	for(int i = m -1; i > 0; i--)
	{
		curr += p[i];
		
		if(curr > max_pages)
		{
			curr = p[i];
			mark[i] = 1;
			
			if(++cnt > k)
				return -1; 
		}
	}
	
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> m >> k;
		
		int start = 0;
		for(int i = 1; i <= m; i++)
		{
			cin >> p[i];
			start = max(start, p[i]);
		}
		
		ll l = start, r = (ll)1e10;
		
		int req;
		while(l < r)
		{
			ll mid = l +r >> 1;
			reset();
			
			req = min_scribers(mid);
			
			if(req == -1)
				l = mid +1;
				
			else
				r = mid;		
		}
		
		//cout << l << endl;
		
		reset();
		req = min_scribers(l);
		
		adjust_partitions(k -req);
		
		for(int i = 1; i <= m; i++)
		{
			cout << p[i] << ' ';
			
			if(mark[i])
				cout << "/ ";
		}
		
		cout << endl;
	}
	
	return 0;
}
