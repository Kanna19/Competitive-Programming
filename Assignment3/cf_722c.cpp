#include <iostream>

#define ll long long

const int MAXN = 100010;
using namespace std;

int p[MAXN];
ll sum[MAXN];
int rnk[MAXN];
ll order[MAXN];
bool isPresent[MAXN];

int find_set(int x)
{
	if(p[x] != x)
		p[x] = find_set(p[x]);
	
	return p[x];
}

void merge_set(int x, int y)
{
	int p_x = find_set(x);
	int p_y = find_set(y);
	
	if(p_x != p_y)
	{
		if(rnk[p_x] > rnk[p_y])
		{
			p[p_y] = p_x;
			sum[p_x] += sum[p_y];
		}
		
		else
		{
			p[p_x] = p_y;
			sum[p_y] += sum[p_x];
		}
		
		if(rnk[p_x] == rnk[p_y])
			rnk[p_y]++;	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		p[i] = i;
	}
	
	for(int i = 0; i < n; i++)
		cin >> order[n -i];
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int next = order[i];
		order[i] = ans;
		
		isPresent[next] = 1;
		
		if(isPresent[next -1])
			merge_set(next -1, next);
		
		if(isPresent[next +1])
			merge_set(next, next +1);
		
		ans = max(ans, sum[find_set(next)]);
	}
	
	for(int i = n; i > 0; i--)
		cout << order[i] << '\n';
		
	return 0;
}
