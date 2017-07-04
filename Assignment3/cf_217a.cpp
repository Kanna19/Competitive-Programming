#include <iostream>
#include <vector>

#define F first
#define S second
#define pb push_back

const int MAXN = 110;
using namespace std;

bool vis[MAXN];
vector <int> adj[MAXN];
pair <int, int> nodes[MAXN];

void dfs(int u)
{
	vis[u] = 1;
	
	for(const auto &v : adj[u])
		if(!vis[v])
			dfs(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		nodes[i] = {x, y};
	}
	
	for(int i = 1; i < n; i++)
	{
		int x1 = nodes[i].F, y1 = nodes[i].S;
		
		for(int j = i +1; j <= n; j++)
			if(x1 == nodes[j].F || y1 == nodes[j].S)
				adj[i].pb(j), adj[j].pb(i);
	}
	
	int components = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			components++;
			dfs(i);
		}
	}
	
	cout << components -1 << '\n';
	return 0;
}
