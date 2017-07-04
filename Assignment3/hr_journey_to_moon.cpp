#include <iostream>
#include <list>

#define ll long long
#define pb push_back

const int MAXN = 100010;

using namespace std;

bool vis[MAXN];
list <int> adj[MAXN];

ll n_c_2(ll n)
{
	return ((n *(n -1)) >> 1);
}

int dfs(int u)
{
	int count = 1;
	vis[u] = 1;
	
	for(const auto &v : adj[u])
		if(!vis[v])
			count += dfs(v);
	
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, p;
	cin >> n >> p;
	
	while(p--)
	{
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	ll ans = n_c_2(n);
	
	for(int i = 0; i < n; i++)
		if(!vis[i])
			ans -= n_c_2(dfs(i));
	
	cout << ans << '\n';
	return 0;
}
